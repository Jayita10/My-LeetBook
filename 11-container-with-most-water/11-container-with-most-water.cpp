class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int area = 0;
        
        while(left<right){
            int water = min(height[left],height[right])*(right-left);
            area = max(area,water);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};