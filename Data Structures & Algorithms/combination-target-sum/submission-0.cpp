class Solution {
public:
    void recurr(int i, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& res, int sum){
        int num = candidates[i];
        sum+=num;
        temp.push_back(num);
        if(sum==target){
            res.push_back(temp);
            temp.pop_back();
            sum-=num;
            return;
        }
        else if(sum>target){
            temp.pop_back();
            sum-=num;
            return;
        } 
        int n =candidates.size();
        for(int j =i; j<n; j++){
            if(sum+candidates[j]<=target)recurr(j, candidates,target,temp, res, sum);
        }
        temp.pop_back();
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n=candidates.size();
        for(int i =0; i<n; i++){
            vector<int>temp;
            if(candidates[i]<=target) recurr(i, candidates,target,temp, res, 0);
        }
        return res;
    }
};
