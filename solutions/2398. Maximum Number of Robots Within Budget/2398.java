class Solution {
  public int maximumRobots(int[] chargeTimes, int[] runningCosts, long budget) {
    long cost = 0;
    // max queue storing chargeTimes[i]
    Deque<Integer> dq = new ArrayDeque<>();

    int j = 0; // window's range := [i..j], so k = i - j + 1
    for (int i = 0; i < chargeTimes.length; ++i) {
      cost += runningCosts[i];
      while (!dq.isEmpty() && dq.peekLast() < chargeTimes[i])
        dq.pollLast();
      dq.offerLast(chargeTimes[i]);
      if (dq.peekFirst() + (i - j + 1) * cost > budget) {
        if (dq.peekFirst() == chargeTimes[j])
          dq.pollFirst();
        cost -= runningCosts[j++];
      }
    }

    return chargeTimes.length - j;
  }
}
