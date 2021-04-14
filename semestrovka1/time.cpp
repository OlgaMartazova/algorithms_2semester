#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ifstream in;
    //file with 100 sets of data
    in.open(".\\input.txt");
    ofstream res;
    //file with two columns: number of elements in each set of data
    //and average execution time
    res.open(".\\1.txt");
    for (int t = 0; t < 100; t ++) {
        int x;
        in >> x;
        ofstream out;
        //file with 1 set of data (made from input.txt)
        out.open(".\\output.txt");
        out << x << endl;
        res << x << "\t";
        for (int i = 0; i < x; i++) {
            int y;
            in >> y;
            out << y << endl;
        }
        while (x != -1) {
            in >> x;
            out << x << endl;
        }
        out.close();
        double count = 0;
        for (int l = 0; l < 10; l ++) {
            auto start = high_resolution_clock::now();
            system(".\\code_.exe < .\\output.txt");
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            count += duration.count();
        }
        count = (int) count / 10;
        res << count << endl;
    }
    in.close();
    res.close();
    return 0;
}