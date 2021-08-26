#include <vector>
#include <queue>
using namespace std;

class RecentCounter {
public:
    RecentCounter()
    {
        count = 0;
    }

    int ping(int t)
    {
        ReqQue.push(t);
        ++count;
        int delta = t - 3000;
        while (!ReqQue.empty()) {
            int ReqFront = ReqQue.front();
            if (ReqFront < delta) {
                ReqQue.pop();
                --count;
            } else {
                break;
            }
        }
        return count;
    }
    queue<int> ReqQue;
    int count;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
