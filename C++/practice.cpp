#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  int arr[6] = {1, 2, 2, 1, 1, 3};
  map<int, int> m;
  bool a = false;
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    m[arr[i]]++;
  }
  set<int> s;
  for (auto val : m) {
    s.insert(val.second);
  }
  if (s.size() == m.size()) {
    a = true;
  }

  cout << a;
}