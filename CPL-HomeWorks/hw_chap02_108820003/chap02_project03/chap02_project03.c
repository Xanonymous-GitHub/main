/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.17                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
//define a variable that means "math.pi"
#define pi 3.14
int main(int argc,char* argv[]) {
  //init a variable that means radius.
  int radius=0;
  //show a message that tells user there is the input place.
  printf("Enter a radius: ");
  //get the data that user inputed.
  scanf("%d",&radius);
  //output the message and the sphere volume.
  printf("sphere volume: %.2f cubic meters\n",(4.0f/3.0f)*pi*radius*radius*radius);
  return 0;
}