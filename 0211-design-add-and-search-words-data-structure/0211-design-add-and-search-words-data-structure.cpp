class WordDictionary {
public:
    bool isleaf;
    WordDictionary* children[26];
    WordDictionary() {
        isleaf = false;
        for (int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
            
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;

        for(char c: word){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a']= new WordDictionary();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isleaf = true;
    }
    
    bool dfs(string &word, int i, WordDictionary* node) {
        if (i == word.size())
            return node->isleaf;

        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->children[j] &&
                    dfs(word, i + 1, node->children[j]))
                    return true;
                }
            return false;
        }

        int idx = word[i] - 'a';

        if (node->children[idx] == nullptr)
            return false;

        return dfs(word, i + 1, node->children[idx]);
    }

    bool search(string word) {
        return dfs(word, 0, this);
    }   
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */