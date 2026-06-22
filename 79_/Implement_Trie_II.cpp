// Implement Trie ll - Coding ninjas

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    int wordCount;
    int prefixCount;

    TrieNode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
        wordCount = 0;
        prefixCount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        root->prefixCount++;

        if (word.length() == 0)
        {
            root->isTerminal = true;
            root->wordCount++;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(const string &word)
    {
        insertUtil(root, word);
    }

    int countWordsEqualTo(string &word)
    {
        TrieNode *curr = root;

        for (char ch : word)
        {
            int index = ch - 'a';

            if (curr->children[index] == NULL)
                return 0;

            curr = curr->children[index];
        }

        return curr->wordCount;
    }

    int countWordsStartingWith(string &word)
    {
        TrieNode *curr = root;

        for (char ch : word)
        {
            int index = ch - 'a';

            if (curr->children[index] == NULL)
                return 0;

            curr = curr->children[index];
        }

        return curr->prefixCount;
    }

    void eraseUtil(TrieNode *root, string word, int pos)
    {
        root->prefixCount--;

        if (pos == word.length())
        {
            root->wordCount--;

            if (root->wordCount == 0)
                root->isTerminal = false;

            return;
        }

        int index = word[pos] - 'a';
        TrieNode *child = root->children[index];

        if (child == NULL)
            return;

        eraseUtil(child, word, pos + 1);
    }

    void erase(string &word)
    {
        eraseUtil(root, word, 0);
    }
};

int main()
{
    Trie trie;

    string word1 = "apple";
    string word2 = "app";
    string word3 = "bat";

    trie.insert("apple");
    trie.insert(word1);
    trie.insert(word2);
    trie.insert(word3);

    cout << "Count of 'apple': "
         << trie.countWordsEqualTo(word1) << endl;

    cout << "Count of words starting with 'app': "
         << trie.countWordsStartingWith(word2) << endl;

    trie.erase(word1);

    cout << "\nAfter erasing one 'apple':\n";

    cout << "Count of 'apple': "
         << trie.countWordsEqualTo(word1) << endl;

    cout << "Count of words starting with 'app': "
         << trie.countWordsStartingWith(word2) << endl;

    cout << "Count of 'bat': "
         << trie.countWordsEqualTo(word3) << endl;

    return 0;
}