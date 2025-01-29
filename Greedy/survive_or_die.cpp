// Problem Link: https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

class Solution {
  public:
    int minimumDays(int totalDays, int maxPurchase, int requiredFood) {
        if(requiredFood > maxPurchase || ((maxPurchase*6 < requiredFood*7) && totalDays>6))
            return -1;
        
        int totalFood=totalDays*requiredFood;
        int days=totalFood/maxPurchase;
        
        if(totalFood % maxPurchase!=0)
            days++;
        
        return days;
    }
};
