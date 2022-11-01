class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int x = 0, y = 0;
        
        int u = 0, d = 0, l = 0, r = 0;
        for(int i=0;i<n;i++){
            if(moves[i] == 'U') y++;
            if(moves[i] == 'D') y--;
            if(moves[i] == 'L') x--;
            if(moves[i] == 'R') x++;
        }
        
        if(y == 0 && x == 0) return true;
        return false;
    }
};