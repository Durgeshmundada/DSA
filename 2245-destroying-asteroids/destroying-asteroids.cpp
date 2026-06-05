class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long sub=0;
        for(int i=0;i<asteroids.size();i++){
            if(mass>=asteroids[i]-sub){
                sub+=asteroids[i];
            }
            else{
                mass=0;
                break;
            }
        }
        if(mass) return true;
        return false;
    }
};