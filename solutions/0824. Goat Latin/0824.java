class Solution {
  public String toGoatLatin(String S) {
    String ans = "";
    String vowels = "aeiouAEIOU";
    String[] words = S.split(" ");
    int i = 1;

    for (final String word : words) {
      if (i > 1)
        ans += " ";
      if (vowels.contains("" + word.charAt(0)))
        ans += word;
      else
        ans += word.substring(1) + word.charAt(0);
      ans += "ma" + new String(new char[i++]).replace('\0', 'a');
    }

    return ans;
  }
}