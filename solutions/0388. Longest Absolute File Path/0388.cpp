struct Item {
  int depth;
  size_t length;
};

class Solution {
 public:
  int lengthLongestPath(string input) {
    size_t ans = 0;
    stack<Item> stack{{{-1, 0}}};  // placeholder
    istringstream iss(input);

    for (string token; getline(iss, token, '\n');) {
      const int depth =
          count_if(begin(token), end(token), [](char c) { return c == '\t'; });
      token.erase(remove(begin(token), end(token), '\t'), end(token));
      while (depth <= stack.top().depth)
        stack.pop();
      if (isFile(token))
        ans = max(ans, stack.top().length + token.length());
      else  // directory + '/'
        stack.push({depth, stack.top().length + token.length() + 1});
    }

    return ans;
  }

 private:
  bool isFile(const string& token) {
    return token.find('.') != string::npos;
  }
};