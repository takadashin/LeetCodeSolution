typedef pair<int, int> pr;
class Solution {

public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size() ;
        auto cp = [&](pr a,pr b){
            return arr[a.first] * arr[b.second] > arr[a.second]* arr[b.first];
        };


        priority_queue<pr,vector<pr>,decltype(cp)> minH(cp);
        for(int i = 1;i < n;i++) minH.push({0,i});

        for(int t = 0;t < k-1;t++)
        {
            auto [i,j] = minH.top();
            minH.pop();
            if( i +1 < j) minH.push({i+1,j});
        }

        return {arr[minH.top().first] , arr[minH.top().second]};

    }
};
