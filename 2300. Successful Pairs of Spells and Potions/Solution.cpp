class Solution {
public:
    
    
void helper(int low, int high, double& comp, int& counter, vector<int>& potions)
{
    if (low > high) return;
   
    int mid = low + (high - low) / 2;
   
     if (potions[mid] < comp)
        helper(mid + 1, high, comp, counter, potions);
    else
    {
        counter += (high - mid) + 1;
        helper(low, mid - 1, comp, counter, potions);
       
    }

}


vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> res;
    sort(potions.begin(),potions.end());
    for (auto x : spells)
    {
        int counter = 0;
            double divide = (double)success / x;
            helper(0, potions.size() - 1, divide, counter, potions);

        res.push_back(counter);

    }

    return res;
}
};
