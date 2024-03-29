//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private: 
    void dfs(int sr, int sc, int init_col, int newColor, vector<vector<int>>& image, 
    vector<vector<int>> &ans){
        int n = image.size();
        int m = image[0].size();
        ans[sr][sc] = newColor;
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        for(int i=0;i<4;i++){
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && image[nrow][ncol] == init_col && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, init_col, newColor, image, ans);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int init_col = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, init_col, newColor, image, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends