class Solution {
public:
    void recurr(int idx, string& curr,  string digits, vector<string>& alpha, vector<string>& res){
        if(curr.length()==digits.length()){
            res.push_back(curr);
            return;
        }
        if(curr.length()>digits.length()){
            return;
        }

        int ind= digits[idx]-'0';
        for(int j=0; j<alpha[ind].size(); j++){
            curr.push_back(alpha[ind][j]);
            recurr(idx+1, curr, digits, alpha, res);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string>alpha= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string curr="";       
        vector<string> res;
        recurr(0, curr, digits, alpha, res);
        return res;
    }
};
