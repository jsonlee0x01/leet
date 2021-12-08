#include <string>
#include <map>
#include <set>
using namespace std;

class WordDictionary {
public:
    WordDictionary()
    {}

    void addWord(string word)
    {
        if (data.count(word.size())) {
            data[word.size()].insert(word);
        } else {
            set<string> wordSet;
            wordSet.insert(word);
            data[word.size()] = wordSet;
        }
    }

    bool search(string word)
    {
        if (!data.count(word.size())) {
            return false;
        }
        if (data[word.size()].count(word)) {
            return true;
        }
        set<string> wordSet = data[word.size()];
        auto it = wordSet.begin();
    RESTART:
        auto ie = wordSet.end();
        for (; it != ie;) {
            for (int i = 0; i < it->size(); ++i) {
                if (word[i] != '.' && word[i] != (*it)[i]) {
                    ++it;
                    goto RESTART;
                }
            }
            wordSet.insert(word);
            return true;
        }
        return false;
    }

private:
    map<int, set<string>> data;
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
