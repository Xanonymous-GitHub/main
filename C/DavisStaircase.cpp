#include <bits/stdc++.h>
using namespace std;
vector<int> record(37, 0);
int steps(int data)
{
    if (record[data - 1] != 0)
        return record[data - 1];

    if (data == 1)
        return 1;
    if (data == 2)
        return 2;
    if (data == 3)
        return 4;

    return steps(data - 1) + steps(data - 2) + steps(data - 3);
}
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0);
    int s = 0, data = 0;
    cin >> s;
    while (s--)
    {
        cin >> data;
        record[data - 1] = steps(data);
        cout << record[data - 1] << endl;
    }
    return 0;
}