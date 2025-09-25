class Solution {
public:
    int thirdMax(vector<int>& nums) {
      set<int> s(nums.begin(), nums.end()); 
       if (s.size() < 3) {
            return *s.rbegin(); // largest element
        }
      auto it = s.rbegin(); // reverse iterator -> largest
        advance(it, 2);       // move 2 steps (to 3rd largest)
        return *it;
    }
};