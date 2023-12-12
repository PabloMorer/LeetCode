class Solution {
public:
    string largestGoodInteger(string num) {
        int cont = 1;
        int max = -1;
        string r = num.substr(0, 1);;
        string re;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i - 1]) {
                cont++;
                r += num.substr(i, 1);
                if (cont == 3) {
                    cont = 2;
                    int nm = num[i] - '0';
                    if (nm > max) {
                        max = nm;
                        re = r;

                    }
                }
            }
            else {
                cont = 1;
                r = num.substr(i, 1);
            }
        }
        return re;
    }
};
