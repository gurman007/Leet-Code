#define vi vector<int>
#define pb push_back
class Solution {
public:
    void helper(int no, int n, vi& arr)
{
    if(no > n) 
        return;

    if(no != 0) arr.pb(no); 
    for(int i = 0; i <= 9; ++i)
    {
        no = no*10 + i;           // Updating no.           
        if(no == 0) continue;   
        helper(no, n, arr);
        no /= 10;                // while Bactracking undo..
    }
}
    
    vector<int> lexicalOrder(int n) 
    {
        vi arr;
        helper(0, n, arr); 
        return arr;
    }
};