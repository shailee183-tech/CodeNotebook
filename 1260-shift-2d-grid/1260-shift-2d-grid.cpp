class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col= grid[0].size();
        int sz = row*col;

        k = k % sz;

        vector<vector<int>> ans (row, vector<int>(col));
        for(int i = 0; i<row;i++){
            for(int j = 0; j<col; j++){
                int newIndex = i*col + j+k;
                int newRow = (newIndex/col) % row;
                int newCol = newIndex % col;

                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};