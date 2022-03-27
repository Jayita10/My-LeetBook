class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        if(nums.empty()) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1; 
            int right = n-1;
            while(left < right){
                int two_sum = nums[left] + nums[right] + nums[i];
                
                if(two_sum > 0) right--;
                else if(two_sum < 0) left++;
                else{
                    vector<int> v(3,0);
                    v[0] = nums[i];
                    v[1] = nums[left];
                    v[2] = nums[right];
                    ans.push_back(v);
                    
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};