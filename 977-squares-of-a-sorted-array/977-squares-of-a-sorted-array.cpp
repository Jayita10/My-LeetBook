class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            ans[i] = (abs(nums[l])>abs(nums[r]) ? nums[l]*nums[l++] : nums[r]*nums[r--]);
        }
        return ans;
    }
};