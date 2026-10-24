class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        mnth= [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        aa=int(arriveAlice[3:5])
        for i in range(int(arriveAlice[0:2])-1):
            aa+=mnth[i]
        la=int(leaveAlice[3:5])
        for i in range(int(leaveAlice[0:2])-1):
            la+=mnth[i]
        ab=int(arriveBob[3:5])
        for i in range(int(arriveBob[0:2])-1):
            ab+=mnth[i]
        lb=int(leaveBob[3:5])
        for i in range(int(leaveBob[0:2])-1):
            lb+=mnth[i]
        l=max(aa,ab)
        r=min(la,lb)
        if r-l+1 < 0 :
            return 0
        return r-l+1

        