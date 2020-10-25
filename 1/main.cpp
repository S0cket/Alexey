#include <iostream>
#include <list>
#include <time.h>

using namespace std;

int main(void) {
	srand(time(NULL));

	int n, m;
	cin >> n >> m;
	list<int> a, b;

	cout << "\na:\n";
	for (int i = 0; i < n; ++ i) {
		int x = rand() % 10;
		a.push_back(x);
		cout << x << " ";
	}

	cout << "\n\nb:\n";
	for (int i = 0; i < m; ++ i) {
		int x = rand() % 10;
		b.push_back(x);
		cout << x << " ";
	}

	for (auto i = a.begin(); i != a.end();) {
		bool flag = true;
		for (auto j = b.begin(); j != b.end(); ++ j) {
			if (*i == *j)
				flag = false;
		}
		if (!flag) {
			a.erase(i);
			i = a.begin();
		}
		else
			++ i;
	}

	cout << "\n\na(new):\n";
	for (auto i = a.begin(); i != a.end(); ++ i)
		cout << *i << " ";
	cout << "\n";
	return 0;
}