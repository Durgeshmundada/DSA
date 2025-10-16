class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            int rem = ((nums[i] % value) + value) % value;
            freq[rem]++;
        }
       int x=0;
        while(true){
            if(freq[x%value]!=0){
                freq[x%value]--;
                x++;
                
            }
            else{
                return x;
            }
        }
        return x;
    }
};