class Solution {
public:
    /**
    bool even(int n){
        int cnt = 0;
        while(n){
            cnt++;
            n /= 10; 
        }
        if(cnt%2 == 0)
            return true;
        else{
            return false;
        }
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(even(nums[i])){
                count++;
            }
        }
        return count;
    }
    **/
    
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            if(n>=10 && n<=99 || n>=1000 && n<=9999 || n == 100000){
                count++;
            }
        }
        return count;
    }
    
};