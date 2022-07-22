class Solution {
    vector<char> reverse(vector<char>& s, vector<char>& temp, int idx){
        if(idx == 0){
            temp.push_back(s[0]);
            return temp;
        }
        temp.push_back(s[idx]);
        return reverse(s,temp,idx-1);
    }
public:
    void reverseString(vector<char>& s) {
        vector<char> temp;
        int n = s.size();
        s = reverse(s,temp,n-1);
    }
};