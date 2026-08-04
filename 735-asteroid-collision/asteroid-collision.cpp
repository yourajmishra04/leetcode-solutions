class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int> ans;
        int n = as.size();
        ans.push_back(as[0]);
      

        int i = 1;
        while (i < n) {

            while (ans.size() > 0 && ans.back() > 0 && as[i] < 0 &&
                   ans.back() < abs(as[i]))
                ans.pop_back();

            if (ans.empty() || ans.back() < 0 || as[i]>0)
                ans.push_back(as[i]);

            else if (ans.back() + as[i] == 0) {
                ans.pop_back();
            }

            i++;
        }

        return ans;
    }
};