class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int,int> m;
        for (int num : hand) m[num]++;
        sort(hand.begin(), hand.end());
        for (int num : hand) {
            if (m[num] <= 0) continue;
            for (int i = num; i < num + groupSize; ++i) {
                if (m[i] == 0) return false;
                m[i]--;
            }
        }
        return true;
    }
};
