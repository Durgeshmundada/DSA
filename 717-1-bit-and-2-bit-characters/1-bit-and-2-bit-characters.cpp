class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
       bool check=true;
       for(int i=0;i<bits.size()-1;i++){
           if(check==false){
            check=true;
           }
           else if(bits[i]==1){
               check=false;
           }
       }
       return check;
    }
};