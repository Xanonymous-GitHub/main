#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0);
    string data;
    unsigned long long n = 0, result = 0;
    cin >> data >> n;
    unsigned long long _size = data.size();
    for (unsigned long long i = 0; i < n; i++)
    {
        if (data[i % _size] == 'a')
        {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}