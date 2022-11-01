//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisJointSet{
  vector<int> parent, rank, size; 
  public:
  
  DisJointSet(int n){
      rank.resize(n+1, 0);
      size.resize(n+1, 1);
      parent.resize(n+1);
      
      for(int i=0;i<=n;i++){
          parent[i] = i;
      }
  }
  
  int findParent(int node){
      if(parent[node] == node) return node;
      
      return parent[node] = findParent(parent[node]);
  }
  
  void unionByRank(int u, int v){
      int ulp_u = findParent(u);
      int ulp_v = findParent(v);
      
      if(ulp_u == ulp_v) return;
      
      if(rank[ulp_u] < rank[ulp_v]){
          parent[ulp_u] = ulp_v;
      }
      else if(rank[ulp_u] > rank[ulp_v]){
          parent[ulp_v] = ulp_u;
      }
      else{
          parent[ulp_v] = ulp_u;
          rank[ulp_u]++;
      }
  }
  
  void unionBySize(int u, int v){
      int ulp_u = findParent(u);
      int ulp_v = findParent(v);
      
      if(ulp_u == ulp_v) return;
      
      if(size[ulp_u] < size[ulp_v]){
          parent[ulp_u] = ulp_v;
          size[ulp_v] += size[ulp_u];
      }
      
      else{
          parent[ulp_v] = ulp_u;
          size[ulp_u] += size[ulp_v];
      }
  }
  
};


class Solution{
    int primAlgo(int V, vector<vector<int>> adj[]){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
            
            vector<int> vis(V, 0);
            pq.push({0,0});
            int sum = 0;
            
            // E log E + E log E
            while(!pq.empty()){
                // log E
                auto it = pq.top();
                pq.pop();
                
                int node = it.second;
                int wt = it.first;
                
                if(vis[node]) continue;
                vis[node] = 1;
                sum += wt;
                
                
                // E log E
                for(auto nbrs : adj[node]){
                    int nbr = nbrs[0];
                    int edgeWt = nbrs[1];
                    
                    if(!vis[nbr]){
                        // log E
                        pq.push({edgeWt, nbr});
                    }
                }
            }
        return sum;
    }


    int kruskalAlgo(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int, int>>> edges;
        
        for(int node=0;node<V;node++){
            for(auto it : adj[node]){
                int adjNode = it[0];
                int wt = it[1];
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        int wtSum = 0;
        DisJointSet ds(V);
        
        for(auto it : edges){
            int edgeWt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findParent(u) != ds.findParent(v)){
                wtSum += edgeWt;
                ds.unionBySize(u, v);
            }
        }
        return wtSum;
    }
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //return primAlgo(V, adj);
        return kruskalAlgo(V, adj);
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends