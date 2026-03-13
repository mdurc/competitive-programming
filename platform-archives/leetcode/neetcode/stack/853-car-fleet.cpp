class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for (int i=0; i<position.size(); ++i){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend()); // sorts by position in pair<int,int>
        stack<double> s;
        for (int i=0; i<cars.size(); ++i){
            // position + v*t = new_position --> solve for time reached target
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (!s.empty() && time <= s.top()){
                // if the current cars time is faster than the car in front of them
                continue;
            }
            s.push(time); // the new slowest time in this position
        }
        return s.size();
    }
};

/*
Notes:

- we have to start from the position that is closest to the target.
    - because this is the first car to set the slowest pace
- need to merge the speed and position vectors so that sorting stays aligned
*/
