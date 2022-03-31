class Solution {
private:
    bool validSplit(vector<int> &nums, int mid, int m){
        int split = 1;
        int sum = 0;
        for(int i : nums){
            sum += i;
            
            if(sum > mid){
                split++;
                sum = i;
            }
        }
        if(split <= m) return true;
        else{
            return false;
        }
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int maxi = INT_MIN, sum = 0;
        
        for(int i : nums){
            maxi = max(maxi,i);
            sum += i;
        }
        if(m == (nums.size())) return maxi;
        int low = maxi;
        int high = sum;
        
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(validSplit(nums,mid,m)){
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