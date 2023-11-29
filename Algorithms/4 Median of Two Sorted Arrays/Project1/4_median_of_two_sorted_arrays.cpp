
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums2.size(); i++) {
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(), nums1.end());
        return 0.5 * (nums1[(nums1.size() - 1) / 2] + nums1[nums1.size() / 2]);
    }
};


int main() {
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2, 7 };
    Solution s;
    cout << s.findMedianSortedArrays(v1, v2);
}