class Solution {
 public:
  int longestString(int x, int y, int z) {
    //"AB" can always be easily appended within the string.
    // Alternating "AA" and "BB" can be appended, creating a pattern like "AABB"
    // If x == y, we repeat the pattern "AABBAABB...AABB".
    // If x != y, the pattern becomes "AABBAABB...AABBAA" or "BBAABBAABB...AABB"
    const int mn = min(x, y);
    if (x == y)
      return (mn * 2 + z) * 2;
    return (mn * 2 + 1 + z) * 2;
  }
};
