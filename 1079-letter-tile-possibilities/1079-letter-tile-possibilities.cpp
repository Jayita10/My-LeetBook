class Solution {
    void dfs(string tiles, string s, map<int, int> flag, set<string>& ans){
        for(int i=0;i<tiles.size();i++){
            if(flag[i] != 1){
                s.push_back(tiles[i]);
                flag[i] = 1;
                ans.insert(s);
                dfs(tiles,s, flag, ans);
                flag[i] = 0;
                s.pop_back();
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        set<string> ans;
        map<int, int> flag;
        string s;
        dfs(tiles, s, flag, ans);
         
        return ans.size();
    }
};