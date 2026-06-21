// Trie Search
// TC - O(length of word)

#include <iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL){
                child = root->children[index];
            }else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root, word);
        }

        bool searchUtils(TrieNode* root, string word){
            // Base Case
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // present
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                // absent
                return false;
            }

            // Recursion
            return searchUtils(child, word.substr(1));
        }

        bool searchWord(string word){
            return searchUtils(root, word);
        }
};

int main(){
    Trie* T = new Trie();

    T->insertWord("Hello");
    T->insertWord("Do");
    T->insertWord("Time");

    cout << "\"Tim\" Present or Not: " << T->searchWord("Tim") << endl;
    cout << "\"Time\" Present or Not: " << T->searchWord("Time") << endl;

    return 0;
}