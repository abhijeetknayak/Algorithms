int firstBadVersion(int n) {
    bool bad = false;
    int low = 1, mid, high = n;

    while (low < high) {
        mid = low + (high - low) / 2;
        bad = isBadVersion(mid);
        if (bad == true) high = mid;
        else low = mid + 1;
    }
    return low;
}
