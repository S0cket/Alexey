#include <iostream>
#include <string>

using namespace std;

class Learner {
private:
	string type, name;
public:
	void print() {
		cout << type << " " << name << endl;
	}
	friend class Schoolboy;
	friend class Student;
	friend void print(Learner*, unsigned int, string);
};

class Schoolboy : public Learner {
public:
	Schoolboy() {
		type = "Schoolboy";
		name = "Unknown";
	}
	Schoolboy(string name) {
		type = "Schoolboy";
		this->name = name;
	}
	~Schoolboy() {}
};

class Student : public Learner {
public:
	Student() {
		type = "Student";
		name = "Unknown";
	}
	Student(string name) {
		type = "Student";
		this->name = name;
	}
	~Student() {}
};

void print(Learner *arr, unsigned int n, string type) {
	for (int i = 0; i < n; ++ i)
		if (arr[i].type == type)
			arr[i].print();
}

int main(void) {
	Learner arr[5] = {
		Schoolboy("aaa"),
		Student("bbb"),
		Schoolboy("ccc"),
		Student("ddd"),
		Schoolboy("eee")
	};

	cout << "\nStudents:\n";
	print(arr, 5, "Student");
	cout << "\nSchoolboys:\n";
	print(arr, 5, "Schoolboy");
	return 0;
}