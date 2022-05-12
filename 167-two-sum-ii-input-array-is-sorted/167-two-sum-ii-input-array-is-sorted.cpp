class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s=0;
        int e= numbers.size()-1;
        while( s<e){
            int sum = numbers[e]+ numbers[s];
            if(sum== target) return {s+1,e+1};
            if(sum >target) e--;
            if(sum< target) s++;
        }
        return {s,e};
    }
};