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
        int n = s.size();
        int l = 0, r = n-1;
        while(l <= r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        
    }
};