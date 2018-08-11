/*
https://leetcode.com/contest/weekly-contest-96/problems/projection-area-of-3d-shapes/

On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.
Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
Now we view the projection of these cubes onto the xy, yz, and zx planes.
A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane. 
Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.
Return the total area of all three projections.

Input: [[1,0],[0,2]]
Output: 8
*/


class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int dim1=0, dim2=0, dim3=0;
        vector<int> temp_grid = grid[0];
        for(int i=0; i<grid.size(); i++){
            int max_val = 0;
            for(int j=0; j<grid[i].size();j++){
                if(grid[i][j] > 0)
                    dim1++;
                max_val = max(max_val, grid[i][j]);
                if(grid[i][j] > temp_grid[j])
                    temp_grid[j] = grid[i][j]; 
            }
            //dim1 += grid[i].size();
            dim2 += max_val;
            cout<<dim1<<"Here"<<dim2;
        }
        
        for(int i =0; i<temp_grid.size(); i++)
            dim3 +=temp_grid[i];    
        return dim1+dim2+dim3;
    }
};


//Better Solution

int projectionArea(const vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            int m = 0, n = 0;
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[i][j] > m) m = grid[i][j];
                if (grid[j][i] > n) n = grid[j][i];
                if (grid[i][j]) ++sum;
            }
            sum += m + n;
        }
        return sum;
    }
