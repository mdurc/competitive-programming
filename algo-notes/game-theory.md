## Combinatorial Game Theory (Nim & Sprague-Grundy)

> ***Combinatorial game theory applies when there is no chance (no dice), perfect information (no hidden cards), and games are finite.***

### 1. Terminology
* **Impartial game:** both players have the same moves at any turn.
* **Normal play convention:** player who makes the last move wins.
* **Winning state ($W$):** when the current turn player has a forced winning strategy on the current game state.
* **Losing state ($L$):** no matter what the current turn play does, the opponent has a winning strategy.

### 2. Nim Game

- *Two player game with the following properties:*

* **State:** $n$ independent piles of stones: $p_1, p_2, \dots, p_n$, where each pile $p_i \ge 0$.
* **Move:** current turn player may pick one pile $p_i$ and remove $s$ stones ($1 \le s \le p_i$).
* **Condition:** the game ends when there are no more stones left.

$\text{Nim-sum} = G = p_1 \oplus p_2 \oplus \dots \oplus p_n$
* Game state is **Winning** if the Nim-sum is greater than 0.
* Game state is **Losing** if the Nim-sum is exactly 0.

### 3. Deriving the Nim-sum, XOR operator

- **What is the Nim-sum/Nim-value**
  - For each game state, $G$ will represent the Nim-sum that determines if this is a winning or losing state for the current player.
  - Given two game states, $a$, and $b$ with Nim-sums $A$ and $B$ respectively, let $a + b$ be the game state where simply all the piles of $a$ are placed next to all of the piles of $b$.
  - $A \diamond B$ will be the Nim-sum of the game state $a + b$.
      - This is some operator that facilitates the composition of game-states.
      - We are looking for an operator that acts as a [homomorphism](https://en.wikipedia.org/wiki/Homomorphism). Since combining game states $a$ and $b$ is an additive action, we want a function $f$ and an operator $\diamond$ such that $f(a + b) = f(a) \diamond f(b)$.

* **What does a given Nim-sum/Nim-value correspond to?**
  - *We can start by considering a simple game state:* **one pile of $p$ stones.**
      - Since the only information about this game state is the pile with $p$ stones, the Nim-value must be $p$.
      - We don't know if this represents a "winning" or "losing" state, but we know the integer value.
  - Intuitively, we know that $p > 0$ will be a winning state and $p = 0$ will be a losing state.
  - Since $G = p$, we can determine that a Nim-value $G$ corresponds to a winning game state when $G > 0$, and a losing game state when $G = 0$.

- **What is the operator that allows us to compose $G$ from two game states?**
  1. $(A \diamond B) \diamond C = A \diamond (B \diamond C)$: Operator is associative and commutative.
      - When we move piles next to pre-existing piles, ordering doesn't matter.
  2. $A \diamond 0 = A$
      - When a Nim-value is $0$, the Nim-value for the composition should stay the same.
      - In our simple one-pile example, $p = 0$ means a pile of $0$ stones. Adding an empty game to your existing game clearly doesn't change anything.
      - In the general case, a Nim-value of $0$ represents any losing sub-game (like two identical piles). If you add a losing sub-game to your board, it doesn't alter your game state. Whenever your opponent makes a move in that losing sub-game, you simply respond with the counter-move to restore its value to $0$, effectively neutralizing it.
  3. $A \diamond A = 0$
      - If you have two identical piles, the second player will always win. Whatever player 1 does to the first pile, player 2 can simply *mirror* that exact move on the other pile. This means player 2 will take the last stone and win, thus it is a losing state for the current player.


In standard math, a number is canceled by its negative ($A+(−A)=0$). In games, we don't have negative states, so a state must act as its own negative ($A \diamond A = 0$). If we used normal addition, $A + A = 2A$ because values "carry" over to larger magnitudes. To prevent magnitudes from accumulating, we must perform additon-without-carry, aka addition modulo 2, aka **binary-XOR**.

***Proof:***
* **Claim:** Given a game of Nim whose current game state consists of $n$ piles with $p_1, p_2, \dots, p_n$, the current game state is a winning state if the Nim-sum of the piles $G = p_1 \oplus p_2 \oplus \dots \oplus p_n$ is non-zero, and a losing state if it is equal to zero.
* After a given move, the new sum is: $(p_1 \oplus p_2 \oplus \dots \oplus p_n) \oplus p_i \oplus (p_i - s)$
1. The empty game is a losing state with a Nim-sum of $0$.
2. If $G = 0$, then any valid move will make it non-zero. The new sum must be $0 \oplus p_i \oplus (p_i - s)$, and since $1 \le s \le p_i$, the term $p_i \oplus (p_i - s)$ cannot be $0$. Thus, the new sum is non-zero.
3. If $G > 0$, then there is always a move to make it equal $0$. The new sum must be $G \oplus p_i \oplus (p_i - s)$, thus we need $p_i \oplus (p_i - s) = G$ for this new Nim-sum to equal zero. We know that since $G$ is non-zero, it must have a Most Significant Bit (MSB), let's call it the $g$-th bit. Thus, there must exist at least one pile $p_i$ where the $g$-th bit is also set (due to $G$ being the XOR-sum of all $p_j$). We can choose one of these piles as $p_i$ and construct the new pile size $(p_i - s)$ as follows:
    * All bits greater than the $g$-th bit stay the same.
    * The $g$-th bit is set to zero.
    * All bits less than the $g$-th bit are set to match $G \oplus p_i$.


### 4. Generalizing: Sprague-Grundy Theorem

The Sprague-Grundy Theorem states: **Every impartial game under normal play is mathematically equivalent to a single Nim pile of a specific size.**

* This "size" is called the **Grundy value** (or nim-value) of the game state.
  * If a game state has a Grundy value of $G$, it behaves *exactly* like a Nim pile of $G$ stones.
  * Therefore, a game state is a winning state if $G > 0$, and a losing state if $G = 0$.

> If a game consists of multiple **independent** sub-games, you find the Grundy value of each sub-game individually and simply XOR them together to find the Grundy value of the entire board (Nim-sum).
> **Rule:** sub-games must be completely independent. A move in sub-game A cannot alter the available moves in sub-game B.

### 5. Finding Grundy Values

To find the Grundy value of a game state, model the game as a *Directed Acyclic Graph (DAG)* where vertices are game states and directed edges are valid moves. Terminal states (vertices with no outgoing edges) are losing states because the current player has no valid moves left to make.

* We calculate the Grundy value $G(u)$ of a state $u$ using the **Minimum Excluded (MEX)** function.
* The MEX of a set of integers is the smallest non-negative integer strictly not present in the set.
  * $\text{mex}(\{0, 1, 3\}) = 2$
  * $\text{mex}(\{1, 2\}) = 0$

**Algorithm:**
1. Let $u$ be the current game state.
2. Let $v_1, v_2, \dots, v_k$ be the adjacencies of $u$.
3. $G(\text{terminal}) = \text{mex}(\{\}) = 0$
4. $G(u) = \text{mex}(\{G(v_1), G(v_2), \dots, G(v_k)\})$

### Resources
* https://codeforces.com/blog/entry/66040
