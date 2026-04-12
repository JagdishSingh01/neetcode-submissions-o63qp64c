class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int>mpp;
        
        for(int i =0; i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                return true;
            }
            mpp[nums[i]]++;
        }
        return false;
    }
};