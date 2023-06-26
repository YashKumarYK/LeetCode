class Solution {
public:
    long long totalCost(vector<int>& cs, int k, int cd) {
        int n = cs.size();
        priority_queue<int, vector<int> , greater<int>> pq, pq2;
        int i=0;
        while(i<cd){
            pq.push(cs[i]);
            i++;
        }
        int j= n-1;
        int c = 0;
        if(cd >cs.size()-cd){
            cd = cs.size()-cd;
        }
        while(c<cd){
            pq2.push(cs[j]);
            c++;
            j--;
        }
        long long sum =0;
       
        while( k--){
            if(pq.size()==0){
                sum+= pq2.top();
                pq2.pop();
                if(i<=j){
                    pq2.push(cs[j]);
                    j--;
                }
               
            } 
            else if(pq2.size()==0){
                sum+= pq.top();
                pq.pop();
                if(i<=j){
                    pq.push(cs[i]);
                    i++;
                }
               
            } 
            else if(pq.top()<=pq2.top()){
                sum+= pq.top();
                pq.pop();
                if(i<=j){
                    pq.push(cs[i]);
                    i++;
                }
            }
            else if( pq.top()>pq2.top()){
                sum += pq2.top();
                pq2.pop();
                if(i<=j){
                    pq2.push(cs[j]);
                    j--;
                }
            }
        }
        return sum;
    }
};