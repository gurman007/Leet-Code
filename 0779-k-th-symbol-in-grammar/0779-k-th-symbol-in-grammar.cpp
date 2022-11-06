class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base Case..
    if(n == 1) 
        return 0;

    int parent = kthGrammar(n-1, (k+1)/2);
   //

    if (parent) 
        return ((k % 2) ? 1 : 0);
    else 
        return ((k % 2) ? 0 : 1);
    }
};