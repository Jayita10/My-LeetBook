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
        
//         // dfs
//         vector<int> vis(n, 0);
//         vector<int> pathVis(n, 0);
//         for(int i=0;i<n;i++){
//             if(!vis[i])
//                 dfsCycle(i, graph, vis, pathVis);
//         }
        
//         for(int i=0;i<n;i++){
//             if(pathVis[i] == 0)
//                 ans.push_back(i);
//         }
        
          //bfs -> topo sort
        
        vector<int> adjRev[n];
        
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adjRev[node]){
                indegree[it]--;
                
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};