class Solution {
public:
   bool chk(int n , int t){
    int pro=1;
     while(n>0){
        pro*=n%10;
        n/=10;
     }
     if(pro% t >0) return 0;
     return 1;

   }
    int smallestNumber(int n, int t) {
         for(int i=n;i<=n+10 ; i++){
            if(chk(i,t)) return i;
         }
         return 1;
    }
};