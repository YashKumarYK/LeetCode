class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long> mp;
        long long day=1;
        mp[tasks[0]]= 1;
        for( int i=1; i<tasks.size(); i++){
            ++day;
            if(mp.find(tasks[i])!= mp.end() && day-mp[tasks[i]]<=space)
                day= mp[tasks[i]]+ space+1;
            mp[tasks[i]] = day;
        }
        return day;
    }
};