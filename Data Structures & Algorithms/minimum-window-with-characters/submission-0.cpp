class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>seen;
        for(char ch:t){
            seen[ch]++;
        }
        int l=0;
        int minlen= INT_MAX;
        int start = 0;
        int required=t.length();
        for(int r=0; r<s.length(); r++){
            if(seen[s[r]]>0){
                required--;
            } 
            seen[s[r]]--;   
            
            while(required==0){
                // update ans
                if((r-l+1)<minlen){
                    minlen=r-l+1;
                    start=l;
                }

                //remove s[l]
                seen[s[l]]++;

                if(seen[s[l]]>0){
                    required++;
                }
                l++;
            }
        }
        if(minlen==INT_MAX) return "";
        return s.substr(start,minlen);
    }
};