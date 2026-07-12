class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        long long ans=0;
        long long mul=1;

        for(int i=n-1; i>=0; i--){
            ans+= (mul*(columnTitle[i]-'A'+1));
            mul*=26;
        }
        return (int)ans;
    }
};