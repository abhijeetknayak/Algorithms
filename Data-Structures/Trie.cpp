class Trie {
private:
    struct TrieNode {
        map<char, TrieNode *> next_char;
        bool complete;
    };
    TrieNode * root;   
    
public:
    /** Initialize your data structure here. */    
    Trie() {
        root = new TrieNode();
        root->complete = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->next_char.find(word[i]) != temp->next_char.end()) {
                temp = temp->next_char[word[i]];
            }
            else {
                /* Insert new node into the map */
                cout << "Inserting " << word[i] << endl; 
                temp->next_char[word[i]] = new TrieNode();
                temp = temp->next_char[word[i]];
            }
            
            if (i == word.size() - 1) {
                temp->complete = true;
            }
        }        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->next_char.find(word[i]) != temp->next_char.end()) {
                cout << "found Character" << endl;
                temp = temp->next_char[word[i]];
                if (i == word.size() - 1 && temp->complete) return true;
            }
            else return false;
        }
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * temp = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (temp->next_char.find(prefix[i]) == temp->next_char.end()) {
                return false;
            }
            else {
                temp = temp->next_char[prefix[i]];
            }
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
