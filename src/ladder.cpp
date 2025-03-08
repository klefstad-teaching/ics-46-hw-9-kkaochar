#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << word1 << word2 << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    return str1 != str2 || d; // placeholder
}

bool is_adjacent(const string& word1, const string& word2) {
    return word1 != word2; // placeholder
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    vector<string> ladder;
    if (begin_word != end_word) return ladder; // begin and end word shouldn't be equal
    return ladder; // placeholder
}

void load_words(set<string> & word_list, const string& file_name) {
    cout << word_list << file_name; // placeholder
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
