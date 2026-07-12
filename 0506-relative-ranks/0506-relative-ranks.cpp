class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp(score.begin(), score.end());
        sort(temp.begin(), temp.end());
        vector<string> answer(score.size());
        int st = 0, mid = 0, end = 0;
        for (int i = 0; i < score.size(); ++i) {
            st = 0;
            end = score.size() - 1;
            while (st <= end) {
                mid = st + (end - st) / 2;
                if (temp[mid] == score[i]) {
                    mid = score.size() - mid;
                    if (mid == 1)
                        answer[i] = "Gold Medal";
                    else if (mid == 2)
                        answer[i] = "Silver Medal";
                    else if (mid == 3)
                        answer[i] = "Bronze Medal";
                    else
                        answer[i] = to_string(mid);
                    break;
                } else if (temp[mid] > score[i])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
        }
        return answer;
    }
};