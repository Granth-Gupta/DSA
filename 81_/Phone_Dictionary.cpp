// Implement a phone Dictionary - CN

// TC -> O(N * M^2)
// SC -> O(N * M)

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
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
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        string prefix = "";
        vector<vector<string>> output;

        for (int i = 0; i < str.size(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);

            TrieNode *curr = prev->children[lastch - 'a'];

            if (curr == NULL)
                break;

            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *T = new Trie();

    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        T->insertWord(str);
    }

    return T->getSuggestions(queryStr);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<string> contactList(n);

        for (int i = 0; i < n; i++)
        {
            cin >> contactList[i];
        }

        string queryStr;
        cin >> queryStr;

        vector<vector<string>> ans = phoneDirectory(contactList, queryStr);

        for (auto &v : ans)
        {
            for (auto &s : v)
            {
                cout << s << " ";
            }
            cout << endl;
        }
    }

    // Input Example

    // 2
    // 5
    // cod coding codding code coly
    // coding
    // 2
    // ninjas coding
    // ninja

    return 0;
}