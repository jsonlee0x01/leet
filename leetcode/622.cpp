#include <queue>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
  MyCircularQueue(int k) {
    capacity = k;
    count = 0;
  }

  bool enQueue(int value) {
    if (count < capacity) {
      q.push(value);
      ++count;
      return true;
    }
    return false;
  }

  bool deQueue() {
    if (count > 0) {
      q.pop();
      --count;
      return true;
    }
    return false;
  }

  int Front() {
    if (count) {
      return q.front();
    }
    return -1;
  }

  int Rear() {
    if (count) {
      return q.back();
    }
    return -1;
  }

  bool isEmpty() { count == 0; }

  bool isFull() { return count == capacity; }
  queue<int> q;
  int capacity;
  int count;
};

// Without queue.
class MyCircularQueue1 {
public:
  MyCircularQueue(int k) {
    q = vector<int>(k);
    capacity = k;
    count = 0;
    front = 0;
    end = 0;
  }

  bool enQueue(int value) {
    if (count < capacity) {
      end = (end + 1) % capacity;
      q[end] = value;
      ++count;
      return true;
    }
    return false;
  }

  bool deQueue() {
    if (count > 0) {
      front = (front + 1) % capacity;
      --count;
      return true;
    }
    return false;
  }

  int Front() {
    if (count) {
      return q[(front + 1) % capacity];
    }
    return -1;
  }

  int Rear() {
    if (count) {
      return q[end - 1];
    }
    return -1;
  }

  bool isEmpty() { return count == 0; }

  bool isFull() { return count == capacity; }
  vector<int> q;
  int capacity;
  int count;
  int front;
  int end;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */