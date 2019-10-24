#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0);
    long n = 0, k = 0, test = 0, a = 0, b = 0, center = 0, center_index = 0;
    cin >> n >> k;
    long data[100005];
    for (long i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    while (k--)
    {
        b = n;
        a = 0;
        cin >> test;
        center_index = (a + b) / 2;
        while (1)
        {
            center_index = (a + b) / 2;
            if (test > data[center_index])
            {
                a = center_index;
            }
            else if (test < data[center_index])
            {
                b = center_index;
            }
            else
            {
                cout << center_index + 1 << endl;
                break;
            }
            if (b - a <= 1)
            {
                if (test == data[b])
                {
                    cout << b + 1 << endl;
                    break;
                }
                if (test == data[a])
                {
                    cout << a + 1 << endl;
                    break;
                }
                cout << 0 << endl;
                break;
            }
        }
    }
    return 0;
}