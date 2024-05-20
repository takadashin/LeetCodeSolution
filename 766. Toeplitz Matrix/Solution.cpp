class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i < m;i++)
        {
            int index2 = i;
            int index = 0;
            int num = matrix[index][index2];
            
            while(index2 < m && index < n) 
            {
  
                if(matrix[index][index2] !=  num) return false;
                index++,index2++;
            }

        }

        for(int i=0;i < n;i++)
        {
            int index2 = 0;
            int index = i;
            int num = matrix[index][index2];
            while(index2 < m && index < n) 
            {
                if(matrix[index][index2] !=  num) return false;
                index++,index2++;
            }

        }

        return true;
    }
};
