class Solution {
public:
    int maximumGap(vector<int>& nums) {
     int n = nums.size();
        if (n < 2) return 0;

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        if (mini == maxi) return 0;
        int bucketSize = max(1, (maxi - mini) / (n - 1));
        int bucketCount = (maxi - mini) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        for(auto x:nums){
            int idx = (x - mini) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], x);
            bucketMax[idx] = max(bucketMax[idx], x);

        }
        int maxGap = 0;
        int prevMax = mini;
        for(int i=0;i<bucketCount;i++){
             if (bucketMin[i] == INT_MAX) continue; 
              maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }
        return maxGap;
    }
};