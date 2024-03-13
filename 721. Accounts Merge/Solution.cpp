class Solution {

public:

    
void dfs_account(int index,vector<bool>& visited,unordered_map<string,vector<int>>& email2id,set<string>& mset,vector<vector<string>>& accounts)
{
    if(visited[index]) return;

    visited[index] = true;
    for (int i = 1; i < accounts[index].size(); i++)
    {
        /* scan through all email in accounts at index and add to set*/
        mset.insert(accounts[index][i]);

        // dfs deeper to any index related to this email
        for(auto x:email2id[accounts[index][i]])
            dfs_account(x,visited,email2id,mset,accounts);
    }
}
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        

        vector<vector<string>> ans; // this variable is used to return the result
        unordered_map<string,vector<int>> email2id; // this will create a dictionary with key value , key is email and value is index
        int index = 0;
        //initialize dictionary with email and indexing
        for(auto x: accounts)
        {

            for (int i = 1; i < x.size(); i++)
            {
                /* enter email with list of associated index */
                email2id[x[i]].push_back(index);
            }
            index++;
        }

        vector<bool> visited(accounts.size(),false); // this to mark which index already checked

        for (int i = 0; i < accounts.size(); i++)
        {
            /* code */
            set<string> mset;
            dfs_account(i,visited,email2id,mset,accounts);
            if(!mset.empty())
            {
                vector<string> onelist = {accounts[i][0]};
                for(auto x:mset)
                    onelist.push_back(x);

                ans.push_back(onelist);
            }
        }
        

        return ans;

    }
};
