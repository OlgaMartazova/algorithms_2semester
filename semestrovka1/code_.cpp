#include <iostream>
#include <list>
#include <cmath>
using namespace std;

const int N = 100000;
struct BloomFilter {
    int numberOfCells;
    list<int(*)(int)> hashFunctions;
    bool* cell;
};

void addItem(int const& x, BloomFilter bf) {
    for (auto it = bf.hashFunctions.begin(); it != bf.hashFunctions.end(); ++it) {
        bf.cell[(*it)(x) % bf.numberOfCells] = true;
    }
}

bool checkItem(int const& x, BloomFilter bf) {
    bool intInSet = true;
    for (auto it = bf.hashFunctions.begin(); it != bf.hashFunctions.end(); ++it) {
        if (!bf.cell[(*it)(x) % bf.numberOfCells]) {
            intInSet = false;
            break;
        }
    }
    return intInSet;
}

int hash1(int x) {
    return x;
}

int hash2(int x) {
    return (3*x + 5);
}

int hash3(int x) {
    return (5*x + 7);
}

int hash4(int x) {
    return (7*x + 11);
}

int hash5(int x) {
    return (13*x + 17);
}

int main() {
    list<int(*)(int)> hashFunctions;
    hashFunctions.push_back(hash1);
    hashFunctions.push_back(hash2);
    hashFunctions.push_back(hash3);
    hashFunctions.push_back(hash4);
    hashFunctions.push_back(hash5);

    BloomFilter bf;
    bf.hashFunctions = hashFunctions;
    // enter the number of items in the filter
    int n;
    cin >> n;
    bf.numberOfCells = round (5 * n / log(2));
    bool cells[N];
    for (int i = 0; i < bf.numberOfCells; i ++) {
        cells[i] = false;
    }
    bf.cell = cells;
    int count = 0;
    // enter numbers into the filter
    // possible input: positive integer and 0
    int x;
    while (count < n) {
        cin >> x;
        addItem(x, bf);
        count ++;
    }
    //cout << "Bloom filter has filled" << endl;
    //cout << "Check if an item was present in set" << endl;

    // testing numbers against the bloom filter
    // possible input: positive integer and 0
    // -1 is the end of input
    int y;
    cin >> y;
    while (y != -1) {
        if (!checkItem(y, bf)){}
             //cout << y << " surely is not present" << endl;
        //else cout << y << " was probably present" << endl;
        cin >> y;
    }
    return 0;
}
//task - testing that the number was not in the set
//enter n - number of elements in set
//enter n numbers of the set
//possible numbers - positive integer and 0
//enter number to test
//-1 indicates the end of the input