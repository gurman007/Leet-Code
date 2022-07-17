#define ll                      long long
#define pii						pair<int, int>
#define pli						pair<ll, int>
#define pil						pair<int, ll>
#define pll						pair<ll, ll>
#define vi						vector<int>
#define vll						vector<ll>
#define vb						vector<bool>
#define vd						vector<double>
#define vs						vector<string>
#define ff						first
#define ss						second
#define pb						push_back
#define eb						emplace_back
#define ppb						pop_back
#define pf						push_front
#define ppf						pop_front
#define vpli                    vector<pli>
#define vpii					vector<pii>
#define umap					unordered_map
#define all(x)					x.begin(),x.end()
class Solution {
public:
    vs trim(vs& nums, int trim_no)
{
    if(nums[0].size() == trim_no) {return nums;} // Basic optimization...

    int no_of_digit_removed = nums[0].size() - trim_no;
    vs new_nums;
// for each string simply use substr function... and add new string inot new_nums...
    for(int i = 0; i < nums.size(); ++i)
    {
        string curr = nums[i].substr(no_of_digit_removed);
        new_nums.pb(curr);
    }
    return new_nums;
}

int find_kth_Smallest_ele(vs& new_string, int k)
{
    vector< pair<string, ll> > pairs;
    for(int i = 0; i < new_string.size(); ++i)
    {
        pairs.pb({new_string[i], i});
    }
    // sort..
    sort(all(pairs));
    // simply return kth element's index..i.e pairs[k].ss
    return pairs[k-1].ss;
}

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vi output;
        int no_of_queires = queries.size(), i = 0;
        while(i < no_of_queires)
        {
         // for each query .. firstly trim..
            vs new_string = trim(nums, queries[i][1]);
            int idx = find_kth_Smallest_ele(new_string, queries[i][0]);
            output.pb(idx);
            i++;
        }
        return output;
    }
};