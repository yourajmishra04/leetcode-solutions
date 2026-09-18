class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
       while(n>0){
         while(n>0 && n%5>0) n--;
          if(n<=0) return ans;
          int k = n/5;
          ans+=k;
          n=k;
       }
       return ans;
    }
};