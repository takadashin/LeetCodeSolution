class Solution {
public:
    int minFlips(int a, int b, int c) {
        int counter = 0;

        while (c || a || b)
        {
            if(c & 1 == 1)
            {
                 if  ((a & 1) || (b & 1))
                 {

                 }
                 else
                 counter++;
            }
            else
            { // = 0
                if((a & 1) && (b & 1)) counter +=2;
                else if  ((a & 1) || (b & 1)) counter += 1;
                else
                counter +=0;
            }
            c = c >> 1;
            a = a >> 1;
            b = b >> 1;
        }

        return counter;
    }
};
