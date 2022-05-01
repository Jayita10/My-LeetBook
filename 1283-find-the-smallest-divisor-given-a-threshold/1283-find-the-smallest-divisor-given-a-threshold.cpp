class Solution {
    // TC : N*log(search space) == N*log(max_element)
    
    int sumAfterDiv(int n, vector<int> &nums, int div){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (nums[i]/div);
            // 5/2...so we add 2 on above line, but need to add 1 more
            // for ceiling
            if(nums[i]%div != 0) 
                sum += 1;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        //need sum<=threshold
        //in which need to find the smallest divisor
        
        int n = nums.size();
        int low = 1;
        int high = 0;
        for(int i=0;i<n;i++){
            high = max(high,nums[i]);
        }
        int ans = high;
        while(low <= high){
            int mid = (high+low)/2;
            
            if(sumAfterDiv(n,nums,mid) <= threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};