class Solution {
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, int u){
        path.push_back(u);
        
        if(u == graph.size()-1) 
            ans.push_back(path);
        else{
            for(auto v : graph[u]){
                dfs(graph, ans, path, v);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(graph, ans, path, 0);
        return ans;
    }
};