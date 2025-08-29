class Solution {
public:
    int daysReq(vector<int>& weights, int cap) {
        int days = 1, load = 0;
        for (int w : weights) {
            if (load + w > cap) { 
                days++;
                load = w;

            } else {
                load += w;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin(), weights.end()); 
        int sum = accumulate(weights.begin(), weights.end(), 0);

        int low = maxi, high = sum, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            int requiredDays = daysReq(weights, mid);
            if (requiredDays <= days) {
                high = mid - 1;  // try smaller capacity
            } else {
                low = mid + 1;   // need bigger capacity
            }
        }
        return low;
    }
};
