#include <iostream>
#include <string>

using namespace std;

// #### -> abab
// # -> a
// ## -> ab
// ab#c#a#b## -> abacbacbab
class Solution {
public:
  char getFirstDifferentChar(const char &prev, const char &next) {
    for (int i = 0; i < 26; ++i) {
      char current = 'a' + i;
      if (current != prev && current != next) {
        return current;
      }
    }
    return 'a';
  }

  void replaceStr(string &input) {
    char prev = ' ';
    int i = 0;
    while (i < input.size() - 1) {
      if (input[i] == '#') {
        input[i] = getFirstDifferentChar(prev, input[i + 1]);
      }
      prev = input[i];
      ++i;
    }
    if (input[input.size() - 1] == '#') {
      for (int i = 0; i < 26; ++i) {
        if ('a' + i != prev) {
          input[input.size() - 1] = 'a' + i;
          break;
        }
      }
    }
  }
};

int main() {
  Solution s;
  string in = "####";
  cout << in << endl;
  s.replaceStr(in);
  cout << in << endl;
  in = "#";
  cout << in << endl;
  s.replaceStr(in);
  cout << in << endl;
  in = "##";
  cout << in << endl;
  s.replaceStr(in);
  cout << in << endl;
  in = "ab#c#a#b##";
  cout << in << endl;
  s.replaceStr(in);
  cout << in << endl;
  return 0;
}