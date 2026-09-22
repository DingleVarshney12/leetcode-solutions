class Solution {
    int binarySearch(vector<int>& arr,int key){
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i =0 ; i < arr.size();i++){
            int key = 2 * arr[i];
            int res = binarySearch(arr,key);
            if(res >= 0 && res != i) return true;

        }
        return false;
        
    }
};