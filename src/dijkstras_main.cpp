#include "dijkstras.h"

int main(int argc, char *argv[]) {
    string input_file = argc > 1 ? argv[1] : "small.txt";
    Graph g;
    file_to_graph(input_file, g);
    vector<int> previous(g.numVertices);
    vector<int> distances = dijkstra_shortest_path(g, 0, previous);
    for (int i = 0; i < g.numVertices; ++i) {
        print_path(extract_shortest_path(distances, previous, i), distances[i]);
    }
}