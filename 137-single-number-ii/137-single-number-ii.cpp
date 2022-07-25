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
    if(flag) 
        return unique_no;
    else
        return unique_no2;
    }
};