#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxim;
        int second_max;
        int a = 0;
        int b = height.size() - 1;
        int area = 0;
        while (a < b) {
 
            area = max(area, min(height[a], height[b]) * abs((b - a)));
            if (height[a] < height[b]) {
                a++;
            }
            else {
                b--;
            }

        }
        return area;
    }
};
