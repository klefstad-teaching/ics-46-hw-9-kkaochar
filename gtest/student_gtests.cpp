#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Dijkstras, test1) {
  Graph g;
  file_to_graph("./src/small.txt", g);
  vector<int> prev(g.numVertices);
  vector<int> distances = dijkstra_shortest_path(g, 0, prev);
  vector<int> shortest_path = extract_shortest_path(distances, prev, 0);
  ASSERT_EQ(0, distances[0]);
  ASSERT_EQ(0, shortest_path[0]);
}
