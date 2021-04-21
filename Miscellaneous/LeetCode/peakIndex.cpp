    int peakIndexInMountainArray(vector<int>& arr) {
        bool peak = false;
        int i = 1;
        while(i < arr.size() - 1) {
            peak = arr[i] > arr[i - 1] && arr[i] > arr[i + 1];
            if (peak) return i;
            else i = i + 1;
        }
        if (!peak) return -1;
        else return i;
    } /* O(n) solution */

    int peakIndexInMountainArrayNew(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[mid + 1]) low = mid + 1;
            else high = mid;
        }
        return low;
    } /* O(logn) solution */

