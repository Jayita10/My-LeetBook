class Solution {
    void solve(string digits, string path, int idx, unordered_map<char, string> m, vector<string>& ans){
        
        if(idx == digits.size()){
            ans.push_back(path);
            return;
        }
        string currStr = m[digits[idx]];
        for(auto c : currStr){
            path.push_back(c);
            solve(digits, path, idx+1, m, ans);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        
        unordered_map<char, string> m = {
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}
        };
        
        string path = "";
        solve(digits, path, 0, m, ans);
        
        return ans;
    }
};