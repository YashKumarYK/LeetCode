class Solution {
public:
    int countWays(vector<int>& arr) {
        int n = arr.size(), answer = 0;
        sort(arr.rbegin(), arr.rend());
        reverse(arr.begin(), arr.end());
        if (arr[0] > 0)
            answer = 1;
        if (n > arr[n - 1])
            answer++;
        n--;
        for (int i = 0; i < n; i++)
            if ((i + 1) > arr[i])
                if ((i + 1) < arr[i + 1])
                    answer++;
        return answer;
    }

};