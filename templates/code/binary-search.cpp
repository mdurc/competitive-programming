// LOWER BOUND
int l = 1, r = n; // both l and r are in the search space
while (l < r) {
  int mid = l + (r - l) / 2;
  // finding the FIRST T in: FFFFFTTTTTTT
  if (cond(mid)) {
    r = mid;
  } else {
    l = mid + 1;
  }
}
return l; // l == r

// UPPER BOUND
int l = 1, r = n; // both l and r are in the search space
while (l < r) {
  int mid = l + (r - l + 1) / 2; // pick right middle element (avoid inf loop)
  // finding the LAST T in: TTTTTTFFFFFF
  if (cond(mid)) {
    l = mid;
  } else {
    r = mid - 1;
  }
}
return l; // l == r
