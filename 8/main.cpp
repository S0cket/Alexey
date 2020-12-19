#include <iostream>
#include <deque>

using namespace std;

class Deque {
private:
	deque<int> d;
	int n;
public:
	Deque() {
		n = 0;
	}

	int operator[](unsigned index) {
		if (index >= d.size()) throw 1;
		return d[index];
	}
	void operator++() {
		d.push_front(n ++);
	}
	void operator++(int) {
		d.push_back(n ++);
	}
	int operator--() {
		if (d.size() == 0) throw 2;
		int out = d.front();
		d.pop_front();
		return out;
	}
	int operator--(int) {
		if (d.size() == 0) throw 2;
		int out = d.back();
		d.pop_back();
		return out;
	}
	void print() {
		for (int i = 0; i < d.size(); ++ i)
			cout << d[i] << " ";
		cout << endl;
	}

	~Deque() {}
};

int main(void) {
	Deque a;
	a++;
	a.print();
	a++;
	a.print();
	a++;
	a.print();
	++a;
	a.print();
	a--;
	a.print();
	--a;
	a.print();
	try {
		a--;a--;a--;
	}
	catch (int) {
		cout << "ERROR!!!!!\n";
	}
	return 0;
}