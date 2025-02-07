// Problem Link: https://leetcode.com/problems/ugly-number/

class Solution {
private:
    vector<int> prime_factors(int num) {
        vector<int> res;
        if (num < 1) 
            return {};
        while (num % 2 == 0) {
            res.push_back(2);
            num /= 2;
        }
        while (num % 3 == 0) {
            res.push_back(3);
            num /= 3;
        }
        for (long long i = 5; i * i <= num; i += 6) {
            while (num % i == 0) {
                res.push_back(i);
                num /= i;
            }
            while (num % (i + 2) == 0) {
                res.push_back(i + 2);
                num /= (i + 2);
            }
        }
        if (num > 3)
            res.push_back(num);

        return res;
    }
public:
    bool isUgly(int n) {
        if (n < 1)
            return false;
        vector<int> res = prime_factors(n);
        for (int num : res)
            if (num != 2 && num != 3 && num != 5)
                return false;
        return true;
    }
};
