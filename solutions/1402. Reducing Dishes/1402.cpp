class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    int ans = 0;
    int sumSatisfaction = 0;

    sort(satisfaction.begin(), satisfaction.end(), greater<>());

    for (const int s : satisfaction) {
      sumSatisfaction += s;
      if (sumSatisfaction <= 0)
        return ans;
      ans += sumSatisfaction;
    }

    return ans;
  }
};
