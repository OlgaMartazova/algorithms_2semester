#include <iostream>
#include <list>
using namespace std;

const int N = 10000;
struct BloomFilter {
	const int numberOfCells = 1024;
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
	return (5*x + 3);
}

int hash4(int x) {
	return (7*x - 8);
}
int main() {
	list<int(*)(int)> hashFunctions;
	hashFunctions.push_back(hash1);
	hashFunctions.push_back(hash2);
	hashFunctions.push_back(hash3);
	hashFunctions.push_back(hash4);

	BloomFilter bf;
	bf.hashFunctions = hashFunctions;
	//init
	bool cells[N];
	for (int i = 0; i < bf.numberOfCells; i ++) {
	    cells[i] = false;
	}
	bf.cell = cells;

	// insert numbers into the filter
	// possible input: positive numbers and 0
	// -1 is the end of input
	int x;
	cin >> x;
	while (x != -1) {
		addItem(x, bf);
		cin >> x;
	}
	cout << "Bloom filter has filled" << endl;
	cout << "Check if an item was present in set" << endl;

	// testing numbers against the bloom filter
	// possible input: positive numbers and 0
	// -1 is the end of input
	int y;
	cin >> y;
	while (y != -1) {
		if (!checkItem(y, bf))
			cout << y << " surely is not present" << endl;
		else cout << y << " was probably present" << endl;
		cin >> y;
	}
	return 0;
}
