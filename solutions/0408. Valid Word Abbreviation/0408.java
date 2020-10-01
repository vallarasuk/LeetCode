class Solution {
  public boolean validWordAbbreviation(String word, String abbr) {
    int i = 0; // word's pointer
    int j = 0; // abbr's pointer

    while (i < word.length() && j < abbr.length()) {
      if (word.charAt(i) == abbr.charAt(j)) {
        ++i;
        ++j;
        continue;
      }
      if (abbr.charAt(j) <= '0' || abbr.charAt(j) > '9')
        return false;
      int num = 0;
      while (j < abbr.length() && Character.isDigit(abbr.charAt(j))) {
        num = num * 10 + abbr.charAt(j) - '0';
        if (num == 0)
          return false;
        ++j;
      }
      i += num;
    }

    return i == word.length() && j == abbr.length();
  }
}