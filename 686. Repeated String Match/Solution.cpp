class Solution {
public:
    int repeatedStringMatch(string a, string b) {
    int counter = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int fakei = i;
        if(i)
        counter = 1;
        else 
        counter = 0;
        for (int j = 0; j < b.size() ; j++, fakei++)
        {
            if (fakei % a.size() == 0) counter++;
            int indexi = fakei % a.size();

            if (b[j] != a[indexi])
            {
                counter = 0; break;
            }

            
        }
        if (counter) return counter;


    }
    return -1;
}
};
