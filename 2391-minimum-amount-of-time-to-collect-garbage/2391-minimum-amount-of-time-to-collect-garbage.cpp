class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<vector<int>> v;
        unordered_map<char, int> mp;
        for( auto gr: garbage){
            int m=0, p=0, g=0;
            for( int i=0; i<gr.size(); ++i){
                if( gr[i]=='M') ++m;
                else if( gr[i]=='P') ++p;
                else if( gr[i]=='G') ++g;
            }
            mp['M']+= m;
            mp['P']+=p;
            mp['G']+=g;
            v.push_back({g, m, p});
            // cout<< g<<" "<<m<<" "<<p<<endl;
        }
        
        int m=0, g=0, p=0;
        
        int c =0;
        for( int i= 0; i<v.size() ; ++i){
          
            if( mp['G']!=0){
                g+= v[i][0]+c;
                if(v[i][0]!=0) mp['G'] -= v[i][0];
            }
            if( mp['M']!=0){
                m+= v[i][1]+c;
                if(v[i][1]!=0) mp['M']-= v[i][1];
               
            }
            if( mp['P']!=0){
                p+=v[i][2]+c;
                if(v[i][2]!=0) mp['P']-=v[i][2];
                
            }
            if( i != v.size()-1){
                c= travel[i];
            }
            // cout<< mp['M']<<" "<<mp['P']<<" " <<mp['G']<<endl;
      
        }
        // cout<<"-------------"<<endl;
        // cout<<m<<" "<<p<<" "<<g;
        return m+p+g;
    }
};