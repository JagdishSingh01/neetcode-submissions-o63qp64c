class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mpp;
        int len=0,maxf=0,maxlen=0,l=0,r=0;
        while(r<s.length()){
            mpp[s[r]]++;
            len=r-l+1;
            maxf = max(maxf, mpp[s[r]]);
            if(len-maxf>k){
                mpp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
