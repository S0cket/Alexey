#include <iostream>
#include <algorithm>

using namespace std;

class Fraction {
private:
	int n, m;
public:
	Fraction() {
		this->n = 0;
		this->m = 1;
	}
	Fraction(int n, int m) {
		this->n = n;
		this->m = m;
	}

	int getn() {
		return this->n;
	}
	void setn(int n) {
		this->n = n;
	}
	int getm() {
		return this->m;
	}
	void setm(int m) {
		this->m = m;
	}

	void scan() {
		scanf("%d/%d", &this->n, &this->m);
	}
	void print() {
		printf("%d/%d", this->n, this->m);
	}

	void add(Fraction f) {
		if (f.getn() != 0) {
			this->n = this->n * f.getm() + f.getn() * this->m;
			this->m *= f.getm();
			int n = this->n, m = this->m;
			if (m > n)
				swap(n, m);
			if (m != 0) {
				while (n % m != 0) {
					int b = n;
					n = m;
					m = b % m;
				}
				this->n /= m;
				this->m /= m;
			}
		}
	}
};

int main(void) {
	Fraction s, a;
	cout << "Sum:"; s.print(); cout << endl;

	while (true) {
		cout << "Input Fractional(1/1):";
		a.scan();
		s.add(a);
		cout << "Sum:"; s.print(); cout << endl;
		cout << "Continue?(y/n)";
		char c;
		cin >> c;
		if (c != 'y' && c != 'Y')
			break;
	}
}