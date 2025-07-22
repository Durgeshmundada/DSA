class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
          int low = 0;
    int high = arr.size() - 1;
    int result = -1;
vector<int> temp;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            high = mid - 1; // Search in the left half for the first occurrence
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else { // arr[mid] > target
            high = mid - 1;
        }
    } temp.push_back(result);
    if(result==-1){
    temp.push_back(result);
    return temp;
    }
    while(result+1<=arr.size()-1 && arr[temp[0]]==arr[result+1]){
        result++;
    }
    
    temp.push_back(result);
    
    return temp;
    }
};