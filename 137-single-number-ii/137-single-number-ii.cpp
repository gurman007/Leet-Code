// class Solution
// {
// public:
// int singleNumber(vector<int>& nums) {
        
//         long long int ans = 0;
//         vector<int>cnt(32,0);   // count bit array => Constant Extra Space
//         for(int i=0;i<nums.size();i++)
//         {
//             int j=31;
//             long long int n = abs(nums[i]);  // int-Range	=>	[ -2,147,483,648 to 2,147,483,647 ]
//             while(n)                    // abs(-2,147,483,648) = 2,147,483,648 not stored in 'int'
//             {
//                 cnt[j] += n&1;
//                 n >>= 1; 
//                 j--;
//             }
//         }
        
//         for(int j=31;j>=0;j--)
//         {
//             int bit = cnt[j]%3;
//             if(bit)
//              ans += 1 <<(31-j); // 1 * 2^(31-j)
//         }
        
//         int c=0;
//         for(auto x:nums)   //for negative numbers
//           if(x==ans) {c++;}   //if our calculated value 'ans' is present in array, then increment c
//         return c==1?ans:-ans; 
//     }
// };
#define vi vector<int>
#define ll long long
class Solution {
public:
    
    int singleNumber(vector<int>& nums) 
{
    vi sum(32, 0);
    ll st_bit = 1;
    for(int i=0, k=0; i < 32; ++i, ++k)
    {
        ll mask = (st_bit << i);
        for(int j = 0; j < nums.size(); ++j)
        {
            if((mask & nums[j]) > 0)
                sum[k] += 1;
        }
        sum[k] %= 3;
    }
    
    // Evaluating Unique Number..
    ll unique_no = 0, flag = 1; 
    signed int unique_no2 = 0;
    if(sum[31] == 0)          // i.e number is positive as MSB = 0;
    {
        for(int i = 0; i < 32; ++i)
        {
            if(sum[i] == st_bit)
            {
                ll pow = (st_bit << i);
                unique_no += pow;
            }
        }
    }
    else
    {
        flag = 0;
        string s;
        for(int i = sum.size()-1; i >= 0; --i)
        {
            char c = sum[i] + '0';
            s += c;
        }
        auto ul = stoul(s,nullptr,2);
        unique_no2 = ul;
    } 
    return flag == true ? unique_no : unique_no2;
    }
};