class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int N= 1<<n;
        vector <int> ans;
        for(int i=0;i<N;i++)
            ans.push_back(start ^ (i^(i>>1)));
        return ans;
    }
};

    