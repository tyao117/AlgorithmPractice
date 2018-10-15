// https://leetcode.com/problems/distribute-candies/description/

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        size_t amount = candies.size();
        unordered_set<int> diff;
        for (auto c :candies)
            diff.insert(c);
        return min(amount>>1, diff.size());
    }
};
