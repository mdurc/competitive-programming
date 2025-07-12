// Max heap solution
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26, 0);
        for (char t: tasks) {
            ++f[t - 'A'];
        }
        priority_queue<int> pq; // max heap
        for (int i = 0; i < 26; ++i) {
            if (f[i] > 0) {
                pq.push(f[i]);
            }
        }

        int time = 0;
        queue<pair<int, int>> q; // <amt_remaining, time_when_valid>
        while (!pq.empty() || !q.empty()) {
            ++time;
            if (pq.empty()) {
                // skip to next time
                time = q.front().second;
            } else {
                int curr = pq.top(); pq.pop();
                if (--curr > 0) {
                    q.push({curr, time + n});
                }
            }
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};


// Greedy solution
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
        [A, A, A, B, B] n = 2
        - Minimum layout: A _ _ A _ _ A
        Important, because of the rules regarding proximity,
        we can only place at most one character in each idle group.
        For example, if we tried to place both B's in the same idle group (A B B A _ _ A) we would
        violate the task proximity. Thus, at any given cycle, we can take up at most (num_idle_groups)
        idle positions, which would be (max_frequency - 1). Though it is possible that there are so
        many idle groups available, that we can simply take up (current_frequency) idle positions.
        A B _ A B _ A, answer = 7

        An important note is to understand that if you fill up all idle positions, the remaining tasks
        can be inserted somewhere in the schedule only costing one more interval for each placement.
        For example, if we have [C C D] remaining in the schedule: A B A B A, we can always find a new
        schedule that will not require any more idle positions: A C B D A C B A, as an example.

        We can simply keep track of the required idle positions, and then add the final remaining
        idle count with the total number of tasks.
        */

        vector<int> f(26, 0);
        for (char t: tasks) {
            ++f[t - 'A'];
        }

        sort(f.begin(), f.end()); // sort in ascending order
        int f_max = f[25];
        int idle = n * (f_max - 1); // starting amt of idle spaces
        for (int i = 24; i >= 0; --i) {
            // f_max - 1 idle groups to use, but possibly we only need f[i] groups
            idle -= min(f_max - 1, f[i]);
        }
        return max(0, idle) + tasks.size();
    }
};
