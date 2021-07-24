#include <stack>
using namespace std;

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int val) {
    if (!stackData.size()) {
      stackMin.push(val);
    } else {
      int currentMin = stackMin.top();
      if (val < currentMin) {
        stackMin.push(val);
      } else {
        stackMin.push(currentMin);
      }
    }
    stackData.push(val);
  }

  void pop() {
    stackMin.pop();
    stackData.pop();
  }

  int top() {
    int topData = stackData.top();
    return topData;
  }

  int getMin() {
    int currentMin = stackMin.top();
    return currentMin;
  }
  stack<int> stackData;
  stack<int> stackMin;
};