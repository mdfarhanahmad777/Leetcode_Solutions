class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        int start = 0;
        int end = n-1;

        if (n==1) return nums[0];

        int mid;

        while(start<=end)
        {
            mid = start + (end-start)/2;
            if (mid>0 && nums[mid]==nums[mid-1])
            {
                if((mid-1-start)%2 != 0)
                {
                    end = mid-2;
                }
                else
                {
                    start = mid+1;
                }
            }
            else if (mid <n-1 && nums[mid]==nums[mid+1])
            {
                if((end - mid -1)%2 != 0)
                {
                    start = mid+2;
                }
                else
                {
                    end = mid-1;
                }
            }
            else
            {
                return nums[mid];
            }
        }

        return nums[start];
        
    }
};