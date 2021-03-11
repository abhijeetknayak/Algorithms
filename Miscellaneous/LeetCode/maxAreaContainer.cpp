int maxArea(vector<int>& height) {
	int area = 0;
    int first = 0, last = height.size() - 1;
    while (first < last) {
    	area = max(area, min(height[first], height[last]) * (last - first));
    	if (height[first] <= height[last]) { first++; }
    	else { last--; }
    }
    return area;
}
