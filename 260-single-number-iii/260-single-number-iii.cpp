class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
{
    vector<int> ans;
    int n = nums.size();
    int XOR = 0;
    for(int i = 0; i < n; ++i)
        XOR ^= nums[i];

// Calculating pos.. (i.e where first set-bit is present in XOR)
    int pos = 0, temp = XOR;
    while((temp & 1) != 1)
    {
        pos++;
        temp = temp >> 1;
    }
    
// The first set-bit in XOR is at postion 'pos'
    int mask = (1 << pos);

// Find those numbers which contain set-bit at position 'pos'
    int a = 0;
    int b = 0;
    for(int i = 0; i < n; ++i)
    {
        if( (mask & nums[i]) > 0 )
        {
            a ^= nums[i];
        }
    }
    b = a ^ XOR;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
    
};