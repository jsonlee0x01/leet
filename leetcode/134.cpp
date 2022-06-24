#include <vector>
#include <algorithm>
using namespace std;

/*
超时版本：
class Solution:
    def canCompleteCircuit(self, gas, cost):
        if sum(gas) < sum(cost):
            return -1
        ln = len(gas)
        for i in range(ln):
            if gas[i] < cost[i]:
                continue
            total = 0
            for j in range(i, i + ln):
                j %= ln
                total += gas[j] - cost[j]
                if total < 0:
                    break
            else:
                return i
        return -1
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int curFuel = 0;
        for (int i = 0; i < gas.size(); ++i) {
            curFuel = gas[i];
            int count = 0;
            int j = i;
            int tmpFuel = curFuel;
            while (count <= gas.size()) {
                if (tmpFuel - cost[j % gas.size()] >= 0) {
                    tmpFuel -= cost[j % gas.size()];
                    tmpFuel += gas[j % gas.size()];
                    ++j;
                    ++count;
                } else {
                    break;
                }
            }
            if (count < gas.size()) {
                continue;
            } else {
                return i;
            }
        }
        return -1;
    }
};

/*
重点就两句话：
1、两个数组之差的总和必须大于等于0，否则不能完成绕行
2、
一个站的收益如果小于0，肯定不能作为起点；而连续的多个站也可以等效地看做一个站，如果其累积收益小于0，就跳过，寻找下一个。
*/
class Solution1 {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0;
        int run = 0;
        int rest = 0;
        for (int i = 0; i < gas.size(); ++i) {
            rest += (gas[i] - cost[i]);
            run += (gas[i] - cost[i]);
            if (run < 0) {
                start = i + 1;
                run = 0;
            }
        }
        return rest < 0 ? -1 : start;
    }
};
