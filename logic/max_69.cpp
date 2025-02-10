// You are given a positive integer num consisting only of digits 6 and 9.
// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

// Example 1:
// Input: num = 9669
// Output: 9969

class Solution {
public:
    int maximum69Number(int num) {
        string value = to_string(num);
        int idx = 0, size = value.size();
        
        while (idx < size && value[idx] != '6')
            idx++;
        
        if (idx == size)
            return num;
        
        num += 3 * pow(10, size - idx - 1);

        return num;
    }
};
