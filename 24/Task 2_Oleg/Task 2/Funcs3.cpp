#include<iostream>
#include "Group.h"
#include "Person.h"
#include "Student.h"
#include "Ex.h"
#include "stdio.h"


using namespace std;


Group::Group()
{
	this->count = 0;
	this->maxcount = 10;
	sts = new Student*[maxcount];
}


Group::Group(int maxcount)
{
	this->count = 0;
	this->maxcount = maxcount;
	sts = new Student*[maxcount];
}

void Group::Add(const char* name, const char* fname, const int age, const char* gender, const char* faculty, const char* specialty, const int year, const double av_grade)
{
	if (count >= maxcount) throw Ex(5, "Ecxeed group size!");
	else
	{
		sts[count] = new Student(name, fname, age, gender, faculty, specialty, year, av_grade);
		count++;
	}
}

Group::~Group()
{
	for (size_t i = 0; i < count; i++)
	{
		delete sts[i];
	}
	delete[] sts;
}

void Group::Print()
{
	cout << "Print\n\n";
	for (size_t i = 0; i < count; i++)
	{
		sts[i]->APPrint();
	}
}

void Group::PPrint()
{
	for (size_t i = 0; i < count; i++)
	{
		sts[i]->PPrint();
	}
}

void Group::APrint()
{
	for (size_t i = 0; i < count; i++)
	{
		sts[i]->APrint();
	}
}


void Group::Add(Student* st)
{
	if (count >= maxcount) throw Ex(5, "Ecxeed group size!");
		else
		{
			sts[count] = st;
			count++;
		}
}

void Group::operator+(Student* st)
{
	if (count >= maxcount) throw Ex(5, "Ecxeed group size!");
	else
	{
		sts[count] = st;
		count++;
	}
}

void Group::operator+=(Student* st)
{
	if (count >= maxcount) throw Ex(5, "Ecxeed group size!");
	else
	{
		sts[count] = st;
		count++;
	}
}




Group::Group(const Group& source) :Student(source)
{
	count = source.count;
	maxcount = source.maxcount;

	sts = new Student * [maxcount];

	for (size_t i = 0; i < count; i++)
	{
		sts[i] = new Student(source.sts[i]->getName(), source.sts[i]->getFname(), source.sts[i]->getAge(),
			source.sts[i]->getGender(), source.sts[i]->GetFac(), source.sts[i]->GetSpec(),
			source.sts[i]->GetYear(), source.sts[i]->GetAv_grade());
	}
}


Group& Group::operator=(const Group& source)
{
	if (maxcount != source.maxcount)
	{
		for (size_t i = 0; i < count; i++)
		{
			delete sts[i];
		}
		delete[] sts;

		maxcount = source.maxcount;
		count = source.count;
		sts = new Student* [source.maxcount];
		
	}

	for (size_t i = 0; i < count; i++)
	{
		sts[i] = new Student(source.sts[i]->getName(), source.sts[i]->getFname(), source.sts[i]->getAge(),
			source.sts[i]->getGender(), source.sts[i]->GetFac(), source.sts[i]->GetSpec(),
			source.sts[i]->GetYear(), source.sts[i]->GetAv_grade());
		
	}
	return *this;
}


Group& Group::operator+=(const Group& source)
{
	
	int newmaxcount = source.maxcount+maxcount;
	int newcount = source.count+count;
	Student** newsts = new Student * [newmaxcount];

	for (size_t i = 0; i < count; i++)
	{
		newsts[i] = new Student(sts[i]->getName(), sts[i]->getFname(), sts[i]->getAge(),
			sts[i]->getGender(), sts[i]->GetFac(), sts[i]->GetSpec(),
			sts[i]->GetYear(), sts[i]->GetAv_grade());
	}

	for (size_t i = count; i < newcount; i++)
	{
		newsts[i] = new Student(source.sts[i - count]->getName(), source.sts[i - count]->getFname(), source.sts[i - count]->getAge(),
			source.sts[i - count]->getGender(), source.sts[i - count]->GetFac(), source.sts[i - count]->GetSpec(),
			source.sts[i - count]->GetYear(), source.sts[i - count]->GetAv_grade());
	}

	delete[] sts;
	sts = newsts;
	this->maxcount = newmaxcount;
	this->count = newcount;
	
	return *this;
}

bool Group::operator==(const Group& source)
{
	return (this->count == source.count) ? true : false;
}

bool Group::operator>=(const Group& source)
{
	return (this->count> source.count) ? true : false;
}


