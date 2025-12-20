// dp[w] = max value from using the first i items with total weight <= w
int knapsack_no_rep(vector<int>& weights, vector<int>& val, int CAP) {
  int n = weights.size();
  vector<int> dp(CAP + 1, 0);
  for (int i = 0; i < n; ++i)
    for (int w = CAP; w >= weights[i]; --w)
      dp[w] = max(dp[w], dp[w - weights[i]] + val[i]);
  return dp[CAP];
}
// dp[w] = max value with total weight <= w with unlimited copies of each item
int knapsack_rep(vector<int>& weights, vector<int>& val, int CAP) {
  int n = weights.size();
  vector<int> dp(CAP + 1, 0);
  for (int w = 0; w <= CAP; ++w)
    for (int i = 0; i < n; ++i)
      if (weights[i] <= w) dp[w] = max(dp[w], dp[w - weights[i]] + val[i]);
  return dp[CAP];
}
// inc[i] = length of the longest increasing subsequence ending at index i
int LIS(vector<int>& a, int n) {
  vector<int> inc(n);
  for (int i = 0; i < n; ++i) inc[i] = 1;
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i]) {
        inc[i] = max(inc[i], inc[j] + 1);
        ans = max(ans, inc[i]);
      }
  return ans;
}
// min_curr = minimum sum of a subarray ending at current position
int min_subarray_sum(vector<int>& nums) {
  int ans = INT_MAX, min_curr = 0, DEFAULT = 0;
  for (auto& i : nums) {
    min_curr += i;
    ans = min(ans, min_curr);
    min_curr = min(min_curr, DEFAULT);
  }
  return ans;
}
// max_curr = maximum sum of a subarray ending at current position
int max_subarray_sum(vector<int>& nums) {
  int ans = INT_MIN, max_curr = 0, DEFAULT = 0;
  for (auto& i : nums) {
    max_curr += i;
    ans = max(ans, max_curr);
    max_curr = max(max_curr, DEFAULT);
  }
  return ans;
}

// SUBSET SUM OPTIMIZED (result in dp[x])
int n, x; cin >> n >> x;
bitset<mn + 1> dp; // static const int mn
dp[0] = 1;
for (int i = 0; i < n; ++i) {
  int v;
  cin >> v;
  dp |= (dp << v);
}
