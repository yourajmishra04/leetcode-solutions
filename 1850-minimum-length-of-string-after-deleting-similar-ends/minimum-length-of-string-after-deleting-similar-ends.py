class Solution:
    def minimumLength(self, s: str) -> int:
        n=len(s)
        i=0
        j=n-1
        while i < j :
            if s[i] != s[j] :
                break 
            ch=s[i]
            while s[i]== ch:
                if(i>= j ) :
                    break
                else :
                    i+=1
            if i==j:
                return 0
            while s[j]==ch :
                if j<= i:
                    break
                else :
                    j-=1
            
                
        return j-i+1
        