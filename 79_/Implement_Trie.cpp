// Implement Trie - CN

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class solution
{
public:
    TrieNode *root = new TrieNode();

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isEnd = true;
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
            child = new TrieNode();
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isEnd;
        }

        int index = word[0] - 'a';

        if (root->children[index] == NULL)
        {
            return false;
        }

        return searchUtil(root->children[index], word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    bool startsWithUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'a';

        if (root->children[index] == NULL)
        {
            return false;
        }

        return startsWithUtil(root->children[index], word.substr(1));
    }

    bool startsWith(string word)
    {
        return startsWithUtil(root, word);
    }
};

int main()
{
    // solution *T = new solution();
    solution T;

    // T->insert("Hello");
    // T->insert("Do");
    // T->insert("Time");

    T.insert("Time");
    T.insert("Hello");

    cout << "\"Tim\" Present or Not: " << T.search("Tim") << endl;
    cout << "\"Time\" Present or Not: " << T.search("Time") << endl;

    return 0;
}