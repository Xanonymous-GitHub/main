/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.17                                              */
/* Purpose:                                                      */
/* Change History:                                               */
/*****************************************************************/
#include <stdio.h>
int main(int argc,char* argv[]) {
  //init a float type variable as 0. 
  float data=0;
  //show a message that tells user there is the input place.
  printf("Enter an amount: ");
  //get the data that user inputed.
  scanf("%f",&data);
  //output the message and the price with tax.
  printf("With tax added: %.2f\n",data*1.05);
  return 0;
}