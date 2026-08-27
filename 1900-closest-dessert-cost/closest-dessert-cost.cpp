class Solution {
public:
    int ans;
    int n;
    int r;
    void solve(vector<int>& toppingCosts, int target, int curr, int idx) {
        int diff = abs(curr - target);

        if (diff < ans || (diff == ans && curr < r)) {
            ans = diff;
            r = curr;
        }
        if (curr > target || idx >= n) {
            return;
        }
        solve(toppingCosts, target, curr + toppingCosts[idx], idx + 1);
        solve(toppingCosts, target, curr, idx + 1);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts,
                    int target) {
        ans = INT_MAX;
        r = INT_MAX;
        n = toppingCosts.size();
        for (int i = 0; i < n; i++) {
            toppingCosts.push_back(toppingCosts[i]);
        }
        n = toppingCosts.size();
        sort(toppingCosts.begin(), toppingCosts.end());
        for (int x : baseCosts) {
            solve(toppingCosts, target, x, 0);
        }
        return r;
    }
};