class Solution:
    def evalRPN(self, tok: list[str]) -> int:
        st=[]
        n=len(tok)
        for i in range (n):
            if tok[i] != "*" and tok[i] != "/" and tok[i]!= "+" and tok[i] != "-" :
                st.append(tok[i])
                continue
            else :
                a=int(st[-1])
                st.pop()
                b=int(st[-1])
                st.pop()
                if tok[i]=="+":
                    st.append(a+b)
                elif tok[i]=="-" :
                    st.append(b-a)
                elif tok[i]=="*" :
                    st.append(a*b)
                else :
                    st.append(int(b/a))
        return int( st[-1])