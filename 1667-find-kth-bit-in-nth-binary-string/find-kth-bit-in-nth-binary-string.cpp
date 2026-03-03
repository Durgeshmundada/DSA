class Solution {
public:
    char findKthBit(int n, int k) {
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