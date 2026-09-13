class Solution {
public:
    vector<int> sortArray(vector<int>& nums){
        sort(nums,0 , nums.size()-1);
        return nums;
    }
    void merge(vector<int>& arr, int left, int mid, int right){
        vector<int> leftArr(arr.begin()+left, arr.begin()+mid+1);
        vector<int> rightArr(arr.begin()+mid+1, arr.begin()+right+1);
        int i = 0, j = 0, k = left;
        while(i < leftArr.size() && j < rightArr.size()){
            if(leftArr[i] < rightArr[j]){
                arr[k] = leftArr[i];
                i++;
            }
            else{
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        while(i < leftArr.size()){
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        while(j < rightArr.size()){
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    void sort(vector<int>& arr, int left, int right){
        if(left >= right)return;
        int mid = left + (right-left)/2;
        sort(arr, left, mid);
        sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
};