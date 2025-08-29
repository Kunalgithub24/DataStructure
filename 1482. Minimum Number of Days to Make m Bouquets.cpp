class Solution {
public:
    int maxLimit(vector<int>& arr){
        int maxi = INT_MIN;
        for(int i = 0;i<arr.size();i++){
            maxi = max(maxi,arr[i]);

        }
        return maxi;
    }
    int minLimit(vector<int>& arr){
        int mini = INT_MAX;
        for(int i = 0;i<arr.size();i++){
            mini = min(mini,arr[i]);
        }
        return mini;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = minLimit(bloomDay), high = maxLimit(bloomDay), mid;
        if(bloomDay.size()< (long long) m*k) return -1;
        while(low<=high){
            int cnt = 0, boq = 0;
            mid = low + (high-low)/2;
            for(int i = 0;i<bloomDay.size();i++){
                if(mid>=bloomDay[i]){
                    cnt++;
                }
                else{
                    boq += cnt/k;
                    cnt = 0;
                }
            }
            boq += cnt/k;
            if(boq>=m){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
