class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
      double l=0,lsum=0, r=0,rsum=0;
        for(int i=0;i<n/2;i++){
                 if(num[i]=='?') l++;
                 else lsum+=num[i]-'0';
        }
        for(int i=n/2;i<n;i++){
             if(num[i]=='?') r++;
                 else rsum+=num[i]-'0';
        }

        if(l==r){

            if(lsum==rsum) return 0;
            return 1;

        }
        else if(l>r){

           l-=r;
           l*=4.5;
           if(l== (rsum-lsum)) return 0;
           return 1;
            


        }
        else{

            r-=l;
            r*=4.5;
            if(r==(lsum-rsum)) return 0;
            return 1;

        }
        
    }
};