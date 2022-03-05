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

    bool isTree() // tree is an acyclic graph
    {
        bool *visited = new bool[v];
        int *parent = new int[v];

        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            parent[i] = i;
        }

        queue<int> q;
        int src = 0;
        q.push(src);
        visited[src] = false;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto x : l[front])
            {
                if (visited[x] && parent[front] != x)
                {
                    return false;
                }
                else if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                    parent[x] = front;
                }
            }
        }
        return true;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);

    cout << g.isTree() << endl;
    return 0;
}