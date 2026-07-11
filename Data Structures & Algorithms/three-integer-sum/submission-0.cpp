class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1;
            int r=n-1;
            int target=-nums[i];
            while(l<r){
                int sum= nums[l]+nums[r];
                if(target==sum){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[r]==nums[r+1]) r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                }
                else if(sum>target){
                    r--;
                }else{
                    l++;
                }
            }

        }
        return res;
    }
};
