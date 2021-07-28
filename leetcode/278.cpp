// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    if (isBadVersion(1)) {
      return 1;
    }
    long left = 1;
    long right = n;
    long mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (isBadVersion(mid) == true && isBadVersion(left) == false) {
        if (mid == left + 1) {
          return mid;
        } else {
          right = mid;
        }
      } else if (isBadVersion(mid) == false && isBadVersion(right) == true) {
        if (mid + 1 == right) {
          return right;
        } else {
          left = mid;
        }
      }
    }
    return 1;
  }
};