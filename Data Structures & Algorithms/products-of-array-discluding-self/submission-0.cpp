class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod0=1, prod1=1, cnt=0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]!=0){
                prod1 *=nums[i];
            }
            if(nums[i]==0) cnt++;
            prod0 *=nums[i];
        }
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0 && cnt<2){
                ans.push_back(prod1);
            }else if(nums[i]==0 && cnt>1){
                ans.push_back(prod0);
            }else{
                ans.push_back(prod0/nums[i]);
            }
        }
        return ans;
    }
};
