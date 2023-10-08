class Solution {
public:
    
string fractionAddition(string expression) {
    expression += "+";
    bool neg = false, divider = true;
    int dv = 0, dvd = 0;
    int DV = 0, DVD = 1;
    int temp;
    for (auto x : expression)
    {
        if (x == '-' || x == '+')
        {
            
            
            if (abs(dv))
            {
                DV = DV * dvd + dv * DVD;
                DVD = dvd * DVD;
                dv = 0, dvd = 0;
            }
            neg = x == '-';
            divider = true;
        }
        else if (x == '/')
            divider = false;
        if (x >= '0' && x <= '9')
        {
            if (divider)
            {
                 temp  = (x - '0') * (neg?-1:1);
                dv = dv * 10 + temp;
            }
            else
            {
                temp = (x - '0');
                dvd = dvd * 10 + temp;
            }

        }
    }
    string res = "";
    res = (DV < 0 ? "-" : "");
    DV = abs(DV);
    int common = gcd(DV, DVD);
    DV /= common;
    DVD /= common;
    string sdv = to_string(DV), sdvd = to_string(DVD);

   
    
    res += sdv + '/' + sdvd;
  
    return res;
}
};
