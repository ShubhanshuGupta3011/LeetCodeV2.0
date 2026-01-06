class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        for (auto& top : words) {
            for (auto& left : words) {
                if (left == top)
                    continue;
                for (auto& right : words) {
                    if (right == top || right == left)
                        continue;
                    for (auto& bottom : words) {
                        if (bottom == top || bottom == left || bottom == right)
                            continue;
                        if (top[0] == left[0] &&
                            top[3] == right[0] &&
                            bottom[0] == left[3] &&
                            bottom[3] == right[3]) {
                            ans.push_back({top, left, right, bottom});
                        }
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};