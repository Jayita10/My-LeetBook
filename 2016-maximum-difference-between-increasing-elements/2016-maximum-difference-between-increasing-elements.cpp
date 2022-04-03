class Solution {
public:
    //exact similar to stock buy sell problem!
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int maxDiff = -1;
        int n = nums.size();
        
        for(int i=1;i<n;i++){
            int diff = nums[i] - mini;
            maxDiff = max(maxDiff, diff);
            mini = min(mini, nums[i]);
        }
        return (maxDiff == 0)? -1 : maxDiff; //as for duplicates, the val will be 0
    }
};