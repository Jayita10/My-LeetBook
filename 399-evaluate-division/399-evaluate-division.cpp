class Solution {
public:
    double dfs(string src, string dst, unordered_set<string>& visited, unordered_map<string,vector<pair<string, double>>>& graph){
        
        if(graph.find(src) == graph.end()) return -1;
        if(src == dst) return 1;
        
        for(auto nbr : graph[src]){
            if(visited.count(nbr.first)) continue;
            visited.insert(nbr.first);
            double res = dfs(nbr.first,dst,visited,graph);
            if(res != -1) return res*nbr.second; 
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string, double>>> graph;
        int n = equations.size();
        
        for(int i=0;i<n;i++){
            string a = equations[i][0];
            string b = equations[i][1];
            
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, (double)1/val});
        }
        
        vector<double> res;
        for(auto query : queries){
            unordered_set<string> visited;
            double ans = dfs(query[0],query[1],visited,graph);
            res.push_back(ans);
        }
        return res;
    }
};