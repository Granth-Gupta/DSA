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
        isTerminal = false;
        childCount = 0;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
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

    void insertUtil(TrieNode *root, const string &word, int pos)
    {
        if (pos == word.length())
        {
            root->isTerminal = true;
            return;
        }

        int index = word[pos] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[pos]);
            root->children[index] = child;
            root->childCount++;
        }

        insertUtil(child, word, pos + 1);
    }

    void insertWord(const string &word)
    {
        insertUtil(root, word, 0);
    }

    void lcp(const string &str, string &ans)
    {
        TrieNode *curr = root;

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (curr->childCount == 1)
            {
                ans.push_back(ch);

                int index = ch - 'a';
                curr = curr->children[index];
            }
            else
            {
                break;
            }

            if (curr->isTerminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    if (n == 0)
        return "";

    Trie *T = new Trie('\0');

    for (int i = 0; i < n; i++)
    {
        T->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    T->lcp(first, ans);

    delete T;

    return ans;
}

int main()
{
    vector<string> arr = {"Coding", "CodingNinjas", "CodeForces"};
    string ans = longestCommonPrefix(arr, 3);

    cout << "Longest Common Prefix is " << ans;

    return 0;
}