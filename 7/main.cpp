#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Vector {
public:
	vector<T> vect;
	Vector() {}
	Vector(vector<T> vect) {
		this->vect = vect;
	}
	T& operator[](int index) {
		return vect[index];
	}
	int operator()() {
		return vect.size();
	}
	Vector<T> operator*(Vector<T> V) {
		int a = vect.size();
		int b = V();
		vector<T> out = vect;
		for (int i = 0; i < min(a, b); ++ i)
			out[i] = vect[i] * V[i];
		return Vector<T>(out);
	}
	~Vector() {}
};

class Time {
private:
	int min, sec;
public:
	Time() {
		min = 0;
		sec = 0;
	}
	Time(int s) {
		min = s / 60;
		sec = s % 60;
	}
	Time(int m, int s) {
		min = m + s / 60;
		sec = s % 60;
	}
	void print() {
		cout << min << ":" << sec << endl;
	}
	~Time() {}
};

void print(Vector<int> v) {
	for (int i = 0; i < v(); ++ i)
		cout << v[i] << " ";
	cout << endl;
}

int main(void) {
	vector<int> a(4, 5), b(10, 10);
	Vector<int> A(a), B(b);
	print(A);
	print(B);
	print(A * B);
	print(B * A);
	return 0;
}