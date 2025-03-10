#include "dijkstras.h"
#include <list>

struct MinComp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    vector<int> distances(G.numVertices, INF);
    vector<bool> visited(G.numVertices, false);
    distances[source] = 0;
    previous[source] = -1; // undefined
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, MinComp> minHeap; // pair<vertex,weight>
    minHeap.push({source,0});
    
    while(!minHeap.empty()) {
        int u = minHeap.top().first; // gets vertex from the pair
        minHeap.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge e : G[u]) {
            int v = e.dst;
            int weight = e.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v,distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    list<int> list_path;
    for(int e = destination; e != -1; e = previous[e])
        list_path.push_front(e);
    vector<int> shortest_path(list_path.begin(), list_path.end());
    return shortest_path;
}

void print_path(const vector<int>& v, int total) {
    for (int e : v)
        cout << e << ' ';
    cout << "\nTotal cost is " << total << endl;
}
