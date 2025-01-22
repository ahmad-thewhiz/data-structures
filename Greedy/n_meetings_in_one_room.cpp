// Problem Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
  public:
    static bool cmp(pair<int, int>a, pair<int, int>b) {
        return a.second<b.second;
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        vector<pair<int,int>>meets;
        
        for(int i=0;i<n;i++) {
            pair<int, int>p={start[i], end[i]};
            meets.push_back(p);
        }
        
        sort(meets.begin(), meets.end(), cmp);
        
        int count=1;
        int ansEnd=meets[0].second;
        
        for(int i=1;i<n;i++) {
            if(meets[i].first>ansEnd) {
                count++;
                ansEnd=meets[i].second;
            }
        }
        return count;
    }
};
