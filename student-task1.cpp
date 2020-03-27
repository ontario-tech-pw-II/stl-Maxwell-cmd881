// Student class is implemented based on string and do not need any change

#include <iostream>
#include <string>
#include <list>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(string);
		string getname();


		Person(); 				// default constructor
		Person(string);
		Person(const Person &); 		// copy constructor

		

		virtual ~Person();

};

void Person::setname(string n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(string n)
{
	setname(n);
}



Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(string, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);
	bool operator<(Student a){
		if(grade<a.grade){
			return true;
		}
		return false;
	}

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(string n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

int main()
{  

	// Write your code for Task 1
	string strTemp = "";
	double dblTemp = 0.0;
	list<Student> lStud;

	for(int i =0;i <=5;i++){
		cout << "enter name then grade: ";
		cin >> strTemp;
		cin >> dblTemp;
		lStud.push_back(Student(strTemp,dblTemp));
	}

	lStud.sort();

	list<Student>::const_iterator i;
	for(i = lStud.cbegin();i!= lStud.cend();i++){
		cout << *i << endl;
	}
		
}



