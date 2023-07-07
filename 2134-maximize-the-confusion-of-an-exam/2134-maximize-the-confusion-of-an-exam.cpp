class Solution {
public:
    int slidingWindow(string &a, int k, char ch){
        int i=0;
        int j=0;
        int n = a.size();
        int cnt =0;
        int len = 0;
        while(j<n){
            if(a[j]==ch) cnt++;
            if(cnt>k){
                while(cnt>k){
                    if(a[i]==ch){
                        cnt--;
                    }
                    i++;
                }
            }
            if(cnt<=k){
                len = max(len, j-i+1);
            }
            j++;
        }
        return len;
    }
    int maxConsecutiveAnswers(string a, int k) {
        int ans1 = slidingWindow(a, k, 'T');
        int ans2 = slidingWindow(a, k, 'F');
        return max(ans1, ans2);
    }
};