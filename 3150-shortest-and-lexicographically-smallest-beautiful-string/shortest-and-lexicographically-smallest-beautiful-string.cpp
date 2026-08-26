class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       vector<string>v;
       int n=s.size();
       int i=0 , j , temp;
       while(i<n){
        while(i<n && s[i]=='0') i++;
        temp=k;
        j=i;
        while(j<n && temp>0) {
            if(s[j]=='1') temp--;
            j++;
        }
        if(temp ==0) v.push_back(s.substr(i,j-i));

         i++;

       }

       sort(v.begin(),v.end() , [](const string& a, const string& b)  {
          if(a.size()!=b.size()) return a.size()<b.size();
          return a<b;
       }
       );
       if(v.empty()) return "";
       return v[0];

    }
};