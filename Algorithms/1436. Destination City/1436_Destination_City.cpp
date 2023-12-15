class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> ini;
        for (int i = 0; i < paths.size(); i++) {
                ini.insert(paths[i][0]);
        }
    
        for (int i = 0; i < paths.size(); i++) {
            string dest = paths[i][1];
            if (ini.find(dest) == ini.end()) {
                return dest;
            }
        }

        return "";
    }
};
