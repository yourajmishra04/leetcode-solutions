class Solution {
public:
    int largestInteger(int n, int s) {
        int dig = s / n;
        if (dig > 9 || (dig == 9 && s % n != 0))
            return -1;

        string a = "";
        while (s > 0) {
            if (s <= 9) {
                a += s + '0';
                break;
            }

            else {
                a += 9 + '0';
                s -= 9;
            }
        }
         while(a.size()<n) a+='0';
        int ans=stoi(a);
           return ans;

    }
};