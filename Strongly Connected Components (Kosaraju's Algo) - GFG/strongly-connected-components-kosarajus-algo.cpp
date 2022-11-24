//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    void dfs_reverse(int node, vector<int>& vis, vector<int> adjT[]){
        vis[node] = 1;
        
        for(auto it : adjT[node]){
            if(!vis[it]){
                dfs_reverse(it, vis, adjT);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        // step1 : ranking the nodes acc to finishing time
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        // step2 : reverse the edge
        
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                // i -> it actual
                // it -> i reverse
                adjT[it].push_back(i);
            }
        }
        
        // step3 : do the dfs
        
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs_reverse(node, vis, adjT);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends