#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> indices;
		for(int i = 0; i < nums.size(); i++) {
			for(int j = 0; j < nums.size(); j++) {
        if(i != j && nums[i] + nums[j] == target) {
          indices.push_back(i);
          indices.push_back(j);
          return indices;
        }
			}
		}
    return indices;
	}
  
  vector<int> twoSumV2(vector<int>& nums, int target) {
    vector<int> ret = vector<int>(2);
    unordered_map<int,int> m;
    for(int i = 0; i < nums.size(); i++) {
      if(m.find(nums[i]) == m.end()) {
        m.insert(make_pair(nums[i],i));
        if(m.find(target-nums[i]) != m.end() && m.find(target-nums[i])->second != i) {
          ret[0] = m.find(target - nums[i]) -> second;
          ret[1] = i;
          break;
        }
      } else if (nums[i] * 2 == target) {
        ret[0] = m.find(nums[i])->second;
        ret[1] = i;
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution s;
  vector<int> v = {2,7,11,15};
  vector<int> indices = s.twoSum(v, 9);
  for(int i: indices) {
    cout << i << endl;
  }
  indices = s.twoSumV2(v, 9);
  for(int i: indices) {
    cout << i << endl;
  }
}
