class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()){
           return addBinary(b,a);
        }
        int carry=0;
        int s=a.size()-1;
        for(int i=b.size()-1;i>=0;i--){
            if(a[s]=='1' && b[i]=='1'){
                if(carry){
                    b[i]='1';
                }
                else{
                    b[i]='0';
                    carry=1;
                }
            }
            else if(a[s]=='0' && b[i]=='0'){
                if(carry){
                    b[i]='1';
                    carry=0;
                }
                else{
                    b[i]='0';
                }
            }
            else{
                if (carry) {
                    b[i] = '0';
                    carry = 1;
                } else {
                    b[i] = '1';
                    carry = 0;
                }
            }
            s--;
        }
        int n=s;
while (carry && s >= 0){
    
        if(a[s]=='1'){
           a[s]='0';
        }
        else{
            a[s]='1';
            carry=0;
        }
    s--;

}
if(s >= 0){
            return a.substr(0, n+1) + b;
        }
        else if(carry == 0 && s < 0){
           return a.substr(0, n+1) + b;
        }
        else{
            return "1" + a.substr(0, n+1) + b; // changed '1' to "1"
        }
    }
};