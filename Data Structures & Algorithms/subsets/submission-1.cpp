class Solution {
public:
    void recurr(vector<int>&nums, vector<int>&temp, vector<vector<int>>& res, int i){
        res.push_back(temp);
        for(int j=i; j<nums.size(); j++){
            temp.push_back(nums[j]);
            recurr(nums, temp, res, j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        recurr(nums, temp, res, 0);
        return res;
    }
};
