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
        for(int i=0;i<n/2;i++){
            swap(s[i],s[n-i-1]);
        }
        
    }
};