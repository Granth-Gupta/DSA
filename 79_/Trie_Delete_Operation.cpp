// Trie Delete Operation

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
    TrieNode *deleteWord(TrieNode *root, string word);
};

// ---------- Helper Functions ----------

bool searchUtil(TrieNode *root, string word, int pos)
{
    if (root == NULL)
        return false;

    if (pos == word.length())
        return root->isEnd;

    int index = word[pos] - 'a';

    return searchUtil(root->children[index], word, pos + 1);
}

bool searchWord(TrieNode *root, string word)
{
    return searchUtil(root, word, 0);
}

bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
            return false;
    }
    return true;
}

TrieNode *deleteUtil(TrieNode *root, string word, int pos)
{
    if (root == NULL)
        return NULL;

    if (pos == word.length())
    {
        root->isEnd = false;

        if (isEmpty(root))
        {
            delete root;
            return NULL;
        }

        return root;
    }

    int index = word[pos] - 'a';

    root->children[index] =
        deleteUtil(root->children[index], word, pos + 1);

    if (isEmpty(root) && !root->isEnd)
    {
        delete root;
        return NULL;
    }

    return root;
}

// ---------- solution Class Function ----------

TrieNode *solution::deleteWord(TrieNode *root, string word)
{
    if (searchWord(root, word))
    {
        root = deleteUtil(root, word, 0);
    }

    return root;
}

// ---------- Insert Function (for testing) ----------

void insertWord(TrieNode *root, string word)
{
    TrieNode *curr = root;

    for (char ch : word)
    {
        int index = ch - 'a';

        if (curr->children[index] == NULL)
        {
            curr->children[index] = new TrieNode();
        }

        curr = curr->children[index];
    }

    curr->isEnd = true;
}

// ---------- Main ----------

int main()
{
    TrieNode *root = new TrieNode();

    insertWord(root, "hello");
    insertWord(root, "help");
    insertWord(root, "hi");

    cout << "hello present: "
         << searchWord(root, "hello") << endl;

    solution obj;

    root = obj.deleteWord(root, "hello");

    cout << "hello present after deletion: "
         << searchWord(root, "hello") << endl;

    cout << "help present: "
         << searchWord(root, "help") << endl;

    cout << "hi present: "
         << searchWord(root, "hi") << endl;

    return 0;
}