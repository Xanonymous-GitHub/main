/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int GCD(int a,int b){
    //Euclidean algorithm (a type of recursion)
    if(a==0)return b;
    if(b==0)return a;
    return GCD(b,(a-b*(a/b)));
}
int main(int argc,char* argv[]){
    int c1=1,c2=1,gcd=0;
    printf("Enter a fraction: ");
    scanf("%d/%d",&c1,&c2);
    gcd=GCD((c2>c1)?c2:c1,(c2<c1)?c2:c1);
    printf("In lowest terms: ");
    if(c2==gcd){
        printf("%d\n",c1/gcd);
    }else{
        printf("%d/%d\n",c1/gcd,c2/gcd);
    }
    return 0;
}