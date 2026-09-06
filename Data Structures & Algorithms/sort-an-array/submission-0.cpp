class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>minpq;
        for(int num: nums){
            minpq.push(num);
        }
        vector<int>arr;
        while(!minpq.empty()){
            arr.push_back(minpq.top());
            minpq.pop();
        }
        return arr;
    }
};