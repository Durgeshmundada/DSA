class Solution {
public:
    vector<int> rotateElements(vector<int>& arr, int k) {
        vector<int> nums;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= 0)
                nums.push_back(arr[i]);
        }

        if(nums.size() > 0) {
            k %= nums.size();
            reverse(nums, 0, k - 1);
            reverse(nums, k, nums.size() - 1);
            reverse(nums, 0, nums.size() - 1);
        }

        int j = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= 0)
                arr[i] = nums[j++];
        }

        return arr;
    }

private:
    void reverse(vector<int>& nums, int l, int r) {
        while(l < r)
            swap(nums[l++], nums[r--]);
    }
};