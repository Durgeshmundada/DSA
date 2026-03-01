class Solution {
public:
    int minPartitions(string n) {
        int ma=INT_MIN;
        for(int i=0;i<n.size();i++){
            ma=max(ma,(int)(n[i]-'0'));
        }
        return ma;
    }
};