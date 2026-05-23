## Line Sweep (Intervals)

> **TL;DR:** Solves interval and geometric problems by moving a conceptual line across an axis, processing "events" at specific coordinates. Converts $O(N^2)$ interval intersection checks into an $O(N \log N)$ sort for preprocessing and a single $O(N)$ pass.

* For queries such as: "maximum number of overlapping intervals at any point" or "total length of the union of intervals".
* Instead of checking every point or every pair of intervals, we only care about the coordinates where the state *changes*.
* **State changes (Events):**
  - An interval $[L, r]$ starting means the "active" count increases by 1.
  - An interval $[l, R]$ ending means the "active" count decreases by 1.

### Implementation
* We decompose an interval $[L, R]$ into two separate events: an **Entry** event at $x = L$, and an **Exit** event at $x = R + 1$. 
* We sort all events primarily by their $x$-coordinate. 
* **Tie-breaking:** you must determine if entry should be processed before exit, or vice-versa.

*Maximum overlapping intervals.*

```cpp
struct Event {
  long long x;
  int type; // +1 for entry, -1 for exit
  bool operator<(const Event& other) const {
    if (x != other.x) return x < other.x;
    return type < other.type;  // process exits before entries
  }
};

int max_overlapping_intervals(const auto& intervals) {
  std::vector<Event> events;
  for (auto& [l, r] : intervals) {
    events.push_back({l, 1});
    events.push_back({r + 1, -1}); // interval ends after R
  }

  std::sort(events.begin(), events.end());

  int current_active = 0;
  int max_active = 0;
  for (const Event& ev : events) {
    current_active += ev.type;
    max_active = std::max(max_active, current_active);
  }

  return max_active;
}
