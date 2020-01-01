#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0);
    string data;
    long n, ans;
    cin >> data >> n;
    for (int i = 0; i < data.size(); i++)
    {
        ans += data[i] - '0';
    }
    ans *= n;
    ans %= 9;
    if (ans)
    {
        cout << ans << endl;
    }
    else
    {
        cout << 9 << endl;
    }
    return 0;
}