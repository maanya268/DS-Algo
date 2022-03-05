// Here our aim is to find a back edge
// that means if nbr of a node is visited and already exists in the current path
// this means a back edge is present which confirms that the cycle is present in the directed graph

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
    }

    bool containsCycleHelper(int src, bool *visited, bool *stack)
    {
        // exists in the current path and visited
        stack[src] = true;
        visited[src] = true;

        for (auto x : l[src])
        {
            if (stack[x] == true && visited[x])
            {
                return true;
            }
            else if (!visited[x])
            {
                bool haveCycle = containsCycleHelper(x, visited, stack);
                if (haveCycle)
                {
                    return true;
                }
            }
        }

        // remove from path
        stack[src] = false;
        return false;
    }
    bool containsCycle()
    {
        bool *visited = new bool[v];
        bool *stack = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = stack[i] = false;
        }
        return containsCycleHelper(0, visited, stack);
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2);

    cout << g.containsCycle() << endl;
    return 0;
}