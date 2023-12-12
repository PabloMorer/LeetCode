#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        vector<string> v(numRows, "");
        bool direction = false; // true = down, false = up
        int j = 0;
        for (int i = 0; i < s.length(); i++) {

            if (j == 0 || j == numRows - 1) {
                direction = !direction;
            }
            v.at(j) += s.at(i);
            if (direction) {
                j++;
            }
            else {
                j--;
            }
        }

        string r = "";
        for (auto& a : v) {
            r += a;
        }

        return r;
    }
};
