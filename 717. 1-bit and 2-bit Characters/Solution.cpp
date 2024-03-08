class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index =0;
        if(bits.size() == 1) return true; 
        while(index < bits.size())
        {
            index += (bits[index] == 1) ? 2 : 1;
            if(index == bits.size() -1) return true;
        }
        return false;
    }
};
