class Solution {
public:
    int closest(vector<int>& arr,int l,int r,int& x)
    {
        if (l > r) 
        {
            if (r >= 0 && l < arr.size())
                return abs(arr[r] - x) <= abs(arr[l] - x) ? r : l;
            else if (r >= 0) return r;
            else return l;
        }

        int mid = l + (r-l)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] > x) return closest(arr,l,mid-1,x);
        else return closest(arr,mid+1,r,x);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        int i = closest(arr,0,n-1,x);
        int j = i+1;

        while(k--)
        {
            if(i >= 0 && j < n)
            {
                if(abs(arr[i] - x) <= abs(arr[j] - x))
                i--;
                else
                j++;
            }
            else if (i >= 0)
                i--;
            else
                j++;

        }
        return  vector<int>(arr.begin() + (i + 1), arr.begin() + (j ));
    }
};
