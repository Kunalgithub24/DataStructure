class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(); int m = mat[0].size();
        vector<vector<int>> pSum(n, vector<int>(m,0));
        int maxArea = 0;
        for (int j=0; j<m; ++j) {
            int sum = 0;
            for (int i=0; i<n; ++i) {
                if (mat[i][j]=='0') sum=0;
                else sum += mat[i][j] - '0';
                pSum[i][j] = sum;
            }
        }
        for (int i=0; i<n; ++i) maxArea = max(maxArea, lHist(pSum[i]));
        return maxArea;
    }

    // Here it has used the old approach for solving the largest rectangle in histogram 
    // but i did in more shorter manner in question 84. Largest Rectangle in Histogram
    vector<int> calcPSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> ans(n);
        for (int i=0; i<n; ++i) {
            while (!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> calcNSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> ans(n);
        for (int i=n-1; i>=0; --i) {
            while (!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    int lHist(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = calcPSE(arr, n);
        vector<int> nse = calcNSE(arr, n);
        int area=0;

        for (int i=0; i<n; ++i) {
            int width = nse[i] - pse[i] - 1;
            area = max(area, width*arr[i]);
        }
        return area;
    }
};
