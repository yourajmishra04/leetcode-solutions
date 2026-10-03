class Solution:
    def frequencySort(self, s: str) -> str:
        mp = {}

        for ch in s:
            mp[ch] = mp.get(ch, 0) + 1

        fre = []

        for ch in mp:
            fre.append([mp[ch], ch])

        fre.sort(reverse=True)

        ans = ""

        
        for freq, ch in fre:
            ans += ch * freq
        return ans
