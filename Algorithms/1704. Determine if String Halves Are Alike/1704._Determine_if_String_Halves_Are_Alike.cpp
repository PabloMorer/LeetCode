#include<iostream>
#include<string>

using namespace std;
class Solution {
public:

    bool halvesAreAlike(string s) {
        string a = s.substr(0, s.size() / 2);
        string b = s.substr(s.size() / 2, s.size() / 2);
        return countVowels(a) == countVowels(b);
    }

private:
    int countVowels(string a) {
        int cont = 0;
        for (auto c : a) {
            if (tolower(c) == 'a' ||
                tolower(c) == 'e' ||
                tolower(c) == 'i' ||
                tolower(c) == 'o' ||
                tolower(c) == 'u') {
                cont++;
            }
        }
        return cont;
    }
};
