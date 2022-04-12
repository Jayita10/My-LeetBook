class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> m;
        for(auto i : jewels){
            m[i]++;
        }
        int ans = 0;
        for(auto k : stones){
            if(m.find(k) != m.end()) ans++;
        }
        return ans;
    }
};