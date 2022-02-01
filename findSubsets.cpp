#include <bits/stdc++.h>
using namespace std;

void subsets(string str, string ans = "")
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    subsets(str.substr(1), ans + str[0]);
    subsets(str.substr(1), ans);
}

int main()
{
    string str;
    cin >> str;

    subsets(str, "");
    return 0;
}