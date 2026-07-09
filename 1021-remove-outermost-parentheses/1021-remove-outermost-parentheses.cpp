class Solution {
public:
    string removeOuterParentheses(string s) {
        int sum = 0, start = 0, end = 0;
        string res;

        while (end < s.size()) {
            if (s[end] == '(')
                sum++;
            else
                sum--;

            if (sum == 0) {
                res += s.substr(start + 1, end - start - 1);
                start = end + 1;
            }

            end++;
        }

        return res;
    }
};