class Solution {
public:
    int kthGrammar(int n, int k) {
        cout << n << endl;
        if(n == 1) return 0;
        
        if(k % 2 == 0) return kthGrammar(n-1,k/2) == 0 ?  1 : 0;
        else return kthGrammar(n-1,k/2) == 0 ?  0 : 1;
        
    }
};
