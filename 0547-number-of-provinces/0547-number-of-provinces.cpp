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

class Solution { 
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis){
        vis[node] = 1;
        
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i] && isConnected[node][i] == 1){
                dfs(i,isConnected,vis);
            }
        }
    }
    
    int usingDFS(vector<vector<int>>& isConnected){
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
    
    int usingDSU(vector<vector<int>>& isConnected){
        int V = isConnected.size();
        int cnt = 0;
        
        DisJointSet ds(V);
        
        for(int node=0; node<V; node++){
            for(int adjNode=0; adjNode<V; adjNode++){
                if(isConnected[node][adjNode] == 1){
                    ds.unionBySize(node, adjNode);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(ds.findParent(i) == i)
                cnt++;
        }
        return cnt;
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //return usingDFS(isConnected);
        return usingDSU(isConnected);
    }
};