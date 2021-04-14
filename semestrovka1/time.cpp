#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ifstream in;
    in.open(".\\input.txt");
    for (int t = 0; t < 100; t ++) {
        int x;
        in >> x;
        ofstream out;
        out.open(".\\output.txt");
        out << x << endl;
        cout << x << "\t";
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
            //вызов командной строки, ожидание пока программа закончится
            system(".\\code_.exe < .\\output.txt");
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            count += duration.count();
        }
        count = (int) count / 10;
        cout << count << endl;
    }
    in.close();
    return 0;
}
//C:\Users\Olga\CLionProjects\aisd\semestrovka>..\cmake-build-debug\aisd.exe > 1.txt