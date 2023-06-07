class Solution {
  public int countGoodSubsequences(String s) {
    // For each frequency f in [1, max(freq)], start with "" and calculate how
    // many subseqs can be finalructed with each letter's frequency = f.
    //
    // E.g., s = "abb", so f = max(freq) = 2.
    //
    // For f = 1, with 1 way to build "", choose any 'a' to finalruct a good
    // subseq, so # of good subseqs = 1 + 1 * (1, 1) = 2 ("", "a"). Next, add
    // 'b' and # of good subseqs = 2 + 2 * (2, 1) = 6 ("", "a", "b1", "b2",
    // "ab1", "ab2"). So, the # of good subseqs for f = 1 is 5 since we need to
    // exclude "".
    //
    // For f = 2, with 1 way to build "", choose any two 'b's to finalruct a
    // good subseq, so # of good subseqs = 1 + 1 * (2, 2) is 2 ("", "bb"). So,
    // the # of good subseqs for f = 2 = 1 since we need to exclude "".
    //
    // Therefore, the # of good subseqs for "aab" = 5 + 1 = 6.
    final int kMod = 1_000_000_007;
    int ans = 0;
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    final int maxFreq = Arrays.stream(count).max().getAsInt();
    long[] fact = new long[maxFreq + 1];
    long[] invFact = new long[maxFreq + 1];
    getFactAndInvFact(maxFreq, kMod, fact, invFact);

    for (int freq = 1; freq <= maxFreq; ++freq) {
      long numSubseqs = 1; // ""
      for (final int charFreq : count)
        if (charFreq >= freq)
          numSubseqs = (numSubseqs + numSubseqs * nCk(charFreq, freq, fact, invFact, kMod)) % kMod;
      ans += numSubseqs - 1; // Minus ""
      ans %= kMod;
    }

    return (int) ans;
  }

  private int nCk(int n, int k, long[] fact, long[] invFact, int kMod) {
    return (int) (fact[n] * invFact[k] % kMod * invFact[n - k] % kMod);
  }

  private void getFactAndInvFact(int n, int kMod, long[] fact, long[] invFact) {
    long[] inv = new long[n + 1];
    fact[0] = invFact[0] = 1;
    inv[0] = inv[1] = 1;

    for (int i = 1; i <= n; ++i) {
      if (i >= 2)
        inv[i] = kMod - kMod / i * inv[kMod % i] % kMod;
      fact[i] = fact[i - 1] * i % kMod;
      invFact[i] = invFact[i - 1] * inv[i] % kMod;
    }
  }
}
