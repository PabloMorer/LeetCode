#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int cont = 0;
        int b= 0;
        unordered_map<char, int> chars;
        unordered_map<char, int>::iterator it;
        unordered_map<char, int>::iterator it2;
        int a = 0;
        while (b < s.size()) {
            it = chars.find(s[b]);
            if (it == chars.end()) {
                chars.insert({ s[b], b });
                cont++;
                if (cont > max) {
                    max = cont;
                }
                b++;
            }
            else {
                if (it->second == a) {
                    it->second = b;
                    a++;
                    b++;
                }
                else {
                    it2 = chars.find(s[b]);
                    a = it2->second + 1;
                    it2->second = b;
                    b++;
                    cont = b - a;
                    deleteChars(chars, a);
                }
            }
        }

        return max;
    }

    void deleteChars(unordered_map<char, int>& chars, int a) {
        unordered_map<char, int>::iterator it = chars.begin();

        while (it != chars.end()) {
            if (it->second < a) {
                it = chars.erase(it);
            }
            else {
                it++;
            }
            
        }
        
    }
};
