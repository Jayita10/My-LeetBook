class Solution {
    void solve(string s, vector<string> &ans, int idx){
        string curr = s;
        if(idx == s.size()){
            ans.push_back(curr);
            return;
        }     
        
        if(isdigit(s[idx])) solve(curr, ans, idx+1);
        else{
            string temp = curr;
            if(s[idx] >= 65 && s[idx] <= 90){
                curr[idx] = tolower(s[idx]);
            }
            
            if(s[idx] >= 97 && s[idx] <= 122){
                curr[idx] = toupper(s[idx]);
            }
            
            solve(curr, ans, idx+1);
            solve(temp, ans, idx+1);
        }
        
//         if(isdigit(s[idx])){
//             curr.push_back(s[idx]);
//             solve(s,ans, idx+1, curr);
//         }
//         else{
//             string temp1 = curr;
//             temp1.push_back(tolower(s[idx]));
//             solve(s, ans, idx+1, temp1);
            
//             string temp2 = curr;
//             temp2.push_back(toupper(s[idx]));
//             solve(s, ans, idx+1, temp2);
//         }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string curr = "";
        solve(s, ans, 0);
        return ans;
    }
};