class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> ans;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            ans.push_back(grid[i][j]);
        }
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> temp(m,vector<int>(n,0));
        for(int i=0;i<ans.size();i++)
        {
            int val=(i+k)%(m*n);
            int r=val/n;
            int c=val%n;
            temp[r][c]=ans[i];
        }
        return temp;
    }
};