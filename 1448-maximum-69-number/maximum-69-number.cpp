class Solution {
public:
    int maximum69Number (int num) {
        int m=num;
       int s=num;
       string n=to_string(num);
       for(int i=0;i<n.size();i++){
        if(n[i]=='6'){
            n[i]='9';
            m=max(stoi(n),m);
            n[i]='6';
        }
        else{
            n[i]='6';
            m=max(stoi(n),m);
            n[i]='9';
        }
       }
       return m;
    }
};