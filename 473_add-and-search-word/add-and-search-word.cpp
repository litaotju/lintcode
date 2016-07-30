/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/add-and-search-word
@Language: C++
@Datetime: 16-06-12 13:48
*/

struct trieNode {
        trieNode() : terminableSize(0) {
            for (int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
        
        ~trieNode() {
            for (int i = 0; i < 26; ++i) {
                if (children[i]) {
                    delete children[i];
                    children[i] = NULL;
                }
            }
        }
        
        int terminableSize;
        trieNode *children[26];
};

class WordDictionary {
public:
    WordDictionary() : root(new trieNode) {}
    
    size_t Index(char c) {
        return static_cast<size_t>(c % 26);
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        trieNode *cur = root;
        for (size_t i = 0; i < word.size(); ++i) {
            size_t idx = Index(word[i]);
            if (!cur->children[idx]) {
                cur->children[idx] = new trieNode;
            }
            cur = cur->children[idx];
        }
        ++cur->terminableSize;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search_dfs(word, root);
    }
    
    bool search_dfs(string word, trieNode *cur) {
        if (word.size() == 0 && cur->terminableSize > 0)
            return true;
        for (size_t i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (size_t j = 0; j < 26; ++j) {
                    if (cur->children[j] && search_dfs(word.substr(i + 1), cur->children[j]))
                        return true;
                }
                return false;
            }
            else {
                size_t idx = Index(word[i]);
                if (!cur->children[idx])
                    return false;
                cur = cur->children[idx];
            }
        }
        if (cur->terminableSize > 0)
            return true;
        return false;
    }
    
private:
    
    trieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");