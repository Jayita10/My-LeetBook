class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int x = 0, y = 0;
        
        for(int i=0;i<n;i++){
            if(moves[i] == 'U') y++;
            if(moves[i] == 'D') y--;
            if(moves[i] == 'L') x--;
            if(moves[i] == 'R') x++;
        }
        
        return (y == 0 && x == 0);
    }
};