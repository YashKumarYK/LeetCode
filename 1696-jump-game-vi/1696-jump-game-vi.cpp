
class Solution{
public:
    int maxResult(vector<int> &nums, int k)
    {
        if(nums.size()==1)
            return nums[0];
        multiset<int, greater<int>> set;

        int start = 0;
        int end = 0;
        int n = min((int)nums.size() - 1, start + k);

        for (; end <= n; end++)
        {
            if (!set.empty())
                nums[end] += *set.begin();

            set.insert(nums[end]);
        }

        for (; end < nums.size(); end++)
        {
            
          
            set.erase(set.find(nums[start++]));

            nums[end] += *set.begin();

            set.insert(nums[end]);
        }

        return nums.back();
    }
};