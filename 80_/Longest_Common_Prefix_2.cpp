// Longest Common Prefix - CN - Approach#2 - Using Trie (Worse SC then Approach #1, But same TC)
// TC -> O(M*N), SC -> O(M*N)

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
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
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else
                break;

            if (root->isTerminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *T = new Trie('\0');

    for (int i = 0; i < arr.size(); i++)
    {
        T->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    T->lcp(first, ans);

    return ans;
}

int main()
{
    vector<string> arr = {"Coding", "CodingNinjas", "CodeForces"};
    string ans = longestCommonPrefix(arr, 3);

    cout << "Longest Common Prefix is " << ans;

    return 0;
}