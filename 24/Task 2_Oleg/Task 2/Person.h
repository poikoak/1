#pragma once
class Person
{
protected:
	char* name;
	char* fname;
	int age;
	char* gender;
	
public:
	Person();
	Person(const char* name, const char* fname, const int age, const char* gender);

	void PPrint();
	
	~Person();

	Person(const Person& person);
	//Person& operator=(const Person& person);


	void SetAge(int age);
	void SetGender(char* gender);
	void SetName(char* name);
	void SetFname(char* fname);

	char* getName();
	int getAge();
	char* getFname();
	char* getGender();

	//bool findperson(const char* temp);

	

};

