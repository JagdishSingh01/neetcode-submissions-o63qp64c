class Solution {
public:
    void recurr(int i, vector<int>& nums, vector<vector<int>>& res, vector<int>& temp){
        res.push_back(temp);
        for(int j=i; j<nums.size(); j++){
            if(i!=j){
                if(nums[j]==nums[j-1]) continue;
            }
            temp.push_back(nums[j]);
            recurr(j+1, nums, res, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        recurr(0, nums, res, temp);
        return res;
    }
};
