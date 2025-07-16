class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
        int i;
        int j;
        
        for(int i=0;i<nums1.size();i++){
            int a=-1;
            int z=-1;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    a=j;
                    break;
                }
            }
            
            if(a==-1){
                nums1[i]=a;
            }
            else if(a==nums2.size()-1){
                nums1[i]=-1;
            }
            else{
                for(int k=a;k<nums2.size();k++){
                    
                    if(nums1[i]<nums2[k]){
                        nums1[i]=nums2[k];
                        z=1;
                        break;
                    }
                    
                }if(z!=1){
                    nums1[i]=-1;
                }
            }
        }
        return nums1;
    }
};