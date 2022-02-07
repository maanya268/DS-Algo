#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> x, vector<int> y, int w, int h, int n)
{
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int dx = x[0] - 1;
    int dy = y[0] - 1;

    for (int i = 0; i < n; i++)
    {
        dx = max(dx, x[i] - x[i - 1] - 1);
        dy = max(dy, y[i] - y[i - 1] - 1);
    }

    dx = max(dx, w - x[n - 1]);
    dy = max(dy, h - y[n - 1]);

    return dx * dy;
}

int main()
{
    int n, w, h;
    cout << "Enter n w h" << endl;
    cin >> n >> w >> h;
    vector<int> x;
    vector<int> y;

    for (int i = 0; i < n; i++)
    {
        int xc, yc;
        cin >> xc >> yc;
        x.push_back(xc);
        y.push_back(yc);
    }

    cout << maxArea(x, y, w, h, n) << endl;
    return 0;
}