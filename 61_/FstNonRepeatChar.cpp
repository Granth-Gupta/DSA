// First Non-Repeating charater in a stream

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

void firstNonRepeatingChar(const string& str) {
    unordered_map<char, int> charCount;
    queue<char> nonRepeatingQueue;

    for (char ch : str) {
        // Increment the count of the character
        charCount[ch]++;

        // If it's the first occurrence, add it to the queue
        if (charCount[ch] == 1) {
            nonRepeatingQueue.push(ch);
        }

        // Remove characters from the front of the queue until we find a non-repeating character
        while (!nonRepeatingQueue.empty() && charCount[nonRepeatingQueue.front()] > 1) {
            nonRepeatingQueue.pop();
        }

        // Print the first non-repeating character or # if there isn't one
        if (!nonRepeatingQueue.empty()) {
            cout << nonRepeatingQueue.front() << " ";
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
