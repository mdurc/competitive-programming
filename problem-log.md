**`Problem ID  | Rating | Topics | Status | Time | Difficulty | Attempts`**

- [1898C](https://codeforces.com/contest/1898/problem/C) | 1700 | constructive | solved | 54 | 6 | 1
    - Exactly the type of problem that I often struggle with. Persevered with some pen and paper, came up with a heuristic, and it turned out to be correct. The hardest part was printing out the output format.
- [1849D](https://codeforces.com/contest/1849/problem/D) | 1700 | constructive | solved | 50 | 3 | 2
    - Much less cognitive overhead compared to the last. Mostly because the problem statement was simpler. I figured out the primary heuristic but not the complete version until the second attempt. Was going to ask for a hint but decided to stick to it.
- [1846F](https://codeforces.com/contest/1846/problem/F) | 1800 | constructive, interactive | solved | 25 | 2 | 2
    - Interactive problem, forgot to output 1-based indexing
- [1842D](https://codeforces.com/contest/1842/problem/D) | 1900 | constructive, graphs | solved | 45 | 8 | 1
    - Took a while to discover the graph approach

---

```dataview
TABLE WITHOUT ID
  length(rows) AS "\# Problems",
  sum(rows.Time) + "m" AS "Total Time",
  round(sum(rows.Time) / length(filter(rows.Time, (t) => t)), 1) + "m" AS "Avg Time",
  round(sum(rows.Rating) / length(filter(rows.Rating, (r) => r)), 0) AS "Avg Rating",
  round(sum(rows.Diff) / length(filter(rows.Diff, (d) => d)), 1) AS "Avg Difficulty",
  length(filter(rows.Status, (s) => contains(s, "solved"))) AS "\# Solved",
  length(filter(rows.Status, (s) => contains(s, "assisted"))) AS "\# Assisted",
  length(filter(rows.Status, (s) => contains(s, "unsolved"))) AS "\# Unsolved",
  length(filter(rows.Status, (s) => contains(s, "todo"))) AS "\# To-Do"
FROM "problem-log.md"
FLATTEN file.lists AS Item
WHERE contains(Item.text, " | ")
FLATTEN list(split(Item.text, " \| ")) AS Parts
FLATTEN number(Parts[1]) AS Rating
FLATTEN Parts[3] AS Status
FLATTEN number(Parts[4]) AS Time
FLATTEN number(Parts[5]) AS Diff
GROUP BY true
```
```dataview
TABLE WITHOUT ID
  Parts[0] AS "Problem ID",
  number(Parts[1]) AS "Rating",
  Parts[2] AS "Topics",
  Parts[3] AS "Status",
  number(Parts[4]) + "m" AS "Time",
  number(Parts[5]) AS "Difficuly",
  number(Parts[6]) AS "Attempts"
FROM "problem-log.md"
FLATTEN file.lists AS Item
WHERE contains(Item.text, " | ")
FLATTEN list(split(Item.text, " \| ")) AS Parts
```
