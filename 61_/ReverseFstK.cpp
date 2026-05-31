// Greeks For Greeks question

#include <iostream>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

queue<int> modifyQueue(queue<int> q) {
    stack<int> st;
    int k = 3;

    // Step 1: Dequeue first k elements and push them onto the stack
    for (int i = 0; i < k && !q.empty(); i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue the elements from the stack back to the queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move the remaining elements (if any) to the back of the queue
    int size = q.size();
    for (int i = 0; i < size - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main(){
    deque<int> dq = {1, 2, 3, 4, 5};
    queue<int> q(dq);

    queue<int> q1 = modifyQueue(q);

    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }

    return 0;
}