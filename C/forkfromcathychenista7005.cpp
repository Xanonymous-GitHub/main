#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++){
        int num, max, a;
        scanf("%d", &a);
        vector<int> w(a);
        for (int j = 0; j < w.size(); j++){
            scanf("%d", &w[j]);
            if (j == 0){
                max = w[j];
                num = w[j];
            }
            else{
                if ((num < 0) && (num < w[j])){
                    num = w[j];
                    max = w[j];
                }
                else if ((num >= 0) && (num + w[j] < 0)){
                    num = 0;
                }
                else if (num + w[j] >= max){
                    max = num + w[j];
                    num = num + w[j];
                }
                else{
                    num = num + w[j];
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}