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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        
        int extraConn = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            
            if(ds.findParent(u) == ds.findParent(v)){
                extraConn++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
        
        int rootPar = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i) == i) rootPar++;
        }
        
        int ans = rootPar - 1;
        if(extraConn >= ans) return ans;
        else return -1;
    }
};