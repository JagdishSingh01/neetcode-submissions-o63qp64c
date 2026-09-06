class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>mpp;
        int n = nums.size();
        // store freq
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        // make frequency array where index will indicate freq
        vector<vector<int>>freq(n+1);
        for(auto it: mpp){
            freq[it.second].push_back(it.first);
        }
        
        // get top k frequent
        vector<int>ans;
        for(int i=n; i>=0; i--){
            while(!freq[i].empty()){
                ans.push_back(freq[i].back());
                freq[i].pop_back();
                k--;
                if(k==0) return ans;
            }

        }
        return ans;

    }
};
