#import <iostream>
#import <vector>
#import <algorithm>

using namespace std;

class Solution {
public:
  // O(n) time
  // O(1) space
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    int maxRow = n;
    int maxCol = m;
    for(vector<int> v : ops) {
      maxRow = min(maxRow, v[1]);
      maxCol = min(maxCol, v[0]);
    }
    return maxRow * maxCol;
  }
};

int main() {
  Solution s;
  vector<int> v1 = {9,5};
  vector<int> v2 = {6,8};
  vector<vector<int>> v = {v1, v2};
  cout << s.maxCount(10, 10, v);
}
