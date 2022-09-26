class Solution {
    bool dfsCycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCycle(it, adj, vis, pathVis) == true) return true;
            }
            else if(pathVis[it]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        // dfs
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        for(int i=0;i<n;i++){
            if(!vis[i])
                if(dfsCycle(i, adj, vis, pathVis) == true) return false;
        }
        return true;
    }
};