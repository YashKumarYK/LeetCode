bool compare( vector<int> &a, vector<int> &b ){
    if( a[0]== b[0]) return a[1]>b[1];
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size(), vector<int> (2,-1));
        sort(people.begin(), people.end(), compare);
        cout<<"[";
        for( int i=0; i< people.size(); i++){
            cout<<"["<<people[i][0]<<","<<people[i][1]<<"],";
        }
        cout<<"]";
        for(int i=0; i<people.size(); i++){
            int cnt, j;
            
            for( cnt=0, j=0; j<ans.size(); j++){
                if( ans[j][0]==-1){
                    if( cnt == people[i][1]) break;
                    cnt++;
                }
            }
            ans[j]= people[i];
        }
        
        return ans;
    }
};