#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in;
    //file with 100 sets of data
    in.open(".\\data_set\\input.txt");
    for (int t = 0; t < 100; t ++) {
        int x;
        in >> x;
        ofstream out;
        //file with 1 set of data (made from input.txt)
        out.open(".\\output.txt");
        out << x << endl;
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
        system(".\\structure_time\\code_.exe < .\\output.txt");
    }
    in.close();
    return 0;
}