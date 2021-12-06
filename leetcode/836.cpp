#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        int lx1 = rec1[0];
        int ly1 = rec1[1];
        int lx2 = rec1[2];
        int ly2 = rec1[3];
        int rx1 = rec2[0];
        int ry1 = rec2[1];
        int rx2 = rec2[2];
        int ry3 = rec2[3];
        if (lx2 <= rx1 || rx2 <= lx1 || ly1 >= ry2 || ry1 >= ly2) {
            return false;
        }
        return true;
    }
};
