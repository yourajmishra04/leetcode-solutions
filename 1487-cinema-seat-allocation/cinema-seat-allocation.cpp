class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>> mp;
      sort(reservedSeats.begin(),reservedSeats.end());
        int idx = 0, nn = reservedSeats.size(), j;
        while (idx < nn) {
            j = idx;
            vector<int> temp(11, 0);
            while (j<nn && reservedSeats[j][0] == reservedSeats[idx][0]) {
                temp[reservedSeats[j][1]] = 1;
                j++;
            }

            mp[reservedSeats[idx][0]] = temp;
            idx = j;
        }

        int ans = 0;
        for (auto it : mp) {

           
            vector<int> st = it.second;
            if (st[2] == 0 && st[3] == 0 && st[4] == 0 && st[5] == 0) {
                ans++;
                st

                    [2] = 1;
                st[3] = 1;
                st[4] = 1;
                st[5] = 1;
            }
            if (st[4] == 0 && st[5] == 0 && st[6] == 0 && st[7] == 0) {
                ans++;
                st[4] = 1;
                st[5] = 1;
                st[6] = 1;
                st[7] = 1;
            }
            if (st[6] == 0 && st[7] == 0 && st[8] == 0 && st[9] == 0) {
                ans++;
            }
        }
        int k=n-mp.size();
        ans+=(k*2);
        return ans;
    }
};