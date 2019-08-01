


// ========================================


string reverseWords(string s) {

  auto reverse = [](string& data, int i, int j) {
    while (i < j) {
      swap(data[i++], data[j--]);
    }
  };

  int left = 0;
  int right = 0;

  reverse(s, 0, s.size() - 1);

  while (right < s.size()) {
    while (right < s.size() && s[right] != ' ') right++;

    reverse(s, left, right - 1);

    right++;
    left = right;
  }

  return s;
}


