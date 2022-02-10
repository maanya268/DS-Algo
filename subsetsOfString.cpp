#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int totalSubsets = (1 << str.length());

    for (int i = 0; i < totalSubsets; i++)
    {
        int j = 0;
        int temp = i;
        while (temp)
        {
            int lastBit = (temp & 1);
            if (lastBit)
            {
                cout << str[j];
            }
            j++;
            temp = temp >> 1;
        }
        cout << endl;
    }
    return 0;
}