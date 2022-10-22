class Solution { 
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        int cnt = 0;
        vector<bool> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i, isConnected, vis);
            }
        }
        
        return cnt;
    }
    
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis){
        vis[node] = 1;
        
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i] && isConnected[node][i] == 1){
                dfs(i,isConnected,vis);
            }
        }
    }
};