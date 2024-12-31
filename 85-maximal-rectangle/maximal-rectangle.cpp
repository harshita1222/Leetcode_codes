class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (!n)
            return 0;
        int m = matrix[0].size();
        vector<int> hist(m, 0);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hist[j] = matrix[i][j] == '1' ? hist[j] + 1 : 0;
            }
            maxArea = max(maxArea, calcMaxRectInHist(hist));
        }
        return maxArea;
    }

private:
    int calcMaxRectInHist(vector<int> hist) {
        stack<pair<int, int>> stk;
        int n = hist.size();
        int maxRect = 0;
        for (int i = 0; i < n; i++) {
            int exdnIdx = i;
            while (!stk.empty() and stk.top().second > hist[i]) {
                exdnIdx = stk.top().first;
                maxRect = max(maxRect, (i - exdnIdx) * stk.top().second);
                stk.pop();
            }
            stk.push({exdnIdx, hist[i]});
        }
        while (!stk.empty()) {
            maxRect = max(maxRect, (n - stk.top().first) * stk.top().second);
            stk.pop();
        }
        return maxRect;
    }
};