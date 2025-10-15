class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev = 0, curr = 1, max1 = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                curr++;
            } else {
                if (prev > 1){
                    max1 = max(max1, min(curr, prev));
                     max1 = max(max1, max(curr, prev) / 2);}
                else{
                    max1 = max(max1, curr / 2);
                }
               
                prev = curr;
                curr = 1;
            }
        }

        max1 = max(max1, min(curr, prev));
        max1 = max(max1, max(curr, prev) / 2);
        if (max1 == 0) max1 = 1;
        return max1;
    }
};
