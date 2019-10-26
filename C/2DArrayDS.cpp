#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0);
    int max=-32767, tmp=0;
    //init a now vector to store the data from user.
    vector<vector<int>> data(6);

    //get data
    for (int i = 0; i < 6; i++)
    { 
        data[i].resize(6);

        for (int j = 0; j < 6; j++)
        {
            cin >> data[i][j];
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            tmp = data[i][j] + data[i - 1][j - 1] + data[i - 1][j] + data[i - 1][j + 1] + data[i + 1][j - 1] + data[i + 1][j] + data[i + 1][j + 1];
            if (tmp > max)
            {
                max = tmp;
            }
        }
    }
    cout << max << endl;
    return 0;
}