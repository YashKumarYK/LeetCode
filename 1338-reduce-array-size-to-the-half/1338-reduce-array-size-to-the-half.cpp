class Solution {
public:
	int minSetSize(vector<int>& arr) {

		map<int, int> mp;
		for(auto i : arr){
			mp[i]++;
		}

		multimap<int, int, greater<int>> m; // Descending
		for(auto i : mp){
			m.insert({i.second, i.first});
		}

		int n = arr.size();
		int target = n;
		int ans = 0;

		for(auto it=m.begin() ; it!=m.end() ; it++){

			target = target - it->first;
			ans++;
			if(target <= n/2){
				return ans;
			}
		}
		return ans;
	}
};