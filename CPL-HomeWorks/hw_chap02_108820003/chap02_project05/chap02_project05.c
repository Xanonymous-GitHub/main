/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.17                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#include <math.h>
//init a new function "f(x)"
int f(int x,int i){
  //user <math.h>'s pow([var],[amount]) to get the answer.
  return 3*pow(x,i--)+2*pow(x,i--)-5*pow(x,i--)-pow(x,i--)+7*pow(x,i--)-6*pow(x,i);
}
int main(int argc,char* argv[]) {
  //init a float type variable as 0.
  int x=0;
  //get the data that user inputed.
  scanf("%d",&x);
  //output the f(x) result. (call the f function)
  printf("%d\n",f(x,5));  
  return 0;
}