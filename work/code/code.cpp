#include <iostream>
#include <list>
using namespace std;

const int N = 10000;
struct BloomFilter {
	const int numberOfCells = 1024;
	list<int(*)(int)> hashFunctions;
	bool* cell;
};

void addElement(int const& x, BloomFilter bf) {
	for (auto iter = bf.hashFunctions.begin(); iter != bf.hashFunctions.end(); ++iter) {
		bf.cell[(*iter)(x) % bf.numberOfCells] = true;
		//cout << (*iter)(x) % bf.numberOfCells << endl;
	}
}

bool checkElement(int const& x, BloomFilter bf) {
	bool intInSet = true;
	for (auto iter = bf.hashFunctions.begin(); iter != bf.hashFunctions.end(); ++iter) {
		//cout << (*iter)(x) % bf.numberOfCells << endl;
		if (!bf.cell[(*iter)(x) % bf.numberOfCells]) {
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
	//empty(bf);

	// insert numbers into the filter
	// possible input: positive numbers and 0
	// -1 is the end of input
	int x;
	cin >> x;
	while (x != -1) {
		addElement(x, bf);
		cin >> x;
	}
	cout << "Bloom filter has filled" << endl;
	cout << "check if element was present in set" << endl;
	// testing numbers against the bloom filter
	// possible input: positive numbers and 0
	// -1 is the end of input
	int y;
	cin >> y;
	while (y != -1) {
		if (!checkElement(y, bf))
			cout << y << " surely is not present" << endl;
		else cout << y << " was probably present" << endl;
		cin >> y;
	}
	return 0;
}
