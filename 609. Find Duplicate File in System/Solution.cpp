class Solution {
public:
vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> files;
    vector<vector<string>> res;
    for (auto x : paths)
    {
        string root;
        string file;

        stringstream move(x);
        getline(move, root, ' ');
        while (getline(move, file, ' '))
        {
            string content = file.substr(file.find('(')+1, file.size() - file.find('(') - 2);
            string filename = file.substr(0, file.find('('));

            files[content].push_back(root + "/" + filename);

        }

    }
    for (auto x : files)
    {
        if(x.second.size() > 1)
        res.push_back(x.second);
    }
    return res;
}
};
