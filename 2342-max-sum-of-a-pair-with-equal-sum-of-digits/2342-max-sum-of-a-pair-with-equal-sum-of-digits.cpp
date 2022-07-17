#define ll long long
#define pb push_back
#define pll pair<long, long>
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
class Solution {
public:
    ll sum_of_digits(int i)
{
    ll sum = 0;
    while(i > 0)
    {
        sum += i%10;
        i /= 10;
    }
    return sum;    
}

int maximumSum(vector<int>& nums)
{
    vector<pll> pairs;    // pair of {sum, nums[i]}
    for(auto i : nums)
    {
        ll c_sum = sum_of_digits(i);
        pairs.pb({c_sum, i});
    }
    // Sort pairs on the basis of curr_sum...
    sort(all(pairs));
    // Iterate over pairs.. to find answer...
    ll max_sum = INT_MIN;
    for(int i = 0; i < pairs.size()-1; ++i)
    {
        if(pairs[i].ff == pairs[i+1].ff)
        {
            ll c_pair_sum = pairs[i].ss + pairs[i+1].ss;
            max_sum = max(max_sum, c_pair_sum);
        }
    }
    return max_sum == INT_MIN ? -1 : max_sum;
}
};