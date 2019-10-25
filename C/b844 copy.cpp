#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find(int q, vector<int> num, int n)
{ //找第一個比q大的
    int left = 0, right = n;

    while (left < right)
    {
        int mid = (left + right) / 2; //mid最後要等於第一個比q大的
        if (num[mid] > q)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        printf("mid = %d\n", mid);
    }

    return (left + right) / 2;
}

int main()
{
    int n, q;
    while (scanf("%d %d", &n, &q) != EOF)
    {
        vector<int> num(n, 0);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        sort(num.begin(), num.end());

        for (int i = 0; i < q; i++)
        {
            int question;
            scanf("%d", &question);
            int ans = find(question, num, n - 1);

            printf("ans = %d\n", ans);
            if (ans % 2 == 0)
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
        }
    }
    return 0;
}