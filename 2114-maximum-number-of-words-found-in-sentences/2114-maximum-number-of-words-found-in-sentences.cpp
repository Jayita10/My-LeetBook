class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWord = 0;
        for(auto i : sentences){
            string s = i;
            int word = 1;
            for(auto j : s){
                if(j == ' ') word++;
            }
            maxWord = max(maxWord,word);
        }
        return maxWord;
    }
};