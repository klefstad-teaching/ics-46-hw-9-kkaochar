#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    cout << G << source << previous << endl;
    vector<int> shortest_path;
    return shortest_path;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    cout << previous << destination << endl;
    vector<int> shortest_path;
    return shortest_path;
}

void print_path(const vector<int>& v, int total) {
    cout << v << total << endl;
}
