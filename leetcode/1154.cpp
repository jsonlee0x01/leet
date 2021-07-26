#include <map>
#include <string>
using namespace std;

// YYYY-MM-DD
class Solution {
public:
  int dayOfYear(string date) {
    map<int, int> monthDays{{1, 31},  {3, 31},  {4, 30}, {5, 31},
                            {6, 30},  {7, 31},  {8, 31}, {9, 30},
                            {10, 31}, {11, 30}, {12, 31}};
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    int count = 0;
    int febDays = 0;
    if (year % 4 == 0) {
      monthDays[2] = 29;
    } else {
      monthDays[2] = 28;
    }
    // 月偏移
    for (int i = 0; i < month - 1; ++i) {
      count += monthDays[i + 1];
    }
    count += day;
    return count;
  }
};