#define umap unordered_map
#define ss second
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
     umap<int, int> freq;
    for(auto i : nums) { freq[i]++; }
    int no_of_pairs{}, left_overs{};

    for(auto m : freq)
    {
        no_of_pairs += m.ss / 2;
        left_overs += m.ss % 2;
    }
    return {no_of_pairs, left_overs};
    }
};