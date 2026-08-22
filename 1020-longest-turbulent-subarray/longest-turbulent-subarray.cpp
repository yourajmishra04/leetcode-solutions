class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        int n=arr.size();
        set<int>st;
        for(int x: arr) st.insert(x);
        
        if( st.size()==1)return 1;
        vector<int>pk(n,0);
        for(int i=1;i<n-1;i++){
            if((arr[i]>arr[i-1] && arr[i]>arr[i+1]) ||(arr[i]<arr[i-1] && arr[i]<arr[i+1])) pk[i]=1;
        }  

        int i=0,j,ans=0;
        while(i<n){
             while(i<n && pk[i]==0) i++;
             if(i>=n) break;
             j=i+1;
             while(j<n && pk[j]==1) j++;
             int len=j-i;
             if(i>0 && arr[i]!=arr[i-1]) len++;
             if(j<n && arr[j]!=arr[j-1]) len++;
             ans=max(ans,len);
             i=j;

        }
          if(ans==0) ans=2;

        return ans;

    } 
};