#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0);
    long n = 0, q = 0, m = 0, ask = 0;
    while (cin >> n >> q)
    {
        long datas[n];
        for (long i = 0; i < n; i++)
            cin >> datas[i];
        sort(datas, datas + n);
        while (q--)
        {
            long l = 1, r = n;
            m = (r + l) / 2;
            cin >> ask;
            while (r - l)
            {
                if (r < l)
                    break;
                if (ask >= datas[m - 1])
                    l = m + 1;
                else
                    r = m - 1;
                m = (r + l) / 2;
            }
            if (datas[l - 1] > ask)
                l -= 1;
            if (l % 2)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}