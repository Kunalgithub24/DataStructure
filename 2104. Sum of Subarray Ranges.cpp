// ---------------- Approach 1: Brute Force ----------------
class Solution {
public:
    long long subArrayRanges(vector<int>& A) {
        long long res = 0;
        for (int i = 0; i < A.size(); i++) {
            int ma = A[i], mi = A[i];
            for (int j = i; j < A.size(); j++) {
                ma = max(ma, A[j]);  // update max in current subarray
                mi = min(mi, A[j]);  // update min in current subarray
                res += ma - mi;      // add the range
            }
        }
        return res;
    }
};

// ---------------- Approach 2: Optimized with Monotonic Stacks ----------------
class Solution {
public:
    // ---------- Minimum side ----------
    vector<long long> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<long long> nse(n, n); 
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    
    vector<long long> findpsee(vector<int>& arr) {
        int n = arr.size();
        vector<long long> psee(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
    
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long> nse = findnse(arr);
        vector<long long> psee = findpsee(arr);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total += arr[i] * left * right;
        }
        return total;
    }

    // ---------- Maximum side ----------
    vector<long long> findnle(vector<int>& arr) {
        int n = arr.size();
        vector<long long> nle(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nle;
    }
    
    vector<long long> findplee(vector<int>& arr) {
        int n = arr.size();
        vector<long long> plee(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            plee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return plee;
    }
    
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<long long> nle = findnle(arr);
        vector<long long> plee = findplee(arr);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - plee[i];
            long long right = nle[i] - i;
            total += arr[i] * left * right;
        }
        return total;
    }

    // ---------- Final ----------
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
