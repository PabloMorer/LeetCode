#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator it;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int r = target - nums[i];
            it = map.find(r);
            if (it != map.end()) {
                return { map[r], i };
            }
            map.insert({ nums[i],i });
        }

        return {}; 
    }
};
