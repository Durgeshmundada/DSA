class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double x=0.0;
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                for(int k=j+1;k<p.size();k++){
                    double area= 0.5*abs(p[i][0]*(p[j][1]-p[k][1]) +
                                                    p[j][0]*(p[k][1]-p[i][1]) +
                                                    p[k][0]*(p[i][1]-p[j][1]));
                    x=max(x,area);
                }
            }
        }
        return x;
    }
};