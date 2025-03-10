#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    cout << G << source << previous << endl;
    vector<int> shortest_path;
    return shortest_path;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> shortest_path;
    for(int e = previous[destination]; e != -1 ; e = previous[e]) {
        shortest_path.push_back(e);
    }
    shortest_path.push_back(0);
    return shortest_path;
}

void print_path(const vector<int>& v, int total) {
    for (int e : v)
        cout << e << ' ';
    cout << "Total cost is " << total << endl;
}
