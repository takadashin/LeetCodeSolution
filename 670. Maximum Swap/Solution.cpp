class Solution {
public:

int maximumSwap(int num) {
    string bs = to_string(num);
    int tmpi = -1, tmpi2 = -1;
    int maxi = -1, maxnum = -1;
    int mini = -1, minnum = -1;

    for (int i = bs.size() - 1; i  >= 0; i--)
    {
        int x = bs[i] - '0';
        if (maxnum < x || maxi == -1) 
        {
                
            maxnum = x, maxi = i, mini = i, minnum = x;
        }


        else  if (maxnum > x) mini = i, minnum = x, tmpi = maxi, tmpi2 = mini;
    }
    if (mini == -1 && tmpi != -1) 
        return num;
    else if (mini != maxi) 
        swap(bs[mini], bs[maxi]);
    else if (tmpi != -1)
        swap(bs[tmpi], bs[tmpi2]);
    
    return stoi(bs);
}
};
