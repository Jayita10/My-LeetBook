class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        /**
        vector<int> ans;
        for(int i : nums){
            int x = i*i;            
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        return ans;
        **/
        
        vector<int> ans(n);
        int l = 0, r = n-1;
        for(int i=n-1;i>=0;i--){
            ans[i] = (abs(nums[l])>abs(nums[r]) ? nums[l]*nums[l++] : nums[r]*nums[r--]);
        }
        return ans;
        
    }
};