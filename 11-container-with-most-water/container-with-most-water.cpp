class Solution {
public:
    int maxArea(vector<int>& height) {
       int max1=0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
         
            max1=max(max1,(min(height[left],height[right])*(right-left)));
         
         if (height[left] < height[right])
                left++;
            else
                right--;
       } 
       return max1;
    }
};