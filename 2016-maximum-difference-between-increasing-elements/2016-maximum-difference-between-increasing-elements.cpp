class Solution {
public:
    //exact similar to stock buy sell problem!
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int maxDiff = -1;
        int n = nums.size();
        
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]) i++;
            else{
            int diff = nums[i] - mini;
            maxDiff = max(maxDiff, diff);
            mini = min(mini, nums[i]);
            }
        }
        return maxDiff;
    }
};