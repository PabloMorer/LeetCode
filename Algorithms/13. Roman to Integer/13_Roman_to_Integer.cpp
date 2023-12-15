#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {


public:
    int romanToInt(string s) {
        map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        int cont = 0;
        int a = 0;
        while (a < s.size()) {
           
            if (a + 1 < s.size() && map.find(s[a])->second < map.find(s[a + 1])->second ) {
                cont += ( map.find(s[a + 1])->second - map.find(s[a])->second);
                a += 2;
            }
            else {
                cont +=  map.find(s[a])->second;
                a++;
            }
        }

        return cont;
    }
};
