#include <bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addEdge(string src, string dest, bool bidir, int wt)
    {
        l[src].push_back(make_pair(dest, wt));
        if (bidir)
        {
            l[dest].push_back(make_pair(src, wt));
        }
    }

    void printAdjList()
    {
        for (auto p : l)
        {
            string city = p.first;
            list<pair<string, int>> nbrs = p.second;

            cout << city << " : ";
            for (auto nbr : nbrs)
            {
                cout << nbr.first << " " << nbr.second << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.printAdjList();
    return 0;
}