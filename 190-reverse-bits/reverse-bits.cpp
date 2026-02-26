class Solution {
public:
    int reverseBits(int n) {
      vector<int> result(32,0);
      no(result,n,0); 
      int val = 0;
for (int b : result) {
    val = (val << 1) | b;
} 
return val;
    }
    void no(vector<int>& result,int n, int count){
        if(n==0){
            return;
        }
        if(n%2==0){
            result[count]=0;
        }
        else{
            result[count]=1;
        }
        count++; 
        no(result,n>>1,count);
    }
};