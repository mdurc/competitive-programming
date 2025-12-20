class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // target values must exist in the correct positions
        bool fa=0,fb=0,fc=0;
        bool cand=0;
        for (vector<int>& trip: triplets) {
            if (trip[0]==target[0] && trip[1]==target[1] && trip[2]==target[2]) return true;
            if (trip[0]<=target[0] && trip[1]<=target[1] && trip[2]<=target[2]) cand = 1;
            if (trip[0]==target[0] && trip[1]<=target[1] && trip[2]<=target[2]) fa = 1;
            if (trip[0]<=target[0] && trip[1]==target[1] && trip[2]<=target[2]) fb = 1;
            if (trip[0]<=target[0] && trip[1]<=target[1] && trip[2]==target[2]) fc = 1;
        }
        return cand && fa && fb && fc;
    }
};
