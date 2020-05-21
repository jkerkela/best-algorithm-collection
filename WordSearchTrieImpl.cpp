class Trie {
    
    struct TrieNode{
        struct TrieNode *children[26];
        bool isEndOfWord;
    };
    TrieNode* node;
    
public:
  
    Trie() {
        node=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p_current = node; 
        for (auto& current_char: word) 
        { 
            int index = current_char - 'a'; 
            if (!p_current->children[index]) {
                p_current->children[index] = new TrieNode();
            }
            p_current = p_current->children[index]; 
        } 
        p_current->isEndOfWord = true; 
    }
    

    bool search(string word) {
        TrieNode* p_current = node; 
        for (auto& current_char: word) 
        { 
            int index = current_char - 'a'; 
            if (!p_current->children[index]) {
                return false;
            }
            p_current = p_current->children[index]; 
        } 
        return p_current->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p_current = node; 
        for (auto& current_char: prefix) 
        { 
            int index = current_char - 'a'; 
            if (!p_current->children[index]) {
                return false;
            }
            p_current = p_current->children[index]; 
        } 
        return true;
    }
};
