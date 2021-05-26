#include <iostream>
#include <vector>
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

void fill() {
    cout << "Enter the number of vertices in the first part" << endl;
    cin >> l;
    cout << "Enter the number of vertices in the second part" << endl;
    cin >> r;
    cout << "Enter adjacency lists of bipartite graph" << endl << endl;
    cout << "for each vertex in the first part enter" << endl;
    cout << "the number of adjacent vertices" << endl;
    cout << "then enter adjacent vertices" << endl;
    for (int i = 0; i < l; i++) {
        int tmp;
        cin >> tmp;
        m += tmp;
        for (int j = 0; j < tmp; j++) {
            int v;
            cin >> v;
            v--;
            g[i].push_back(v);
        }
    }
    //no match yet = -1
    matching.assign(r+l, -1);
}

void solve() {
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
void print() {
    cout << "maximal matching:" << endl;
    cout << mtSize << endl;
    cout << "matched edges:" << endl;
    for (int i = l; i < r+l; ++i)
        if (matching[i] != -1)
            cout << matching[i] + 1 << " - " << i + 1 << endl;
}
int main() {
    fill();
    solve();
    print();
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