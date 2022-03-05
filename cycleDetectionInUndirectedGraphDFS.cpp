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

    bool containsCycleHelper(int src, bool *visited, int *parent)
    {
        visited[src] = true;
        for (auto x : l[src])
        {
            if (visited[x] && parent[x] != src)
            {
                return true;
            }
            else
            {
                bool haveCycle = containsCycleHelper(x, visited, parent);
                if (haveCycle)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle()
    {
        bool *visited = new bool[v];
        int *parent = new int[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            parent[i] = i;
        }

        return containsCycleHelper(0, visited, parent);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    cout << g.containsCycle() << endl;
    return 0;
}