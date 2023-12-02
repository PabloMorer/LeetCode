class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> m;
        map<char, int>::iterator it;
        for (int i = 0; i < chars.size(); i++) {
            it = m.find(chars[i]);
            if (it != m.end()) {
                it->second++;
            }
            else {
                m.insert({ chars[i], 1 });
            }
           
        }
        map<char, int> m_aux = m;
        int total = 0;
        for (auto& a : words) {
            int j = 0;
            bool g = true;
            while (j < a.size() && g) {
                it = m_aux.find(a[j]);
                if (it != m_aux.end() && it->second > 0) {
                    it->second--;
                }
                else {
                    g = false;
                }
                j++;
            }
            if (g) {
                total += a.size();
            }
            m_aux = m;

        }

        return total;
    }
};
