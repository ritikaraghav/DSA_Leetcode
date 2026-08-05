class Trie {
public:
        bool isleaf;

        Trie* children[26];

        Trie(){
            isleaf = false;
            for( int i = 0; i < 26 ; i++){
                children[i] = nullptr;
            }
        }
    
    
    void insert(string word) {
        Trie* curr = this;

        for( char c : word){
            int index = c - 'a';
            if(curr->children[index] == nullptr){
                curr->children[index] = new Trie();
            }
            curr = curr->children[index];
        }
        curr->isleaf = true;
    }
    
    bool search(string word) {
        Trie* curr = this;

        for(char c : word){
            if(curr->children[c - 'a'] == nullptr)return false;

            curr = curr->children[c-'a'];
        }
        return curr->isleaf;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(char c: prefix){
            int index = c-'a';
            if(curr->children[index] == nullptr)return false;

            curr = curr->children[index];
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