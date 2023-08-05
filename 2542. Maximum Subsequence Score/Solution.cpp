class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int,vector<int>,greater<int>> qe;

        //để sort pair bằng nums2, ta chuyển pair {num2,num1}
        vector<pair<int,int>> arr;
        for(int i = 0;i < nums1.size();i++)
            arr.push_back({nums2[i],nums1[i]});

        sort(arr.begin(), arr.end(),greater<pair<int,int>>());
        long long sum = 0,res = 0;
        for(auto& [e,s] : arr)
        {
            sum += s;
            qe.push(s);

            if(qe.size() > k)
                sum -= qe.top(),
                qe.pop();
            if(qe.size() == k)
                res = max(res, sum * e);
        }
        return res;
        
    }
};
