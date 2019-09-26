/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.                                             */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include<stdio.h>
int main(int argc,char* argv[]){
    printf("Enter a 24-hour time:　");
    int h,m,d=0;
    scanf("%d:%d",&h,&m);
    const int dt[]={
        8*60+0,9*60+43,11*60+19,12*60+47,14*60+0,15*60+45,19*60+0,21*60+45
    };
    const char at[]={
        "10:16 a.m.",
        "11:52 a.m.",
        "1:31 p.m.",
        "3:00 p.m.",
        "4:08 p.m.",
        "5:55 p.m.",
        "9:20 p.m.",
        "11:58 p.m.",
        "a.m.","p.m."
    };
    m+=60*h;
    struct timelist
    {
        
    };
    
    printf("Closet departure time is %d:%02d %c, arriving at %c\n");
    return 0;
}