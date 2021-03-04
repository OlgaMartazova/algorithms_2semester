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

void reverse_print(elem* head) {
	elem* cur = head;
	elem* prev = NULL;
	elem* next = NULL;
	while (cur) {
		next = cur->next;
		cur->next = prev;
		//ñäâèã
		prev = cur;
		cur = next;
	}
	head = prev;

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

int main() {
	int n;
	cin >> n;
	elem* head = empty_list();
	head = add(head, 2);
	reverse_print(f1(head, n));
	return 0;
}



