class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        
        /** 
        !st Approach: TC: O(n*n) SC: O(1)

        int count = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] == nums[j])
                    count++;
            }
        }
        return count;
        
        2nd Approach: TC: O(nlogn), SC: O(1)
        
        sort(nums.begin(),nums.end());
        int count = 0;
        int i = 0;
        for(int j=1;j<n;j++){
            if(nums[j] == nums[i])
                count += j-i;
            else{
                i = j;
            }
        }
        return count;
        **/
        
        int freq[101] = {0};
        int count = 0;
        
        for(int i=0;i<n;i++){
            count += freq[nums[i]]++;
        }
        return count;
    } 
};