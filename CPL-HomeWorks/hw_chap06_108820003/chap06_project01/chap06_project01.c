/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.10.06                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
#include<string.h>
#define max_bit_per_num 100//定義使用者最大輸入數字位數(包含小數點)
#define max_input_amount 100//定義使用者最大輸入資料筆數
typedef struct max_data_with_its_index{
    double data;//存放最大數字
    int index;//紀錄該數字在data中的位置
}max;
double myPow(int base,int p){
    //由於gcc編譯器編譯pow()函式時須加入-lm參數太過麻煩，因此自製次方函數。
    double result=1;//初始值
    if(p>=0){
        //如果次方數為正或0，則用乘法
        for (int i = 0; i < p; i++)result*=base;
    }else{
        //如果次方數為負數，則用除法
        for (int i = 0; i > p; i--)result/=base;
    }
    return result;
}
int main(int argc,char* argv[]){
    /*
        解題心得：本題之困難點在於如何完全正確的輸出用戶資料，根據題意，
        若用戶輸入100.23，則輸出必須亦為100.23而非100.230000000...，
        也就是說，必須使用某種方法去掉多餘的字。
        這邊所使用的解法大略為以下：
        1.取得使用者之輸入資料(stdin)(可能包含小數點以及換行符號)並儲存在字元陣列data
        2.將原資料(char type)轉換為double，判斷該筆資料之大小，若為最大則紀錄至max陣列。
        3.以字串方式將用戶輸入資料原封不動輸出(%s)。
    */
    char data[max_input_amount][max_bit_per_num];//建立用戶資料字串陣列
    max M={-1.7E+308,0};//用來存放最大數字以及最大數字在data的位置
    memset(data,'\0',sizeof(data));//開始前先清空data
    for (int i=0;i<max_input_amount;i++){//此迴圈可讓使用者在筆數達到上限值之前不斷的輸入數字
        int num_of_digits=0,have_point=0,point_pos=0,pos=0,negative=0;
        /*
            num_of_digits:紀錄該資料總共有幾位數字，包含小數點和換行符號。
            have_point:旗標變數，紀錄該資料是否存在小數點。
            point_pos:紀錄該資料之小數點位置，若無小數點，則其值等於num_of_digits。
            pos:計算權重時使用，用來紀錄目前計算到哪一位數。
            negative:旗標變數，紀錄該資料是否小於0。(但是後來發現負數也是結束條件阿...OwO)
        */
        double count=0;//將資料從char轉換到double時的記憶變數。
        printf("Enter a number : ");//顯示輸入訊息
        fgets(data[i], sizeof(data[i]), stdin);//讀取標準輸入之整行內容，以換行符號作為結束

        /*<拆除此註解與下方註解可啟用負數功能>
        if(data[i][0]=='-'){
            //判斷是否是負數。
            negative=!negative;
            int tmp_negative_moving_pos=0;
            do{
                data[i][tmp_negative_moving_pos++]=data[i][tmp_negative_moving_pos];
            }while(data[i][tmp_negative_moving_pos]);
        }*/

        while (data[i][num_of_digits]&&data[i][num_of_digits]!='\n'){
            /*
                開始計算該資料有幾位數，以及小數點位置
                在換行符號之前的所有字元都算在內，num_of_digits將不斷增加，
                其中，如果找到了小數點，則have_point變為true，
                並將point_pos停止後移，保留住小數點位置。
            */
            if(data[i][num_of_digits++]=='.'){//如果該位置是小數點
                have_point=!have_point;//記錄下來
            }else if(!have_point)point_pos++;//否則小數點計位變數繼續後移
        }
        /*
            開始轉換資料型別，這邊分為有小數點和沒小數點兩種，
            若有小數點，則先計算小數點前的部份，再算小數點後，
            計算完畢就將結果儲存至count。
        */
        if(have_point){//有小數點
            /*
                len可紀錄該資料之小數點後有幾位有效數字，
                而point_pos是紀錄小數點在data的索引值，兩者十分相似卻缺一不可。
                多減去1是為了避掉小數點本身，若不如此，會多算到"小數點"那一位。
            */
            int len=num_of_digits-point_pos-1;
            /*
                用point_pos計算步數，將字元減去0的ASCIIcode就可得到該數字，
                再將該數字乘以以10為底的權重次方數。
                例如123.4，1=1*10的2次方+2*10的1次方....
                次方採用自製函式運算。
                由於point_pos紀錄之位置停留在小數點本身，因此會多算一位數，須將
                最後結果再除以10後才可丟到count儲存。
            */
            while (point_pos)
            count+=(data[i][pos++]-'0')*myPow(10,point_pos--)/10;
            pos++;//跳過小數點那位
            int tmp=-1;//從10的-1次方開始
            while(len--)//用len計算步數
            count+=(data[i][pos++]-'0')*myPow(10,tmp--);//同上但不必避開小數點因為已經經過。
        }else{//沒小數點
            while (num_of_digits)//用num_of_digits計算步數
            count+=(data[i][pos++]-'0')*myPow(10,num_of_digits--)/10;
            //這邊也要多除以10是因為以num_of_digits計算步數的話會多算到換行符號。
        }
        /*
            不可用第一個字元等於0作為結束輸入的條件，因為用戶可能輸入0.1之類的值。
            必須拿到double型別的資料後才可判斷其是否為0。
        */
        if(count<=0.0f)break;//結束輸入的條件
        //if(!(count))break; //若要開啟負數功能須將上一行替換為本行

        /*<拆除此註解與上方註解可啟用負數功能>
        if(negative){
            //若是負數，則結果變號。
            count*=-1.0f;
            int tmp_negative_data_pos;
            while(data[i][tmp_negative_data_pos])
            tmp_negative_data_pos++;
            while(tmp_negative_data_pos)
            data[i][tmp_negative_data_pos--]=data[i][tmp_negative_data_pos];
            data[i][0]='-';
        }*/

        /*
            max{max_of_count,_index_in_data}
            如果count高於最高紀錄，則刷新紀錄，並儲存其索引值(在data中的位置)
        */
        if(count>M.data){
            M.data=count;//刷新
            M.index=i;//紀錄索引值
        }
    }
    //根據max中紀錄的索引值來輸出資料，使用%s就可以原封不動的把使用者輸入給吐出來了。
    printf("\nThe largest number entered was %s\n",data[M.index]);
    return 0;
}