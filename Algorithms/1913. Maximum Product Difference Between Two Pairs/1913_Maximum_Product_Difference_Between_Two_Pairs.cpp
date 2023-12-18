#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MAX;
        int d = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (a <= nums[i]) {
                b = a;
                a = nums[i];
                idx_b = idx_a;
                idx_a = i;
            }
            else if (b < nums[i]) {
                b = nums[i];
                idx_b = i;
            }
            if (c >= nums[i]) {
                d = c;
                c = nums[i];
            }
            else if (d > nums[i]) {
                d = nums[i];
            }
        }
        
        return (a * b) - (c * d);
    }
};
