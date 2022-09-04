#define umap unordered_map
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
{
    int prefix_sum = 0;
    int ct = 0;         // answer variable...
        umap<int, int> r_count;    // remainder_count, key = remainder, value  
    r_count[0]++;
    for(int i = 0; i < nums.size(); ++i)
    {

        prefix_sum += nums[i];
        int need = (prefix_sum % k + k) % k;
        ct += r_count[need];
        r_count[need]++;
    }
    return ct;
}
};