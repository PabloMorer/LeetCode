#include<iostream>

using namespace std;
class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        bool positive = true;
        int ret = 0;
        while (s[i] == ' ') {
            i++;
        }
        s = s.substr(i, s.size() - i);
        i = 0;
        if (s[i] == '-') {
            i++;
            positive = false;
        }
        else if (s[i] == '+') {
            i++;
        }
        while (i < s.size() && isdigit(s[i])) {
            int d = s[i] - '0';
            if (ret > (INT_MAX - d) / 10) {
                if (positive) {
                    return INT_MAX;
                }
                return INT_MIN;
            }
            ret *= 10;
            ret += d;
            i++;
        }

        if (positive) {
            return ret;
        }
        else {
            return ret*=-1;
        }
        
    }
};
