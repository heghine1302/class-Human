#include<iostream>
#include<string>
using namespace std;

class Human
{
public:
	string name;
	string sex;
	int age;

	Human()
	{
		cout << "Constructor of Human" << endl;
		name = "Heghine";
		sex = "F";
		age = 19;
	}

	Human(string name, string sex, int age)
	{
		this->name = name;
		this->sex = sex;
		this->age = age;
	}

	void HumanPrint() 
	{
		cout << "Name ---- " << name << "\nSex ---- " << sex << "\nAge ---- " << age << endl<<endl;
	}
	void cinHuman() 
	{
		cout << "Name --> ";
		cin >> name;
		cout << "Sex --> ";
		cin >> sex;
		cout << "Age --> ";
		cin >> age;

		cout << endl;
	}
	virtual ~Human() {
		cout << "Destructor of Human" << endl;
		system("pause");
	}
};

class Student : virtual public Human
{
private:
	int group;
	int ID;

public:
	Student(){
		cout << "Constructor of Student" << endl;
		group = 807;
		ID = 1302;
	}

	Student(const int&_group, const int&_ID) : Human(name, sex, age)
	{
		this->group = group;
		this->ID = ID;
	}

	void Learn() 
	{
		cout << "I'm a student" << endl;
	}

	void HumanPrint() 
	{
		cout << "Group ---- " << group << "\nID ---- " << ID << endl;
		Human::HumanPrint();
	}

	void cinHuman() 
	{
		cout << "Group --> ";
		cin >> group;
		cout << "ID --> ";
		cin >> ID;

		Human::cinHuman();
	}

	virtual ~Student() {
		cout << "Destructor of Student" << endl;
		system("pause");
	}

	void doSmth() {
		Human*p = new Student;
		delete p;
	}
};

class Professor : virtual public Human
{
private:
	string subject;

public:
	Professor()
	{
		cout << "Constructor of Professor" << endl;
		subject = "Math";
	}

	Professor(const string&_subject) : Human(name, sex, age)
	{
		this->subject = subject;
	}
	
	void HumanPrint()
	{
		cout << "Subject ---- " << subject<<endl;
		Human::HumanPrint();
	}

	void cinHuman() {
		cout << "Subject --> ";
		cin >> subject;

		Human::cinHuman();
	}
	virtual ~Professor() {
		cout << "Destructor of Professor" << endl;
		system("pause");
	}

	void doSmth() {
		Human* p = new Professor;
		delete p;
	}

};

int main() {

	Student s;
	s.doSmth();
	s.Learn();
	s.cinHuman();
	s.HumanPrint();

	Professor p;
	p.doSmth();
	p.cinHuman();
	p.HumanPrint();

	Human h;
	h.cinHuman();
	h.HumanPrint();
	
	system("pause");
	return 0;
}
