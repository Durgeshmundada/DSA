class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       sort(potions.begin(),potions.end());
        vector<int>result;
        for(int i=0;i<spells.size();i++){
            int left=0;
            int right=potions.size()-1;
            int j=potions.size();
            while(left<=right){
                
                int mid = left + (right - left) / 2;
                long long product = (long long)spells[i] * potions[mid];
                if(product>=success){
                    j=mid;
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            result.push_back(potions.size() -j);
        }
        return result;
    }
};