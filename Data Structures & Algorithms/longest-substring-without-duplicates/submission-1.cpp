class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen;
        int n = s.length();
        if(n<=1)return n;
        int l=0;
        int mx = INT_MIN;
        for(int r=0; r<n; r++){
            while(seen.find(s[r])!=seen.end()){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            mx=max((r-l)+1, mx);
        }
        return mx;
    }
};
