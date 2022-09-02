class Solution {
public:
    int minimumRefill(vector<int>& p, int c1, int c2) {
        int n = p.size();
        int curr1=c1;
        int curr2=c2;
        int i=0, j= n-1;
        int count =0;
        while( i<=j){
            if( i==j){
                int maxi = max(curr1, curr2);
                if( maxi<p[i]) count++;
            }
            
            else{
                if( curr1<p[i] ){
                    count++;
                    curr1 = c1;
                }
                if( curr2<p[j]){
                    count++;
                    curr2=c2;
                }
            } 
            
            
            curr1 -=p[i];
            curr2 -=p[j];
            i++, j--;
            
        }
        return count;
    }
};