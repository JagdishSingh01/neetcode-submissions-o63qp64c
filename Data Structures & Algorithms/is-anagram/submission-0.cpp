class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        map<int, int>mpp;
        for(int i =0; i<s.length(); i++){
            mpp[s[i]-'a']++;
            mpp[t[i]-'a']--;
            if(mpp[s[i]-'a']==0) mpp.erase(s[i]-'a');
            if(mpp[t[i]-'a']==0) mpp.erase(t[i]-'a');
        }
        if(mpp.size()==0) return true;
        return false;
    }
};
