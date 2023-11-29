#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:

    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> v;
        int word_l = words[0].size();
        int max = word_l * words.size();

        if (max <= s.size()) {
            unordered_map<string, int> m;
            unordered_map<string, int>::iterator it = m.begin();
            for (int i = 0; i < words.size(); i++) {
                it = m.find(words[i]);
                if (it != m.end()) {
                    it->second++;
                }
                else {
                    m.insert({ words[i], 1 });
                }
            }
            unordered_map<string, int> m2;
            m2 = m;
            unordered_map<string, int>::iterator it2 = m.begin();
            it = m.begin();
            while (it != m.end()) {
                string w = it->first;
                int i = 0;
                while (i <= s.size() - max) {
                    if (s.substr(i,word_l) == w ) {
                        it2 = m.find(it->first);
                        it2->second--;
                        int j = word_l;
                        bool r = true;
                        while (j < max && r) {
                            string p = s.substr(i + j, word_l);
                            it2 = m.find(p);
                            if (it2 != m.end() && it2->second > 0) {
                                it2->second--;
                            }
                            else {
                                r = false;
                            }
                            j += word_l;

                        }
                        if (r) {
                            v.push_back(i);
                        }
                        m = m2;
                    }
                    i++;
                }
                it++;
            }
            m.clear();
            m2.clear();
        }
        return v;
    }

};
