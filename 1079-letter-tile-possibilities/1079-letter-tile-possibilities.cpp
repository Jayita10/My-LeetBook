class Solution {
    void solve(string tiles, unordered_map<int, bool> &vis, string curr, set<string>& ans){
        
        if(curr.size() > tiles.size()) return;
        ans.insert(curr);
        
        for(int i=0;i<tiles.size();i++){
            if(vis[i]) continue;
            curr += tiles[i];
            vis[i] = true;
            solve(tiles, vis, curr, ans);
            
            curr.pop_back();
            vis[i] = false;
        }
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<int, bool> vis;
        string curr = "";
        set<string> ans;
        
        solve(tiles, vis, curr, ans);
        return ans.size()-1;
    }
};