/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.09.17                                              */
/* Purpose:                                                      */
/* Change History:                                               */
/*****************************************************************/
#include<stdio.h>
int GCD(int a,int b){
    //Euclidean algorithm (a type of recursion)
    if(a==0)return b;
    if(b==0)return a;
    return GCD(b,(a-b*(a/b)));
}
/* Simplification method explanation
If the numerator and the denominator are the same as the greatest common factor, 
then this score is the irreducible fraction.
That's why I init a GCD function to finish this step.
*/
int main(int argc,char* argv[]){
    //init variable
    /*
        These variables represent the following templates:
        a1/a2+b1/b2=c1/c2
    */
    int a1,a2,b1,b2,c1,c2;
    //show a message that tells user there is the input place.
    printf("Enter two fractions separated by a plus sign: ");
    //get the data that user inputed.
    scanf("%d/%d+%d/%d",&a1,&a2,&b1,&b2);
    //Cross multiplication.
    c2=a2*b2;
    c1=a1*b2+a2*b1;
    //_GCD is the Maximum common factor of c1 & c2.
    //The first parameter of the function (GCD) must be greater than the Last one.
    int _GCD=GCD((c2>c1)?c2:c1,(c2<c1)?c2:c1);
    //out put the result (irreducible fraction)
    printf("%d/%d",c1/_GCD,c2/_GCD);
    return 0;
}