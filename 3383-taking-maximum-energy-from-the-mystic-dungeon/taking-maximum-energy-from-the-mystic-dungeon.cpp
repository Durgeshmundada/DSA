class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int result=INT_MIN;
        for(int i=energy.size()-1;i>=0;i--){
          if(k+i<energy.size()){
            energy[i]+=energy[i+k];
          }
          result=max(result,energy[i]);
        }
        return result;
    }
};