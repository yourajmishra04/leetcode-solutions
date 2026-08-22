class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, k=n,pro=1;
        while(k>0){
            int r=k%10;
        
            sum+=r;
            pro*=r;
            k/=10;
        }
        pro+=sum;
        if((n%pro)>0) return 0;
        return 1;
    }
};