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

TEST(Ladder, test1) {
  set<string> word_list;
  load_words(word_list, "./src/words.txt");
  ASSERT_EQ(generate_word_ladder("cat", "dog", word_list).size(), 4);
}

TEST(Ladder, test2) {
  set<string> word_list;
  load_words(word_list, "./src/words.txt");
  ASSERT_EQ(generate_word_ladder("marty", "curls", word_list).size(), 6);
}

TEST(Ladder, test3) {
  set<string> word_list;
  load_words(word_list, "./src/words.txt");
  ASSERT_EQ(generate_word_ladder("code", "data", word_list).size(), 6);
}

TEST(Ladder, test4) {
  set<string> word_list;
  load_words(word_list, "./src/words.txt");
  ASSERT_EQ(generate_word_ladder("work", "play", word_list).size(), 6);
}

TEST(Ladder, test5) {
  set<string> word_list;
  load_words(word_list, "./src/words.txt");
  ASSERT_EQ(generate_word_ladder("sleep", "awake", word_list).size(), 8);
}

TEST(Ladder, test6) {
  set<string> word_list;
  load_words(word_list, "./src/words.txt");
  ASSERT_EQ(generate_word_ladder("car", "cheat", word_list).size(), 4);
}
