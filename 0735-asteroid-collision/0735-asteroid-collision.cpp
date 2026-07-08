class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int x : asteroids) {

            while (!st.empty() && st.top() > 0 && st.top() < -x)
                st.pop();

            if (!st.empty() && st.top() > 0 && st.top() == -x)
                st.pop();

            else if (st.empty() || st.top() < 0 || x > 0)
                st.push(x);
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};