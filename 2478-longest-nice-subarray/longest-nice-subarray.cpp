class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        int c = 0;
        int left=0;
        for (int i = 0; i < nums.size(); i++) {
            while((c&nums[i])!=0){
                c=c^nums[left];
                left++;
                count--;
            }
            count++;
            c=c|nums[i];
            ans = max(ans, count);
        }

        return ans;
    }
};