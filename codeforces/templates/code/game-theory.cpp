/*
Normal play convention: player who makes the last move wins
Partisan game: available moves are dependent on a player's current state
Impartial game: both players have the same moves at any turn

Nim-sum of a position of the bitwise xor of all pile sizes.
- A Nim position is losing iff the Nim-sum is zero
- Otherwise it is winning

Theorem:
Every impartial game position is equivalent to a Nim heap of some size g.
- g is the Grundy number (Sprague-Grundy value) of the position.

For a position X, moves(X) is the set of available moves:
grundy(X) = mex{grundy(Y) | Y in moves(X)} -- minimum excluded non-negative int
Base:
- grundy(position with no moves) = 0
- grundy(X) = 0 if X is a losing position for the current turn
- grundy(X) != 0 are winning positions

If a position is made up of several independent subgames:
g(X) = g(Y) xor g(Z) xor ...
*/

int mex(const vector<int>& v) {
  int n = v.size();
  vector<char> used(n + 1, 0);
  for (int x : v)
    if (x >= 0 && x <= n) used[x] = 1;
  for (int i = 0; i <= n; ++i)
    if (!used[i]) return i;
  return n;
}

vector<int> sprague(int N, const vector<int>& moves) {
  vector<int> sg(N + 1, 0); // dp with base [0] = 0
  for (int x = 1; x <= N; ++x) {
    vector<int> nxt;
    for (int mv : moves) {
      if (x - mv >= 0) nxt.push_back(sg[x - mv]);
    }
    // grundy = mex{grundy values}
    sg[x] = mex(nxt);
  }
  return sg;
}

int nim_sum(const vector<int>& v) {
  int x = 0;
  for (int g : v) x ^= g;
  return x;
}
