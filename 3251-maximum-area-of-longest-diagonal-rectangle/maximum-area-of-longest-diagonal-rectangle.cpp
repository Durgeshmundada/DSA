class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        float m=0;
     float s=0;
        int idx=0;
        for(int i=0;i<n;i++){
           s= sqrt(dimensions[i][0]*dimensions[i][0] +dimensions[i][1]*dimensions[i][1]);
           
           if(s>m){
             idx=i; 
           }
           else if(s==m){
            if(dimensions[idx][0]*dimensions[idx][1]<dimensions[i][0]*dimensions[i][1]){
                idx=i;
            }
           }
           m=max(m,s);
        }
        return dimensions[idx][0]*dimensions[idx][1];
    }
};
/*class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int idx = 0;
        int maxDiag = dimensions[0][0]*dimensions[0][0] + dimensions[0][1]*dimensions[0][1];
        int maxArea = dimensions[0][0]*dimensions[0][1];

        for (int i = 1; i < n; i++) {
            int a = dimensions[i][0];
            int b = dimensions[i][1];
            int diag = a*a + b*b;
            int area = a*b;

            if (diag > maxDiag || (diag == maxDiag && area > maxArea)) {
                maxDiag = diag;
                maxArea = area;
                idx = i;
            }
        }

        return dimensions[idx][0] * dimensions[idx][1];
    }
};
*/