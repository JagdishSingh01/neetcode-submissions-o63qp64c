class Solution {
public:
    void heapify(vector<int>& arr,int n, int i){
        int largest = i;
        int left = 2*i +1; 
        int right = 2*i +2;
        if(left<n && arr[largest]< arr[left]){
            largest = left;
        }
        if(right<n && arr[largest]< arr[right]){
            largest = right;
        }
        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // heap creation
        for(int i=n/2 - 1; i>=0; i--){
            heapify(nums, n, i);
        }
        while(n--){
            swap(nums[0], nums[n]);
            heapify(nums, n, 0);
        }
        return nums;
        

    }
};




