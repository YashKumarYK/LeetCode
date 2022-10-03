class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         int n1=0;
//         int n2=0;
//         if( nums2.size()%2==0 && nums1.size()%2==0) return 0;
//         if( nums1.size()%2!=0){
//             unordered_map<int, int> mp;
//             for( int i=0; i<nums2.size(); ++i){
//                 mp[nums2[i]]++;
//             }
//             for( auto i:mp){
//                 if(i.second%2!=0) n2 = n2^i.first;  
//             }
//             return n2;
//         }
//         if( nums2.size()%2!=0){
//             unordered_map<int, int> mp;
//             for( int i=0; i<nums1.size(); ++i){
//                 mp[nums1[i]]++;
//             }
           
//             for( auto i:mp){
//                 if(i.second%2!=0) n1 = n1^i.first;  
//             }
//         }
//         return n1^n2;
       // / {
        int n1=0;
        int n2=0;
        for( int i=0; nums2.size()%2!=0 && i<nums1.size(); ++i){
                n1= n1^nums1[i];
        }
        for( int i=0; nums1.size()%2!=0 && i<nums2.size(); ++i){
                n2= n2^nums2[i];
        }
        return n1^n2;
    }
};