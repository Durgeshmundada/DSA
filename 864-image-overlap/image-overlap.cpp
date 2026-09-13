class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>> imge1;
        vector<vector<int>> imge2;

        int n = img1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    imge1.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img2[i][j] == 1) {
                    imge2.push_back({i, j});
                }
            }
        }

        int result = 0;

        for (int i = -(n - 1); i <= n - 1; i++) {
            for (int j = -(n - 1); j <= n - 1; j++) {

                vector<vector<int>> imgee1 = imge1;

                for (int z = 0; z < imgee1.size(); z++) {
                    imgee1[z][0] += i;
                    imgee1[z][1] += j;
                }

                int count = 0;

                for (int z = 0; z < imgee1.size(); z++) {
                    int x = imgee1[z][0];
                    int y = imgee1[z][1];

                    if (x >= 0 && x < n &&
                        y >= 0 && y < n) {

                        if (img2[x][y] == 1) {
                            count++;
                        }
                    }
                }

                result = max(result, count);
            }
        }

        return result;
    }
};