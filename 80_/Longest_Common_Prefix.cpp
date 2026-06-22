// Longest Common Prefix - CN - Approach#1 - Using First string of arr traversal
// {TC - O(M*N), SC - O(1) {If ans space excluded i.e. SC is Auxilary SC}}

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for (int i = 0; i < arr[0].size(); i++)
    {
        char ch = arr[0][i];
        bool match = true;

        for (int j = 0; j < n; j++)
        {
            if ((arr[j].size() < i) || (arr[j][i] != ch))
            {
                match = false;
                break;
            }
        }

        if (match == false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

int main()
{
    vector<string> arr = {"Coding", "CodingNinjas", "CodeForces"};
    string ans = longestCommonPrefix(arr, 3);

    cout << "Longest Common Prefix is " << ans;

    return 0;
}