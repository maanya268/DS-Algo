#include <bits/stdc++.h>
using namespace std;

string stringWindow(string s1, string s2)
{
    // this map is for the pattern
    unordered_map<char, int> s2Map;
    for (int i = 0; i < s2.length(); i++)
    {
        s2Map[s2[i]]++;
    }

    unordered_map<char, int> windowMap; // map for string
    int windowLen = 0;                  // to calculate the length of windows available
    int minWindowLen = INT_MAX;         // final length of the substring

    int start = 0;
    int end = 0;
    int finalStart = -1; // final start of the substring
    int count = 0;       // to match the characters that have been matched

    while (end < s1.length())
    {
        char ch = s1[end];
        windowMap[ch]++;
        // now matching the characters
        // if we find a character that is present in s1 also in s2..we have to check if the freq of the character in the window map is less than the freq in s2map
        //  we have to increment the count if and only if the character is present in s2 and frequence of it is greater than or equal to that in window map
        if (s2Map.find(ch) != s2Map.end() && windowMap[ch] <= s2Map[ch])
        {
            count++;
        }

        // if full pattern is matched
        if (count == s2.length())
        {
            // contraction
            //  a char is useless if its freq in the s2 map is 0 or if the freq of it in window map is greater than that in s2 map
            while (s2Map.find(s1[start]) == s2Map.end() or windowMap[s1[start]] > s2Map[s1[start]])
            {
                windowMap[s1[start]]--;
                start++;
            }

            // now our window becomes small and precise
            windowLen = end - start + 1;
            if (minWindowLen > windowLen)
            {
                minWindowLen = windowLen;
                finalStart = start;
            }
        }
        end++;
    }
    if (finalStart == -1)
    {
        return "No Window Find";
    }
    return s1.substr(finalStart, minWindowLen);
}

int main()
{
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    cout << stringWindow(s1, s2) << endl;
    return 0;
}