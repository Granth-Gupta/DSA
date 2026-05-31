// First Non-Repeating charater in a stream

#include <iostream>
#include <string>
using namespace std;

string firstNonRepeating(string A){
    string ans = "";
    int freq[26] = {0};
    for(int i=0; i<A.size(); i++){
        char ch = A[i];
        freq[ch - 'a']++;
        char firstNonRepeat = '#';
        for(int j=0; j<26; j++){
            if(freq[j] == 1){
                firstNonRepeat = (char)(j + 'a');
                break;
            }
        }
        ans += firstNonRepeat;
    }
    return ans;
}

int main(){
    
    string A;
    cout << "Enter the stream of characters: ";
    cin >> A;
    string result = firstNonRepeating(A);
    cout << "First non-repeating characters in the stream: " << result << endl;

    return 0;
}