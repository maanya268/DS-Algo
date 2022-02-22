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

    void addEdge(int f, int s)
    {
        l[f].push_back(s);
        l[s].push_back(f);
    }

    void printAdjList()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " : ";
            for (auto x : l[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void BFS(int sv)
    {
        queue<int> q;
        unordered_map<int, int> visited;

        q.push(sv);
        visited[sv] = 1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cout << front << " ";

            for (auto x : l[front])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = 1;
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.BFS(0);
    return 0;
}