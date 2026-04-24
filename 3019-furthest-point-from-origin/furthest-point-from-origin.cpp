class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0;
        int r=0;
        int ex=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L') l++;
            if(moves[i]=='R') r++;
            if(moves[i]=='_') ex++;
        }
        int mi=min(l,r);
        int ma=max(l,r);
        return ma-mi+ex;
    }
};