class Solution {
public:
    vector<int>getleftmax(vector<int>& height){
        int n=height.size();
        vector<int>leftmax(n);
        leftmax[0] = height[0];
        for(int i=1; i<n; i++){
            leftmax[i]= max(leftmax[i-1], height[i]);
        }
        return leftmax;
    }
    vector<int>getrightmax(vector<int>& height){
        int n=height.size();
        vector<int>rightmax(n);
        rightmax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightmax[i]= max(rightmax[i+1], height[i]);
        }
        return rightmax;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftmax = getleftmax(height);
        vector<int>rightmax = getrightmax(height);
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=min(leftmax[i], rightmax[i]) - height[i];
        }
        return sum;
    }
};
