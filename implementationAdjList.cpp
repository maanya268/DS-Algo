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
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjList();
    return 0;
}