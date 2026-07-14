class Solution {
public:
    std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat) {
        std::vector<int> ans(2);
        int maxi = INT_MIN;

        for (size_t i = 0; i < mat.size(); i++) {
            for (size_t j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] > maxi) {
                    maxi = mat[i][j];
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }

        return ans;
    }
};