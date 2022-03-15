class Solution {
    void recursion(vector<char> &s, int l, int r){
        if(l >= r)
            return;
        swap(s[l++], s[r--]);
        recursion(s,l,r);
    }
public:
    void reverseString(vector<char>& s) {
        recursion(s,0,s.size()-1);
    }
};