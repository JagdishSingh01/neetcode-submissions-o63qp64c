class Solution {
public:
    void recurr(int i, int n, int k, vector<int>& temp, vector<vector<int>>& res){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        if(temp.size()>k) return ;
        for(int j=i; j<=n; j++){
            temp.push_back(j);
            recurr(j+1, n, k, temp, res);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>res;
        recurr(1,n, k, temp, res);
        return res;
    }
};