class Solution {
public:
    int maxRotateFunction(vector<int>& A) {

        long long sum = 0, F = 0;
        int n = A.size();

        for (int i = 0; i < n; i++) {
            sum += A[i];
            F += 1LL * i * A[i];
        }

        long long maxi = F;

        for (int i = n - 1; i >= 1; i--) {
            F = F + sum - 1LL * n * A[i];
            maxi = max(maxi, F);
        }

        return (int)maxi;
    }
};