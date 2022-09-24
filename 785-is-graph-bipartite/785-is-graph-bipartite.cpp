class Solution {
    bool bfs(int start, vector<vector<int>>& graph, int coloring[]){
        
        queue<int> q;
        q.push(start);
        coloring[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : graph[node]){
                if(coloring[it] == -1){
                    coloring[it] = !coloring[node];
                    q.push(it);
                }
                else if(coloring[it] == coloring[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        
        int coloring[v];
        for(int i=0;i<v;i++) coloring[i] = -1;
        
        for(int i=0;i<v;i++){
            if(coloring[i] == -1){
                if(bfs(i, graph, coloring) == false) return false;
            }
        }
        return true;
    }
};