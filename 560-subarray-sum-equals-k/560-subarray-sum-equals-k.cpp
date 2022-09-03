#define umap unordered_map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
{
    int prefix_sum = 0;
    int ans = 0;
    umap<int, int> prefix_count;           
    prefix_count[0]++;
    for(int i = 0; i < nums.size(); ++i)
    {
        // pre[l...r] = pre[r] - pre[l-1]

        prefix_sum += nums[i];
        int need = prefix_sum - k;
        ans += prefix_count[need];
        prefix_count[prefix_sum]++;
    }
    return ans;
}
};