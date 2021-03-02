/*
 * P1.cpp
 *
 *  Created on: 2 мар. 2021 г.
 *      Author: Olga
 */
#include <iostream>

using namespace std;

struct elem {
  int val;
  elem* next;
};

elem* empty_list() {
  return NULL;
}

elem* add(elem* head, int x) {
  elem* p = new elem;
  p->val = x;
  p->next = head;
  return p;
}

void print_list(elem* head) {
	elem* p = head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

elem* f1(elem* head, int n) {
	if (n>1) {
		int i = 1;
		int count = 3;
		while (i < n) {
			elem* p = head;
			bool b = true;
			while (p) {
				if ((count % p->val != 0) && b) b=true;
				else b = false;
				p = p->next;
			}
			if (b) {
				head = add(head, count);
				i++;
			}
			count++;
		}
	}
	return head;
}

void reverse_list(elem* out, elem* head) {
	elem* p = head;
	out = add(out, p->val);
	p = p -> next;
}
int main() {
	int n;
	cin >> n;
	elem* head = empty_list();
	head = add(head, 2);
	elem* out = empty_list();
	reverse_list(out,f1(head, n));
	print_list(out);
	return 0;
}



