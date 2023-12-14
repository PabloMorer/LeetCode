#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(),0);
        vector<int> col(grid[0].size(),  0 );
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                rows[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        for (int i = 0; i < rows.size(); i++) {
            for (int j = 0; j < col.size(); j++) {
                grid[i][j] = 2 * (rows[i] + col[j]) - grid.size() - grid[0].size();
            }
        }



    }
};
