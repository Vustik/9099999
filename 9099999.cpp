#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// №1 Додати стовпець
void addCol(vector<vector<int>>& m, int pos, const vector<int>& col) {
    for (int i = 0; i < m.size(); ++i) {
        m[i].insert(m[i].begin() + pos, col[i]);
    }
}

// №2 Видалити стовпець
void delCol(vector<vector<int>>& m, int pos) {
    for (int i = 0; i < m.size(); ++i) {
        m[i].erase(m[i].begin() + pos);
    }
}

// №3 Зсув
void shift(vector<vector<int>>& m, int t, const string& dir) {
    t %= dir == "row" ? m.size() : m[0].size();
    if (dir == "row") {
        for (int k = 0; k < t; ++k) {
            vector<int> last = m.back();
            for (int i = m.size() - 1; i > 0; --i) m[i] = m[i - 1];
            m[0] = last;
        }
    }
    else {
        for (int k = 0; k < t; ++k) {
            vector<int> last(m.size());
            for (int i = 0; i < m.size(); ++i) last[i] = m[i].back();
            for (int j = m[0].size() - 1; j > 0; --j) {
                for (int i = 0; i < m.size(); ++i) m[i][j] = m[i][j - 1];
            }
            for (int i = 0; i < m.size(); ++i) m[i][0] = last[i];
        }
    }
}

// №4 Унікальні і спільні значення
void fill(vector<vector<int>>& m, int r, int c) {
    m.resize(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            m[i][j] = rand() % 21 - 10;
        }
    }
}

vector<int> unique(const vector<vector<int>>& a, const vector<vector<int>>& b, const vector<vector<int>>& c) {
    vector<int> res;
    for (const auto& m : { a, b, c }) {
        for (const auto& row : m) {
            for (int x : row) {
                if (find(res.begin(), res.end(), x) == res.end()) res.push_back(x);
            }
        }
    }
    return res;
}

vector<int> common(const vector<vector<int>>& a, const vector<vector<int>>& c) {
    vector<int> res;
    for (const auto& row : a) {
        for (int x : row) {
            for (const auto& crow : c) {
                if (find(crow.begin(), crow.end(), x) != crow.end() && find(res.begin(), res.end(), x) == res.end()) {
                    res.push_back(x);
                }
            }
        }
    }
    return res;
}

vector<int> negatives(const vector<vector<int>>& a, const vector<vector<int>>& b, const vector<vector<int>>& c) {
    vector<int> res;
    for (const auto& m : { a, b, c }) {
        for (const auto& row : m) {
            for (int x : row) {
                if (x < 0 && find(res.begin(), res.end(), x) == res.end()) res.push_back(x);
            }
        }
    }
    return res;
}

int main() {
    srand(time(0));
    vector<vector<int>> a, b, c;
    int ra, ca, rb, cb, rc, cc;
    cin >> ra >> ca >> rb >> cb >> rc >> cc;
    fill(a, ra, ca);
    fill(b, rb, cb);
    fill(c, rc, cc);

    vector<int> u = unique(a, b, c);
    vector<int> cmn = common(a, c);
    vector<int> neg = negatives(a, b, c);

    for (int x : u) cout << x << " ";
    cout << endl;
    for (int x : cmn) cout << x << " ";
    cout << endl;
    for (int x : neg) cout << " " << x;
    cout << endl;
}
