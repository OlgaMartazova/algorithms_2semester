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
	// ввод количества чисел в множестве
	int n;
	cin >> n;
	bf.numberOfCells = round (5 * n / log(2));
	bool cells[N];
	for (int i = 0; i < bf.numberOfCells; i ++) {
	    cells[i] = false;
	}
	bf.cell = cells;
	int count = 0;
	// ввод чисел - элементов множества
	// доступный ввод - натуральные числа и 0
	int x;
	while (count < n) {
		cin >> x;
		addItem(x, bf);
		count ++;
	}
	cout << "Bloom filter has filled" << endl;
	cout << "Check if an item was present in set" << endl;

	// ввод чисел для проверки на отсутствие в множестве
	// доступный ввод - натуральные числа и 0
	// -1 - признак конца ввода
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
//Задача: проверить число на отсутствие в множестве чисел
//вводится число n - количество чисел в множестве
//вводится n чисел - элементы множества
//вводятся числа для проверки
//ввод оканчивается -1
