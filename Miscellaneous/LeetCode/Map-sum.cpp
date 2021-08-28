class MapSum {
public:
    struct TrieNode {
        map<char, TrieNode *> next_char;
        int val;
    };
    
    TrieNode * root;
    
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
        root->val = 0;        
    }
    
    void insert(string key, int val) {
        TrieNode * temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->next_char.find(key[i]) != temp->next_char.end()) {
                /* Character already available */
                temp = temp->next_char[key[i]];
            }
            else {
                temp->next_char[key[i]] = new TrieNode();
                temp = temp->next_char[key[i]];
            }
            
            if (i == key.size() - 1) temp->val = val; 
        }
    }
    
    int recursive_helper(TrieNode * root) {
        int result = 0;
        for (auto it: root->next_char) {
            result += it.second->val;
            result += recursive_helper(it.second);            
        }
        return result;
    }
    
    int sum(string prefix) {
        int result = 0;
        TrieNode * temp = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (temp->next_char.find(prefix[i]) == temp->next_char.end()) return 0;
            else temp = temp->next_char[prefix[i]];
        }
        
        result = temp->val;
        return result + recursive_helper(temp);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
