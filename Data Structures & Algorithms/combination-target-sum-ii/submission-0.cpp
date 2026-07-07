class Solution {
public:
    void recurr(int i, vector<int>& candidates, vector<vector<int>>& res, vector<int>& temp, int target){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int j=i; j<candidates.size(); j++){
            if(j!=i){
                if(candidates[j]==candidates[j-1]) continue;
            } 
            
            temp.push_back(candidates[j]);
            recurr(j+1, candidates, res, temp, target-candidates[j]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>temp;
        recurr(0, candidates, res, temp, target);
        return res;
    }
};
