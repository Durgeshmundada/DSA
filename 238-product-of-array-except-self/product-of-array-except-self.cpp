class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int x = nums.size();
        vector<int> res(x, 0); // Initialize result vector of size `x` with zeros
        int c = 1, zero_count = 0, zero_index = -1;

        // Step 1: Compute product of all non-zero elements and count zeros
        for (int i = 0; i < x; i++) {
            if (nums[i] != 0) {
                c *= nums[i];  // Multiply non-zero elements
            } else {
                zero_index = i;  // Store the index of the zero
                zero_count++;    // Count the number of zeros
            }
        }

        // Step 2: Handle cases based on zero count
        if (zero_count > 1) {
            return res;  // More than one zero -> all elements remain 0
        } else if (zero_count == 1) {
            res[zero_index] = c;  // If exactly one zero, only that position gets `c`
        } else {
            for (int i = 0; i < x; i++) {
                res[i] = c / nums[i];  // No zeros -> normal division
            }
        }

        return res;
    }
};