class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int parts = 1;
        long long curr = 0;

        for (int num : nums) {
            if (curr + num > maxSum) {
                parts++;
                curr = num;
            } else {
                curr += num;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};