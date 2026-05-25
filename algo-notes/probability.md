## Probability & Expected Value

### Modular Probability
- Because probabilities and expected values are fundamentally fractions $\frac{P}{Q}$, we must represent them as integers.
    - Always maintain your probabilities as modular integers from the ground up. Never use `double` and try to convert it at the end.
- We do this by calculating $P \cdot Q^{-1} \pmod M$, where $Q^{-1}$ is the [modular multiplicative](modular-arithmetic.md) inverse of $Q$.

### Properties
- $0 \leq P(X = x) \leq 1$
- $\sum_{x} P(X = x) = 1$

> **Conditional Probability:** The probability of event $A$ occurring given that event $B$ has already occurred.
- $P(A|B) = \frac{P(A \cap B)}{P(B)}$

> **Standard Independence:** Two events are independent if the occurrence of one does not affect the probability of the other.
- $P(A \cap B) = P(A) \cdot P(B)$

> **Condtional Independence:** Two events $A$ and $B$ might be independent *only* when conditioned on a third event $C$.
- $P(A \cap B | C) = P(A|C) \cdot P(B|C)$

> **Law of Total Probability:** $P(A) = \sum_{i=1}^{n} P(A|B_i) \cdot P(B_i)$
- $P(A) = P(A | B)P(B) + P(A|\neg B)P(\neg B)$

> **Bayes' Theorem:** $P(A|B) = \frac{P(B|A) \cdot P(A)}{P(B)}$
- If $P(B)$ is not directly given, it can be computed via the Law of Total Probability: $P(A|B) = \frac{P(B|A) \cdot P(A)}{P(B | A)P(A) + P(B|\neg A)P(\neg A)}$


### Expected Value ($E[X]$)
- The expected value of a random variable $X$ is the probability-weighted average of all possible outcomes.
- If $x_i$ is an outcome and $P(x_i)$ is its probability: $E[X] = \sum x_i \cdot P(x_i)$

> **Linearity of Expectation:** The expected value of a sum is the sum of the expected values, *even if the events are dependent*.
- $E[A + B] = E[A] + E[B]$
- **Intuition:** If a problem asks for the expected number of matching pairs, connected components, or inversions, calculating the probability of the *entire* complex state is usually impossible. Instead, break the expected value down into individual indicator variables (e.g., $E[X_i] = 1$ if index $i$ matches, $0$ otherwise). You can calculate the probability of each small event in isolation and simply sum them up.

**Expected Value DP:**
- Expected value problems are frequently solved using [Dynamic Programming](dynamic-programming.md). Expected value DP often naturally defines the state from the *current* state moving towards the *target* state.
- Let $E[i]$ be the expected number of steps to reach the end state $N$ from state $i$.
    - **Base Case:** $E[N] = 0$ (It takes 0 steps to reach the end if you are already there).
    - **Transition:** $E[i] = 1 + \sum (P(j) \cdot E[j])$ for all reachable states $j$.

*Note: You must add $1$ because taking a step costs $1$ move.*

### Geometric Distribution
- **If an event has a probability $p$ of succeeding, the expected number of trials needed to get the first success is $\frac{1}{p}$.**
```cpp
// E[i] = expected steps to reach N from i
// p = probability of moving forward, (1-p) = probability of staying
// E[i] = 1/p + E[i+1]

vector<long long> E(N + 1, 0);
long long prob_forward = divide(P, Q); // 1/6 for a dice roll
long long inv_p = modInverse(prob_forward); 

E[N] = 0; // base case
for (int i = N - 1; i >= 0; i--) {
  E[i] = add(inv_p, E[i + 1]);
}
```
