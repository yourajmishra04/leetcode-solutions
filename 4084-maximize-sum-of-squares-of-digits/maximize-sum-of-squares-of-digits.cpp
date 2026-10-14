class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum) return "";
        string ans;
        while(sum>0){
            ans.push_back((sum>=9)?'0'+9:'0'+sum);
            sum-=ans.back()-'0';
            
        }
        while(ans.size()<num){
            ans.push_back('0');
        }
        return ans;
    }
};