void Group::operator() ()
{
	Student** newsts = new Student * [maxcount];
	
	for (size_t i = 0; i < count; i++)
	{
		newsts[i] = new Student(sts[i]->getName(), sts[i]->getFname(), sts[i]->getAge(),
			sts[i]->getGender(), sts[i]->GetFac(), sts[i]->GetSpec(),
			sts[i]->GetYear(), sts[i]->GetAv_grade());
	}
	
	int step, i, j;

	
	Student** temp = new Student * [1];
	temp[0] = new Student();

	for (step = count / 2; step > 0; step /= 2)
	{
		for (i = step; i < count; i++)
		{
			for (j = i - step; j >= 0 && ((newsts[j]->GetAv_grade()) > (newsts[j + step]->GetAv_grade())); j -= step)
			{
				temp[0] = new Student(newsts[j]->getName(), newsts[j]->getFname(), newsts[j]->getAge(),	newsts[j]->getGender(), newsts[j]->GetFac(), newsts[j]->GetSpec(), newsts[j]->GetYear(), newsts[j]->GetAv_grade());
				//temp[0]=newsts[j];
				newsts[j] = new Student(newsts[j+step]->getName(), newsts[j + step]->getFname(), newsts[j + step]->getAge(), newsts[j + step]->getGender(), newsts[j + step]->GetFac(), newsts[j + step]->GetSpec(), newsts[j + step]->GetYear(), newsts[j + step]->GetAv_grade());
				//newsts[j]=newsts[j + step];
				newsts[j+step]=new Student(temp[0]->getName(), temp[0]->getFname(), temp[0]->getAge(), temp[0]->getGender(), temp[0]->GetFac(), temp[0]->GetSpec(), temp[0]->GetYear(), temp[0]->GetAv_grade());
				//newsts[j + step] = temp[0];
				
				
			}
		}
	}
	
	delete temp[0];
	delete[] temp;
	
	for (int l = count-1; l >=0; l--)
	{
		cout << (count-l) << ". " << newsts[l]->getName()<<" "<<newsts[l]->getFname()<<" - " << newsts[l]->GetAv_grade() << " points.\n";
	}
	
	
	for (size_t i = 0; i < count; i++)
	{
		delete newsts[i];
	}
	delete[] newsts;
}


void Group::Save(const char* filename)
{
	FILE* targetFile = fopen(filename, "wb");

	try
	{
		if (targetFile != nullptr)
		{
			fprintf(targetFile, "Students number: %d\\\r\n", count);
			fprintf(targetFile, "Max students number: %d\\\r\n", maxcount);

			for (int i = 0; i < count; i++)
			{
				fprintf(targetFile, "%s\\%s\\%d\\%s\\", sts[i]->getName(), sts[i]->getFname(), sts[i]->getAge(), sts[i]->getGender());
				fprintf(targetFile, "%s\\%s\\%d\\%f\\\r\n", sts[i]->GetFac(), sts[i]->GetSpec(), sts[i]->GetYear(), sts[i]->GetAv_grade());
			}

			fclose(targetFile);
		}
		else throw Ex (2, "Wrong file name!");
	}
	catch (Ex* e)
	{
		e->Print();
	}
}

Group& Group::Load(const char* filename)
{
	FILE* srcFile = fopen(filename, "rb");

	try
	{
		if (srcFile != nullptr)
		{

			fseek(srcFile, 0, SEEK_END);
			int filesize = ftell(srcFile);
			fseek(srcFile, 0, SEEK_SET);
			char* buffer = new char[filesize];

			if (buffer != nullptr)
			{

				fread(buffer, sizeof(char), filesize, srcFile);
				char* temp = strtok(buffer, ":");
				char* digit = strtok(NULL, "\\");
				int c; 
				sscanf(digit, "%d", &c);
				char* temp1 = strtok(NULL, ":");
				char* digitMax = strtok(NULL, "\n");
				int d;
				sscanf(digitMax, "%d", &d);
				Student** newsts = new Student * [d];

				for (size_t i = 0; i < c; i++)
				{

					char* nameC = strtok(NULL, "\\");
					char* fnameC = strtok(NULL, "\\");
					char* ageC = strtok(NULL, "\\");
					int ageD;
					sscanf(ageC, "%d", &ageD);
					char* genderC = strtok(NULL, "\\");
					char* facultyC = strtok(NULL, "\\");
					char* specialtyC = strtok(NULL, "\\");
					char* yearC = strtok(NULL, "\\");
					int yearD;
					sscanf(yearC, "%d", &yearD);
					char* av_gradeC = strtok(NULL, "\n");
					double av_gradeD;
					sscanf(av_gradeC, "%lf", &av_gradeD);
					newsts[i] = new Student(nameC, fnameC, ageD, genderC, facultyC, specialtyC, yearD, av_gradeD);
				}
				delete[] sts;
				sts=newsts;
				maxcount = d;
				count = c;
				

			}
			delete[] buffer;
			fclose(srcFile);
		}
		else throw Ex(2, "Wrong file name!");
	}
	catch (Ex* e)
	{
		e->Print();
	}
	return *this;
}

Student* Group::operator[] (const char* name)
{
	int n = -1;
	for (size_t i = 0; i < count; i++)
	{
		if (strcmp(this->sts[i]->getFname(), name) == 0)
		{
			n = i;
			break;
		}
	}

	if (n < 0) throw Ex(6, "Incorrect family name");
	else
	{
		return sts[n];
	}
}
