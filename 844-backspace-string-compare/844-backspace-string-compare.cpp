class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ptr1 = 0;
        int ptr2 = 0;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '#'){
                ptr1--;
                ptr1 = max(0,ptr1);
            }
            else{
                s[ptr1++] = s[i];
            }
        }
        
        for(int i=0;i<t.size();i++){
            if(t[i] == '#'){
                ptr2--;
                ptr2 = max(0,ptr2);
            }
            else{
                t[ptr2++] = t[i];
            }
        }
        if(ptr1 != ptr2) return false;
        for(int i=0;i<ptr1;i++){
            if(s[i] != t[i]) return false;
        }
        return true;
    }
};