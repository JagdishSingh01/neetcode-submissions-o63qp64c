class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mpp;
        for(string str: strs){
            string temp= str;
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(str);
            
        }
        vector<vector<string>>ans;
        
        for(auto mp: mpp){
            ans.push_back(mp.second);
        }
        return ans;
    }
};
