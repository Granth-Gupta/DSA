// First Non-Repeating charater in a stream

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

void firstNonRepeatingChar(const string& str) {
    unordered_map<char, int> charCount;
    queue<char> q;

    for (char ch : str) {
        // Increment the count of the character
        charCount[ch]++;

        // If it's the first occurrence, add it to the queue
        if (charCount[ch] == 1) {
            q.push(ch);
        }

        // Remove characters from the front of the queue until we find a non-repeating character
        while (!q.empty() && charCount[q.front()] > 1) {
            q.pop();
        }

        // Print the first non-repeating character or # if there isn't one
        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout  << "# ";
        }
    }
}

int main() {
    string input = "aabc";
    cout << "First non-repeating characters in the stream: ";
    firstNonRepeatingChar(input);
    cout << endl;
    return 0;
}
