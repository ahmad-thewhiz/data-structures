// Problem Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/

class TrieNode {
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data=ch;
        
        for(int i=0;i<26;i++)
            children[i]=nullptr;
        
        isTerminal=false;
    }
};

class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        root=new TrieNode('\0');
    }
    
    void insertion(TrieNode* root, string word) {
        if(word.length()==0) {
            root->isTerminal=true;
            return ;
        }

        char ch=toupper(word[0]);
        int idx=ch-'A';
        TrieNode* child;

        if(root->children[idx]!=nullptr) {
            child=root->children[idx];
        } else {
            child=new TrieNode(ch);
            root->children[idx]=child;
        }

        insertion(child, word.substr(1));
    }

    void addWord(string word) {
        insertion(root, word);
    }
    
    bool searching(TrieNode* root, string word) {
        if (word.size() == 0)
            return root->isTerminal;

        char ch = toupper(word[0]);
        int idx = ch - 'A';

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != nullptr) {
                    if (searching(root->children[i], word.substr(1)))
                        return true;
                }
            }
            return false; 
        } else {
            if (root->children[idx] == nullptr)
                return false;

            return searching(root->children[idx], word.substr(1));
        }
    }


    bool search(string word) {
        return searching(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
