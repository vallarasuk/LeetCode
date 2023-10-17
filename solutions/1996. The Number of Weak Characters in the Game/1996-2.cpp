class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    int ans = 0;
    const int maxAttack = (*ranges::max_element(
        properties, [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    }))[0];
    // maxDefenses[i] := max defense for i attack.
    vector<int> maxDefenses(maxAttack + 2);

    for (const vector<int>& property : properties) {
      const int attack = property[0];
      const int defense = property[1];
      maxDefenses[attack] = max(maxDefenses[attack], defense);
    }

    for (int i = maxAttack; i >= 1; --i)
      maxDefenses[i] = max(maxDefenses[i], maxDefenses[i + 1]);

    for (const vector<int>& property : properties) {
      const int attack = property[0];
      const int defense = property[1];
      if (maxDefenses[attack + 1] > defense)
        ++ans;
    }

    return ans;
  }
};
