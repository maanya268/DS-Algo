#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> l;

public:
    void
    addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    int snakeAndLadder(int sv, int ev)
    {
        unordered_map<int, int> dist;
        unordered_map<int, int> map;
        queue<int> q;

        for (int i = sv; i <= ev; i++)
        {
            dist[i] = INT_MAX;
        }

        q.push(sv);
        dist[sv] = 0;

        map[sv] = -1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto x : l[front])
            {
                if (dist[x] == INT_MAX)
                {
                    q.push(x);
                    dist[x] = dist[front] + 1;
                    map[x] = front;
                }
            }
        }

        int i = ev;
        while (map[i] != -1)
        {
            cout << i << "<---";
            i = map[i];
        }
        cout << sv << endl;
        return dist[ev];
    }
};

int main()
{
    Graph g;

    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];

            if (j <= 36)
            {
                g.addEdge(i, j);
            }
        }
    }

    cout << g.snakeAndLadder(0, 36) << endl;
    return 0;
}