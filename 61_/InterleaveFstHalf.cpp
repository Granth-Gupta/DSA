// Interleave the first half of the string with the second half of the string (e.g., "abcdef" becomes "adbecf"). - GFG
// Using Queue to store the characters of the first half and then interleaving them with the second half.
// Tc: O(n) where n is the length of the string, Sc: O(n/2) for the queue storing the first half of the string.

#include <iostream>
#include <queue>

using namespace std;

string interleaveString(const string& str) {
    int n = str.length();
    queue<char> q;

    // Enqueue the first half of the string
    for (int i = 0; i < n / 2; i++) {
        q.push(str[i]);
    }

    string result;
    // Interleave the characters from the queue with the second half of the string
    for (int i = n / 2; i < n; i++) {
        if (!q.empty()) {
            result += q.front(); // Add character from the first half
            q.pop();
        }
        result += str[i]; // Add character from the second half
    }

    return result;
}

int main() {
    string input = "abcdef";
    string interleaved = interleaveString(input);
    cout << "Interleaved string: " << interleaved << endl; // Output: "adbecf"
    return 0;
}
