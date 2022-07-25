class Solution
{
public:
int singleNumber(vector<int>& nums) {
        
        long long int ans = 0;
        vector<int>cnt(32,0);   // count bit array => Constant Extra Space
        for(int i=0;i<nums.size();i++)
        {
            int j=31;
            long long int n = abs(nums[i]);  // int-Range	=>	[ -2,147,483,648 to 2,147,483,647 ]
            while(n)                    // abs(-2,147,483,648) = 2,147,483,648 not stored in 'int'
            {
                cnt[j] += n&1;
                n >>= 1; 
                j--;
            }
        }
        
        for(int j=31;j>=0;j--)
        {
            int bit = cnt[j]%3;
            if(bit)
             ans += 1 <<(31-j); // 1 * 2^(31-j)
        }
        
        int c=0;
        for(auto x:nums)   //for negative numbers
          if(x==ans) {c++;}   //if our calculated value 'ans' is present in array, then increment c
        return c==1?ans:-ans; 
    }
};