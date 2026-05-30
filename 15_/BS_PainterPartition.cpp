#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &boards, int mid, int k, int n){
    int sum = 0;
    int painterCount = 1;

    for(int i = 0; i < n; i++){
        if(sum + boards[i] <= mid){
            sum += boards[i];
        }
        else{
            painterCount++;
            if( painterCount > k || boards[i] > mid){
                return false;
            }
            sum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{   
    int n = boards.size();

    if(k > n){
        return -1;
    }

    int s = 0;
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += boards[i];
    }

    int e = sum;
    int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e){
        if(isPossible(boards, mid, k, n)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;

    int ans = findLargestMinDistance(boards, k);
    cout << ans << endl;
}