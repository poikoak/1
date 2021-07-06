#pragma once
class Person
{
	char name[20];
	char lastname[20];
	char city[20];
	char work[20];
public:
	
	void SetName(const char name[20]);
	char* GetName();
	void SetLastName(const char lastname[20]);
	char* GetLastName();
	void SetCity( const char city[20]);
	char* GetCity();
	void SetWork(const char work[20]);
	char* GetWork();

	void Print();









};

