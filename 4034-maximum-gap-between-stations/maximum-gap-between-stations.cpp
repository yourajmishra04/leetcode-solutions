class Solution {
public:
    int maximumGap(string sk, string st) {
        int n = sk.size(), m = st.size();
        if (n == 1)
            return 0;
        int ans = 0;
        vector<int> v(n, 0);
        int i = 0, j = 0;
        while (i < n) {
            if (sk[i] == st[j]) {
                v[i] = j;
                i++;
            }
            j++;
        }
        for (int i = 1; i < n; i++)
            ans = max(ans, v[i] - v[i - 1]);
        i = n - 1;
        j = m - 1;
        while (i >= 0) {
            if (sk[i] == st[j]) {
                v[i] = j;
                 if(i>0)ans = max(ans, v[i] - v[i - 1]);
                i--;

            }
            j--;
        }
           
        return ans;
    }
};