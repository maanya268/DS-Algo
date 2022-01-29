#include <bits/stdc++.h>
using namespace std;

string subString(string str)
{
    // indexMap to store the indeces
    unordered_map<char, int> indexMap;
    int start = 0;
    int end = 0;

    int windowLen = 0;    // maintains the size of window at each step
    int maxWindowLen = 0; // maintains the largest window that has unique characters
    int finalStart = -1;  // the start of the substring that is the largest unique

    while (end < str.length())
    {
        // if the character already exists in the map
        if (indexMap.find(str[end]) != indexMap.end() && indexMap[str[end]] >= start)
        {
            // updating the start , window len, latest index, maxwindow len, final start
            start = indexMap[str[end]] + 1;
            // updating the window length
            windowLen = end - start;
        }
        // maintaining the index
        indexMap[str[end]] = end;
        // incrementing the window length by one as the new charcter has arrived
        windowLen++;
        // checking whether the window length has exceeded the maxWindow length
        if (windowLen > maxWindowLen)
        {
            maxWindowLen = windowLen;
            finalStart = start;
        }
        end++;
    }
    if (finalStart == -1)
    {
        return "No such string";
    }

    return str.substr(finalStart, maxWindowLen);
}

int main()
{
    string str;
    cin >> str;

    cout << subString(str) << endl;
    return 0;
}