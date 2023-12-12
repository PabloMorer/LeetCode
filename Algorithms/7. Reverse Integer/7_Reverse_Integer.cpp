#include<iostream>
#include <stdlib.h> 
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int x_aux = abs(x);
        int r = 0;
        while (x_aux > 0) {
            if ( r > INT32_MAX/10) {
                return 0;
            }
            r *= 10;
            r += x_aux % 10;
            x_aux /= 10;
        }
        if (x < 0) {
            r *= -1;
        }

        return r;
    }
};
