#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    vector<int> int_v;
    vector<int>::iterator g;
    int f[] = {0, 0, 2, 2, 5};
    for (int i = 0; i < 18; i++)
    {
        int_v.push_back(f[i % 5]);
    }
    for (g = int_v.begin(); g != int_v.end(); g++)
    {
        cout << *g << " " << endl;
    }
    cout << int_v[5] << endl;
    return 0;
}