// z[i] is the length of the longest substring starting at i that is prefix s
vector<int> z_function(const string& s) {
  int n = s.size();
  vector<int> z(n, 0);
  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i <= R) z[i] = min(R - i + 1, z[i - L]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > R) {
      L = i;
      R = i + z[i] - 1;
    }
  }
  return z;
}

// find all starting indices in text where pattern occurs
vector<int> z_match(const string& text, const string& pattern) {
  string concat = pattern + "#" + text;
  vector<int> z = z_function(concat);
  vector<int> positions;
  int m = pattern.size();
  for (int i = m + 1; i < (int)concat.size(); i++) {
    if (z[i] == m) positions.push_back(i - m - 1);
  }
  return positions;
}

// p[i] is the length of the longest prefix and suffix of s[0..i]
vector<int> prefix_function(const string& s) {
  int n = s.size();
  vector<int> pi(n, 0);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

// find all starting indices in text where pattern occurs
vector<int> kmp_match(const string& text, const string& pattern) {
  int n = text.size(), m = pattern.size();
  if (m == 0) return {};
  vector<int> pi = prefix_function(pattern);
  vector<int> positions;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j > 0 && text[i] != pattern[j]) j = pi[j - 1];
    if (text[i] == pattern[j]) j++;
    if (j == m) {
      positions.push_back(i - m + 1);
      j = pi[j - 1];
    }
  }
  return positions;
}
