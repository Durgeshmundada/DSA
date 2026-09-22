class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& nums) {
        for(int i=0;i<nums.size();i++){
            int left=0;
            int right=nums[i].size()-1;
            while(left<right){
                int mid=left+(right-left)/2;
                
                if(nums[i][mid]<nums[i][mid+1]){
                    left=mid+1;
                }
                else{
                    right=mid;
                }
            }
            if(i==0){
                if(i+1==nums.size()) return {i,left};
                if(nums[i+1][left]<nums[i][left]) return {i,left};
            }
            else if(i==nums.size()-1){
                if(i==0) return {i,left};
                if(nums[i-1][left]<nums[i][left]) return {i,left};
            }
            else{
                if(nums[i+1][left]<nums[i][left] && nums[i-1][left]<nums[i][left]) return {i,left};
            }
        }
        for (int j = 0; j < nums[0].size(); j++) {

    int top = 0;
    int bottom = nums.size() - 1;

    while (top < bottom) {

        int mid = top + (bottom - top) / 2;

        if (nums[mid][j] < nums[mid + 1][j]) {
            top = mid + 1;
        }
        else {
            bottom = mid;
        }
    }


    if (j == 0) {

        if (j + 1 == nums[0].size())
            return {top, j};

      
        if (nums[top][j + 1] < nums[top][j])
            return {top, j};
    }

    else if (j == nums[0].size() - 1) {

        if (nums[top][j - 1] < nums[top][j])
            return {top, j};
    }

    else {

        if (nums[top][j - 1] < nums[top][j] &&
            nums[top][j + 1] < nums[top][j])
            return {top, j};
    }
}

        return {};
    }
};