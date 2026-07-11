class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        int n= nums.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            int rem = target - nums[i];
            if(mpp.find(rem)!=mpp.end()){
                res.push_back(i);
                res.push_back(mpp[rem]);
            }else{
                mpp[nums[i]]=i;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
