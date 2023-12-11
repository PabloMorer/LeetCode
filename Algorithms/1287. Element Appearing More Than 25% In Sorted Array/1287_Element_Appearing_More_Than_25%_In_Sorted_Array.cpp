#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int q = arr.size() / 4;
        bool f = false;
        int i = 0;
        int r = arr[i];
        while (i < arr.size() - q ) {
            if (arr[i] == arr[i + q]) {
                r = arr[i];
                break;
            }
            i++;
        }

        return r;
    }

};
