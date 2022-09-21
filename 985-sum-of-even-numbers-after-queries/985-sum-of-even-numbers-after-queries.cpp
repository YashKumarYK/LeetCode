class Solution {
public:
        vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int S = 0;
        for (int x: A)
            if (x % 2 == 0)
                S += x;

        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            int val = queries[i][0], index = queries[i][1];
            if (A[index] % 2 == 0) S -= A[index];
            A[index] += val;
            if (A[index] % 2 == 0) S += A[index];
            ans[i] = S;
        }

        return ans;
    }
};