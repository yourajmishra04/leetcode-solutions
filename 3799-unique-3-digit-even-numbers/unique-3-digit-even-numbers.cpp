class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int ans = 0;

      
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            vector<int> need(10, 0);
            need[d1]++;
            need[d2]++;
            need[d3]++;

            if (need[d1] <= count[d1] && 
                need[d2] <= count[d2] && 
                need[d3] <= count[d3]) {
                ans++;
            }
        }

        return ans;
    }
};