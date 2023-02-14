class Solution {
public:
    
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res(nums1.size(), -1);
    map<int, int> local;
    stack<int> st;
    for (int j = 0; j < nums2.size(); j++)
    {
        while (st.size() && st.top() < nums2[j])
        {
            int pastvalue = st.top();
            st.pop();
            local[pastvalue] = nums2[j];

        }
        st.push(nums2[j]);
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (local.find(nums1[i]) != local.end())
            res[i] = local[nums1[i]];

    }
    return res;
}
};
