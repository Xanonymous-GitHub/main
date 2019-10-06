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
#define max_bit_per_num 100
#define max_input_amount 100
double myPow(int base,int p){
    double result=1;
    if(p>=0){
        for (int i = 0; i < p; i++){
            result*=base;
        }
    }else{
        for (int i = 0; i > p; i--){
            result/=base;
        }
    }
    return result;
}
int main(int argc,char* argv[]){
    char data[max_input_amount][max_bit_per_num];
    double max[]={0,0};
    memset(data,'\0',sizeof(data));
    for (int i=0;;i++){
        int num_of_digits=0,have_point=0,point_pos=0,pos=0;
        double count=0;
        printf("Enter a number: ");
        fgets(data[i], sizeof(data[i]), stdin);
        while (data[i][num_of_digits]&&data[i][num_of_digits]!='\n'){
            if(data[i][num_of_digits++]=='.'){
                have_point=!have_point;
            }else if(!have_point)point_pos++;
        }
        if(have_point){
            int len=num_of_digits-point_pos-1;
            while (point_pos)
            count+=(data[i][pos++]-'0')*myPow(10,point_pos--)/10;
            pos++;
            int tmp=-1;
            while(len--)
            count+=(data[i][pos++]-'0')*myPow(10,tmp--);
        }else{
            while (num_of_digits)
            count+=(data[i][pos++]-'0')*myPow(10,num_of_digits--)/10;
        }
        if(!(count))break;
        if(count>max[0]){
            max[0]=count;
            max[1]=i;
        }
    }
    printf("\nThe largest number entered was %s\n",data[(int)max[1]]);
    return 0;
}