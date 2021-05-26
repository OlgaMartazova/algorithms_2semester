#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
int l, r, m;
const int N = 1000;
vector<int>g[N]; //bipartite graph with edges only from the first part to the second
vector<int> matching; //which vertex is matched with the vertex of the second part
vector<bool> used;
int mtSize = 0;

bool try_kuhn(int from) {
    if (used[from])
        return false;
    used[from] = true;
    for (int to : g[from]) {
        if (matching[to] == -1 || try_kuhn(matching[to])) {
            // if vertex is single, matched
            // if vertex has matched, then you can match it
            // only when you can find some other vertex from its current vertex mt[to]
            matching[to] = from;
            return true;
        }
    }
    return false;
}

void solve() {
    matching.assign(r+l, -1);
    vector<bool> used_first(l, false);
    for (int v = 0; v < l; ++v) {
        for (int to : g[v]) {
            if (matching[to] == -1) {
                //add matching
                matching[to] = v;
                mtSize++;
                used_first[v] = true;
                break;
            }
        }
    }
    for (int v = 0; v < l; ++v) {
        if (used_first[v]) continue;
        //start depth-first search
        used.assign(l, false);
        if (try_kuhn(v)) mtSize ++;
    }
}

class Timer
{
private:
    using clock_t = std::chrono::steady_clock;
    using microsecond_t = std::chrono::duration<double, std::ratio<1, 1000000> >;

    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
    {}

    double elapsed() const
    {
        return std::chrono::duration_cast<microsecond_t>(clock_t::now() - m_beg).count();
    }
};

int main() {
    ifstream in;
    in.open("..\\data_set\\input.txt");

    ofstream out;
    out.open(".\\result.txt");

    for (int i=0; i<100; i++) {
        in >> l;
        in >> r;
        for (int j = 0; j < l; j++) {
            int tmp;
            in >> tmp;
            m += tmp;
            for (int k = 0; k < tmp; k++) {
                int v;
                in >> v;
                v--;
                g[i].push_back(v);
            }
        }
        Timer t;
        solve();
        out << l+r << "\t" <<m<< "\t" << t.elapsed() << endl;
    }
    in.close();
    out.close();
    return 0;
}
/**
example
4
5
4 5 6 8 9
1 5
3 6 7 8
2 6 8

answer is:
 4
 2 - 5
 1 - 6
 3 - 7
 4 - 8
*/