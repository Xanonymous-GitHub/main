/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 林天佑                                                 */
/* ID: 108820003                                                 */
/* Date: 2019.12.28                                              */
/* Purpose: Be the best student.                                 */
/* GitHub:  https://github.com/Xanonymous-GitHub/main/tree/HW    */
/*****************************************************************/
#include <stdio.h>
#define len(x) ((int)(sizeof(x) / sizeof(x[0]))) //長度
const struct {
    const char *country; //國家
    int country_code;    //國碼
} country_codes[] =
    {{"Argentina", 54}, {"Bangladesh", 889}, {"Brazil", 55}, {"Burma (Myanmar)", 95}, {"China", 86}, {"Columbia", 57}, {"Congo, Dem. Rep. of", 243}, {"Egypt", 20}, {"Ethiopia", 251}, {"France", 33}, {"Germany", 49}, {"India", 91}, {"Indonesia", 62}, {"Iran", 98}, {"Italy", 39}, {"Japan", 81}, {"Mexico", 52}, {"Nigeria", 234}, {"Pakistan", 92}, {"Philippines", 63}, {"Poland", 48}, {"Russia", 7}, {"South Africa", 27}, {"South Korea", 82}, {"Spain", 34}, {"Sudan", 249}, {"Thailand", 66}, {"Turkey", 90}, {"Ukraine", 380}, {"United Kingdom", 44}, {"United States", 1}, {"Vietnam", 84}};
int main(int argc, char *argv[]) {
    int code, i = 0, j = len(country_codes);         //宣告
    printf("Enter an international dialing code: "); //訊息
    scanf("%d", &code);                              //讀取
    while (i < j) {
        if (code == country_codes[i].country_code) {
            printf("%d is the code for %s.\n", code, country_codes[i].country); //找到
            return 0;
        }
        i++; //下一個
    }
    printf("Error: %d is not a valid country code.\n", code); //沒找到
    return 0;
}