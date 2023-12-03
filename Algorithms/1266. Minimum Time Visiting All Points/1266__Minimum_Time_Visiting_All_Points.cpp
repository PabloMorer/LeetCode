#include<iostream>
#include<vector>
#include <stdlib.h>  
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int i = 1;
        int cont = 0;
        for (int i = 1; i < points.size(); i++) {

            int x = abs(points[i][0] - points[i - 1][0]);
            int y = abs(points[i][1] - points[i - 1][1]);

            cont += max(x, y);
        }

        return cont;
    }
};
