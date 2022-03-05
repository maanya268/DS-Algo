#include <bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<int, list<pair<int, int>>> map;

public:
    void addEdge(int x, int y, int dist, bool bidir)
    {
        map[x].push_back(make_pair(y, dist));
        if (bidir)
        {
            map[y].push_back(make_pair(x, dist));
        }
    }

    void printAdjList()
    {
        for (auto x : map)
        {
            cout << x.first << " : ";
            for (auto y : x.second)
            {
                cout << y.first << " " << y.second << endl;
            }
        }
    }

    void dijkstra(int src)
    {
        unordered_map<int, int> dist;
        for (auto x : map)
        {
            dist[x.first] = INT_MAX;
        }

        set<pair<int, int>> s;

        dist[src] = 0;
        s.insert(make_pair(0, src));

        while (!s.empty())
        {
            // find the pair at the front
            auto p = *(s.begin());
            int node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            // iterate over the neighbors of current node
            for (auto childPair : map[node])
            {
                if (nodeDist + childPair.second < dist[childPair.first])
                {
                    int dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));

                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        for (auto d : dist)
        {
            cout << d.first << " is located at a distance of " << d.second << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 1, true);
    g.addEdge(1, 3, 4, true);
    g.addEdge(2, 3, 1, true);
    g.addEdge(3, 4, 2, true);
    g.addEdge(1, 4, 7, true);
    g.dijkstra(1);
    return 0;
}