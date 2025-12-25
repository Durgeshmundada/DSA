class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> idx;
        vector<int> result(nums.size(),-1);
        for(int i=nums.size()-1;i>=0;i--){
            while(!idx.empty() && nums[idx.top()]<=nums[i] ){
                  idx.pop();
            }
            idx.push(i);
        }
        for(int i =nums.size() - 1; i >= 0; i--){
            while (!idx.empty() && nums[idx.top()] <= nums[i]) {
                idx.pop();
            }
           if(!idx.empty()){
            result[i]=nums[idx.top()];
           }
           idx.push(i);
        }
        
        return result;
    }
};