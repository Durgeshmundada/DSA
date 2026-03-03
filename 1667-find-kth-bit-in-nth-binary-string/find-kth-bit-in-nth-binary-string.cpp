class Solution {
public:
    char findKthBit(int n, int k) {
        int z=1;
        for(int i=1;i<k;i++){
            if(z>k){
                n=z/2-1;
                break;
            }
        }
        string result=find(n-1);
        cout<< result;
        return result[k-1];
    }
    string find(int n){
        if(n==0){
            return "0";
        }
       string s=find(n-1);
       string result=s+"1"+invertAndReverse(s);
       return result;
    }
    string invertAndReverse(string s) {
    
    for (char &c : s) {
        c = (c == '0') ? '1' : '0';
    } 
    reverse(s.begin(), s.end());

    return s;
}
};