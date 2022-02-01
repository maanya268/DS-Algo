#include <bits/stdc++.h>
using namespace std;

void generateBrackets(string output, int n, int i, int open, int close)
{
    if (i == 2 * n)
    {
        cout << output << endl;
        return;
    }
    if (open < n)
    {
        generateBrackets(output + '(', n, i + 1, open + 1, close);
    }

    if (close < open)
    {
        generateBrackets(output + ')', n, i + 1, open, close + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    generateBrackets("", n, 0, 0, 0);
    return 0;
}