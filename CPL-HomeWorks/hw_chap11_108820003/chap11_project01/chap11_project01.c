/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.11.23                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    //step by step to get the answer.
    *twenties = dollars / 20;

    //save the previous change.
    dollars -= *twenties * 20;

    *tens = dollars / 10;

    //save the previous change.
    dollars -= *tens * 10;

    *fives = dollars / 5;

    //save the previous change.
    dollars -= *fives * 5;

    *ones = dollars;
}
int main(int argc, char *argv[]) {
    //init a variable that store the user's dollar amount.
    int dollar_amount = 0;
    //show a message that tells user there is the input place.
    printf("Enter a dollar amount: ");
    //get the data that user inputed.
    scanf("%d", &dollar_amount);
    //init four variable, a is the amount of $20, b is the amount of $10, c is the amount of $5, d is the amount of $1.
    int a, b, c, d;
    pay_amount(dollar_amount, &a, &b, &c, &d);
    //output the answer.
    printf("\n$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", a, b, c, d);
    return 0;
}