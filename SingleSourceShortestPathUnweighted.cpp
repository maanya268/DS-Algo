#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void shortestPath(int sv)
    {
        unordered_map<int, int> dist;
        queue<int> q;

        for (int i = 0; i < v; i++)
        {
            dist[i] = INT_MAX;
        }

        q.push(sv);
        dist[sv] = 0;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            // cout << front << " ";

            for (auto x : l[front])
            {
                if (dist[x] == INT_MAX)
                {
                    q.push(x);
                    dist[x] = dist[front] + 1;
                }
            }
        }

        for (int i = 0; i < v; i++)
        {
            cout << i << " : " << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.shortestPath(0);
    return 0;
}