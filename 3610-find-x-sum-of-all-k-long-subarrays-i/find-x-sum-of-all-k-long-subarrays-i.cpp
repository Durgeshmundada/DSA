class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>result;
        
        for(int i=0;i<nums.size()-k+1;i++){
            map<int,int> um;
            int sum=0;
            int max1=0;
            for(int j=i;j<i+k;j++){
                um[nums[j]]++;
            }
            for(int j=0;j<x;j++){
                int max1_val = 0, max1_freq = 0;
            for (auto &p : um) {
                if (p.second > max1_freq || (p.second == max1_freq && p.first > max1_val)) {
                    max1_val = p.first;
                    max1_freq = p.second;
                }
            }

            sum += max1_val * max1_freq;

            // remove first max element so we can find 2nd max
            um[max1_val] = 0;
            }
            result.push_back(sum);
            
        }
        return result; 
    }
};