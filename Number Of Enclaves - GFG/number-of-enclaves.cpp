//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(int i, int j, vector<vector<int>> &temp, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        
        temp[i][j] = 0;
    
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, -1, 0, +1};
    
        for(int k=0;k<4;k++){
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];
    
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m  
             && grid[nrow][ncol] == 1 && temp[nrow][ncol] != 0){
                dfs(nrow, ncol, temp, grid);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
       int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> temp = grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1)
                        dfs(i, j, temp, grid);
                }  
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j] == 1) ans++;
            }
        }

        return ans;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends