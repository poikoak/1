#include<iostream>
#include<string.h>
#include<iomanip>//для функций setw

#include<conio.h>//дял гетч
//#include<ctype.h>
//#include<stdio.h>

using namespace std;
struct phone
{
	int num;
	int n;
	int d;
	int m;
	int y;
	char name[25];
	char dcr[25];
	char address[25];

};
void menu();
void add();
void menuDisplay();
void viewAllRecords();
void Save_Load();
void deleteDATA();
void mutchNumber();
void view();
void deleteMechanism();
void mutchName();
FILE* file;
FILE* tempfile;

char IDname[25];//для поиска имени не сработало
int id;
bool found;


void menu()
{
	system("cls");
	menuDisplay();
	while (true)
	{
		char* str = new char[10];		
		cin.getline(str, 10);
		if (strcmp(str, "1") == 0)
			add();	

		else if (strcmp(str, "2") == 0)
			viewAllRecords();

		else if (strcmp(str, "3") == 0)
		
			deleteDATA();
		
		else if (strcmp(str, "4") == 0)
		{
			 Save_Load();
		}
		else if (strcmp(str, "5") == 0)
		{
			mutchNumber();
		}
		else if (strcmp(str, "6") == 0)
		{
			mutchName();
		}
		else if (strcmp(str, "7") == 0)
		{
			cout << "Goodbye ";
			exit(0);
		}
		
	}
	
	
}
void menuDisplay()
{
	cout << "............................................\n";
	cout << "                PHONE BOOK\n";
	cout << "............................................\n\n";
	cout << "::::::::::::::: PROGRAM MENU :::::::::::::::\n";
	cout << "1. ADD Contact\n";
	cout << "2. VIEW Contacts\n";
	cout << "3. Delete Specific Record\n";
	cout << "4. Save/Load PhoonBook in \n";
	cout << "5. Find by Phone number\n";	
	cout << "6. Find by Name\n";
	cout << "7. Exit\n";
	cout << "Enter Your Choice: ";
}

void Save_Load()
{
	char sourceFilename[200];
	cout << "Enter name of source file: ";
	cin.getline(sourceFilename, 200);
	char destFilename[200];
	cout << "Enter name of destination file: ";
	cin.getline(destFilename, 200);
	FILE* srcFile = fopen(sourceFilename, "rb");
	if (srcFile != nullptr)
	{
		fseek(srcFile, 0, SEEK_END);
		size_t fileSize = ftell(srcFile);
		fseek(srcFile, 0, SEEK_SET);
		char* buffer = new char[fileSize];
		if (buffer != nullptr)
		{		
			fread(buffer, sizeof(char), fileSize, srcFile);
			FILE* dstFile = fopen(destFilename, "wb");
			if (dstFile != nullptr)
			{
				fwrite(buffer, sizeof(char), fileSize, dstFile);
				fclose(dstFile);
				_getch();//выводит символ из консоли, но не пишет его
				menu();
			}
			delete[] buffer;
		}
		fclose(srcFile);
		
	}
}



void add()
{
	int num, n,d,m,y, IDcontact;
	char name[25], address[25], dcr[25];
	found = false;

	cout << "Contact ID number 	repeat check :";
	scanf("%d", &IDcontact);

	file = fopen("phone.txt", "a+");
	
	while (!feof(file) && found == false)
	{
		fscanf(file, "\n%d%d%s%s%s%d%d%d", &num, &n, &name, &address, &dcr, &d, &m, &y);//считывает поток
	
		if (num == IDcontact)
		{
			printf("Number is Existing!..");
			found = true;
		}
	}
	if (found == false)
	{
		cout << "ADD new contact----->";
		cout << "Contact ID number:";
		scanf("%d", &num);
		cout << "\n\nContact Phone number:";
		scanf("%d", &n);//вводит и конверт в нужный формат <стдио>
		cout << ("\nName:");
		scanf("%s", &name);
		cout << ("\nAddress:");
		scanf("%s", &address);
		cout << ("\nDiscription:");
		scanf("%s", &dcr);
		cout << "\nBirth data";
		cout << "\nDay:";
		scanf("%d", &d);
		cout << "\nMonth:";
		scanf("%d", &m);
		cout << "\nYear:";
		scanf("%d", &y);

		fprintf(file, "\n%5d %5d %20s %20s %20s %5d %5d %5d", num, n, name, address, dcr, d, m, y);
		printf("\nThe new record was successfully saved! Press any button");
	}
	_getch();
	fclose(file);
	menu();
}

void display()
{
	cout << "\n" << setw(15) << left << "Contact no."//устанавливает ширину поля равной()
		<< setw(25) << left << "Phone number"
        << setw(15) << left << "Name"
		<< setw(15) << left << "Address"
		<< setw(15) << left << "Discription"
		<<"B.Day" <<endl;
	
}
void viewAllRecords()
{

	int num, n, d, m, y;
	char name[25], address[25], dcr[25];
	file = fopen("phone.txt", "r");
	
	if (file!=nullptr)
	{
		system("cls");
		cout << " \nLIST OF CONTACTS";
		display();
		while (!feof(file))//проверка на достигло конец фала или не
		{
			if (fscanf(file, "\n%d%d%s%s%s%d%d%d", &num, &n, &name, &address, &dcr, &d, &m, &y) > 0)
				cout << setw(15) << num << setw(25) << n << setw(15) << name << setw(15) << address <<
				setw(15) << dcr << d << "." << m << "." << y << "\n";
			
		}
		_getch();
		menu();
	}
	
	fclose(file);
	
}

void mutchNumber()
{
	system("cls");
	int num, n, d, m, y;
	char name[25], address[25], dcr[25];
	found = false;
	cout << "Enter CONTACT to be viewed:";
	cin >> id;
	file = fopen("phone.txt", "r");
	while (!feof(file) && found == false)
	{
		if (fscanf(file, "\n%d%d%s%s%s%d%d%d", &num, &n, &name, &address, &dcr, &d, &m, &y) > 0)

		{
			if (n == id)
			{
				display();
				cout << setw(15) << num << setw(25) << n << setw(15) << name << setw(15) << address <<
					setw(15) << dcr << d << "." << m << "." << y << "\n";
				found = true;
				_getch();
				menu();
			}
		}
	}
	if (found == false)
	{
		cout << "\n Record is not existing!";
		_getch();
		menu();
	}
	fclose(file);
}
void mutchName()
{
	system("cls");
	int num, n, d, m, y;
	char name[25], address[25], dcr[25], IDname[25];
	found = false;
	cout << "\n\nEnter CONTACT to be viewed:";
	scanf("%s", &IDname);
	file = fopen("phone.txt", "r");
	while (!feof(file) && found == false)
	{
		if (fscanf(file, "\n%d%d%s%s%s%d%d%d", &num, &n, &name, &address, &dcr, &d, &m, &y) > 0)

		{
			if (name == IDname)
			{
				display();
				cout << setw(15) << num << setw(25) << n << setw(15) << name << setw(15) << address <<
					setw(15) << dcr << d << "." << m << "." << y << "\n";
				found = true;
				_getch();
				menu();
			}
		}
	}
	if (found == false)
	{
		cout << "\n Record is not existing!";
		_getch();
		menu();
	}
	fclose(file);
}

void deleteDATA()
{
	char Yes;
	view();
	if (found == true)
	{
		cout << "Are you sure you want to delete this record(y/n)?:";
		cin >> Yes;
		if (Yes == 'y' || Yes == 'Y')
		{
			deleteMechanism();
			cout << "\n\nThe record was successfully deleted!";
			_getch();
			menu();
		}
		else
		{
			cout << "\nThe record was not deleted!";
			_getch();
			menu();
		}
		
	}
}

void view()
{
	int num, n, d, m, y;
	char name[25], address[25], dcr[25];
	found = false;
	cout << "\n\nEnter CONTACT to be viewed:";
	cin >> id;
	file = fopen("phone.txt", "r");
	
	while (!feof(file) && found == false)
	{
		if (fscanf(file, "\n%d%d%s%s%s%d%d%d", &num, &n, &name, &address, &dcr, &d, &m, &y) > 0)
			
		{
			if (num == id)
			{
				display();
				cout << setw(15) << num << setw(25) << n << setw(15) << name << setw(15) << address <<
					setw(15) << dcr << d << "." << m << "." << y << "\n";
				found = true;
				
			}
		}
	}
	if (found == false)
	{
		cout << "\n Record is not existing!";
		
	}
	fclose(file);
}


void deleteMechanism()
{
	int num, n, d, m, y;
	char name[25], address[25], dcr[25];
	file = fopen("phone.txt", "r");
	tempfile = fopen("tempProfile.txt", "w+");
	
	while (!feof(file))
	{
		if (fscanf(file, "\n%d%d%s%s%s%d%d%d", &num, &n, &name, &address, &dcr, &d, &m, &y) > 0)

		{
			if (num != id)
			{
				fprintf(tempfile, "\n%5d %5d %20s %20s %20s %5d %5d %5d", num, n, name, address, dcr, d, m, y);
			}
		}
	}
	fclose(file);
	fclose(tempfile);

	file = fopen("phone.txt", "w+");
	tempfile = fopen("tempProfile.txt", "r");
	
	while (!feof(tempfile))
	{
		if (fscanf(tempfile, "\n%d%d%s%s%s%d%d%d", &num, &n, &name, &address, &dcr, &d, &m, &y) > 0)
		{
			if (num != id)
			{
				fprintf(file, "\n%5d %5d %20s %20s %20s %5d %5d %5d", num, n, name, address, dcr, d, m, y);
			}
		}
	}
	fclose(file);
	fclose(tempfile);
}

















int main()
{
	menu();
}