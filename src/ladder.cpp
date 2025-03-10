#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << word1 << word2 << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    return str1 != str2 || d; // placeholder
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}



void lower_word(string & word) {
    if (word[0] >= 'A' && word[0] <= 'Z')
        word[0] += 32;
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in_file(file_name);
    if (!in_file) { return; }
    string word;
    while (in_file >> word) {
        lower_word(word);
        word_list.insert(word);
    }
    in_file.close();
}

void print_word_ladder(const vector<string>& ladder) {
    for (string word : ladder)
        cout << word << ' ';
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
