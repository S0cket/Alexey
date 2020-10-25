#include <iostream>
#include <set>
#include <stdlib.h>
#include <time.h>

using namespace std;

void setout(set<float> s) {
	for (auto it = s.begin(); it != s.end(); it ++) cout << *it << " ";
	cout << "\n";
}

int main(void) {
	srand(time(NULL));

	int size;
	cout << "Input length: ";
	cin >> size;

	set<float> myset;
	for (int i = 0; i < size; i ++) myset.insert(rand() % 100);
	setout(myset);

	int mn = *(myset.begin());
	cout << "Min: " << mn << endl;
	
	double s = 0;
	for (auto it = myset.begin(); it != myset.end(); it ++) s += *it;
	s /= size;
	cout << "Srednee: " << s << endl;
	while (!myset.empty() && *(--myset.end()) > s)
		myset.erase(--myset.end());
	setout(myset);

	int mx = *(--myset.end());
	cout << "Max: " << mx << endl;
	set<float> buf = myset;
	myset.clear();
	for (auto it = buf.begin(); it != buf.end(); it ++)
		myset.insert(*it * mx);
	setout(myset);

	return 0;
}