class Solution {
public:
    void recurr(vector<string>& res, int open, int close, int n, string s){
        if(open==n && close==n){
            res.push_back(s);
            return;
        }
        if(open<n) recurr(res, open+1, close, n, s+"(");
        if(close<open) recurr(res, open, close+1, n, s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        recurr(res, 1,0,n,"(");
        return res;
    }
};
