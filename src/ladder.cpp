#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << word1 << word2 << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int comp = str1.size() - str2.size();
    if (comp < -1 || 1 < comp) return false;
    int size = str1.size() > str2.size() ? str1.size() : str2.size();
    int diff = d;
    for (int i = 0, j = 0; i < size && diff >= 0; ++i, ++j) {
        if (str1[i] != str2[j]) {
            --diff;
            if (comp == 1 && str1[i + 1] == str2[j]) ++i;
            if (comp == -1 && str1[i] == str2[j + 1]) ++j;
        }
    }
    return 0 <= diff && diff <= d;
}
// can i delete one character with str compare, check for equality and if still not equal then false
// the difference should be AT LEAST 1

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    if (begin_word == end_word || word_list.find(end_word) == word_list.end()) return {};
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder[ladder.size() - 1];
        for (string word : word_list) {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
                visited.insert(word);
                vector<string> new_ladder(ladder);
                new_ladder.push_back(word);
                if (word == end_word) return new_ladder;
                ladder_queue.push(new_ladder);
            }
        }
    }
    return {};
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
    if (ladder.size() == 0) {
        cout << "No word ladder found.";
    } else {
        cout << "Word ladder found: ";
        for (string word : ladder)
            cout << word << ' ';
    }
    cout << '\n';
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
