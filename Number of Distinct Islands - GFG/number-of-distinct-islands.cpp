//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int, int>> &vec, int base_r, int base_c){
        
        
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        vec.push_back({row - base_r, col - base_c});
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};
        
        for(int i = 0; i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, grid, vec, base_r, base_c);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 1 && !vis[row][col]){
                    vector<pair<int, int>> vec;
                    dfs(row, col, vis, grid, vec, row, col);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends