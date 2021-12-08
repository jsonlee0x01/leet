#include <cstddef>
#include <vector>
#include <pair>
#include <string>
using namespace std;

// 设计题，设计Excel求和公式
class Excel {
public:
    Excel(int H, char W)
    {
        data.clear();
        int rows = H;
        int cols = W - 'A' + 1;
        /*for (int i = 0; i < rows; ++i) {
            data.push_back(vector(cols, 0));
        }*/
        data.resize(rows, vector<int>(cols, 0));
    }

    void set(int r, char c, int v)
    {
        if (m.count({r, c})) {
            m.erase({r, c});
        }
        int rowIdx = r - 1;
        int colIdx = c - 'A';
        data[rowIdx][colIdx] = v;
    }

    int get(int r, char c)
    {
        if (m.count({r, c})) {
            return sum(r, c, m[{r, c}]);
        }
        int rowIdx = r - 1;
        int colIdx = c - 'A';
        return data[rowIdx][colIdx];
    }

    int sum(int r, char c, vector<string> strs)
    {
        int ans = 0;
        for (int i = 0; i < strs.size(); ++i) {
            auto pos = strs[i].find_last_of(":");
            if (pos == string::npos) {
                char c = strs[i][0];
                int r = stoi(strs[i].substr(1));
                ans += get(r, c);
            } else {
                char cStart = strs[i][0];
                int rStart = stoi(strs[i].substr(1, pos - 1));
                char cEnd = strs[i][pos + 1];
                int rEnd = stoi(strs[i].substr(pos + 2));
                for (int j = rStart; j <= rEnd; ++j) {
                    for (int k = cStart - 'A'; k <= cEnd - 'A'; ++k) {
                        ans += get(j, k + 'A');
                    }
                }
            }
        }
        m[{r, c}] = strs;
        return ans;
    }

private:
    vector<vector<int>> data;
    map<pair<int, char>, vector<string>> m;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(H, W);
 * obj->set(r,c,v);
 * int param_2 = obj->get(r,c);
 * int param_3 = obj->sum(r,c,strs);
 */
