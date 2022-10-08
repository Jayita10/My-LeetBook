class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stop > k) continue;
            for(auto it : adj[node]){
                int nbr = it.first;
                int edgeWt = it.second;
                
                if(cost + edgeWt < dist[nbr] && stop <= k){
                    dist[nbr] = cost + edgeWt;
                    q.push({stop+1, {nbr, dist[nbr]}});
                }
            }
        }
        
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};