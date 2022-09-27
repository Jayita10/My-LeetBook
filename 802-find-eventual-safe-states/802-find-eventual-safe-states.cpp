class Solution {
    bool dfsCycle(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : graph[node]){
            if(!vis[it]){
               if(dfsCycle(it, graph, vis, pathVis)) return true;
            }
            if(pathVis[it]) return true;
        }
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfsCycle(i, graph, vis, pathVis);
        }
        
        for(int i=0;i<n;i++){
            if(pathVis[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};