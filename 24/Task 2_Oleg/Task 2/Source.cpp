#include <iostream>
#include "Student.h"
#include "Group.h"
#include "Ex.h"

using namespace std;

void main()
{
	cout << "\nCreating group 1\n";
	Group Gr1(5);
	
	cout << "\n=============================================\n";
	cout << "\nAdding students to group in four different ways 1\n";
	Gr1.Add("Mary", "Johnson", 24, "female", "Linguistics", "Typology", 2, 67);
	Gr1.Add(new Student("Mary", "Smith", 34, "female", "Linguistics", "Typology", 2, 89));
	Gr1 + new Student("Jacob", "Dean", 26, "male", "Linguistics", "Typology", 2, 86);
	Gr1 += new Student("Richard", "Carpenter", 32, "male", "Linguistics", "Typology", 2, 80);
	
	cout << "\n=============================================\n";
	cout << "\nDisplaying all students\n";
	Gr1.Print();
	cout << "\nDisplaying only personal information\n";
	Gr1.PPrint();
	cout << "\nDisplaying only academic information\n";
	Gr1.APrint();

	cout << "\n=============================================\n";
		cout << "\nDisplaying information for ONE STUDENT\n";
	char name[80];
	cout << "\nEnter students family name\n";
	cin.getline(name, 80);
	Gr1[name]->APPrint();

	cout << "\n=============================================\n";
	cout << "\nSaving information to file\n";
	char targetfile[400];
	cout << "\nEnter the name of the target file:\n";
	cin.getline(targetfile, 400);
	Gr1.Save(targetfile);

	cout << "\n=============================================\n";
	cout << "\nSorting group students by their academic grades\n";
	Gr1();

	cout << "\n=============================================\n";
	cout << "\nCreating new empty group, loading infromation from file and displaying it\n";
	Group Gr2;
	char sourcefile[400];
	cout << "\nEnter the name of the source file:\n";
	cin.getline(sourcefile, 400);
	Gr2.Load(sourcefile);
	Gr2.Print();

	cout << "\n=============================================\n";
	cout << "\nComparing the two groups\n";
	if (Gr1 == Gr2)cout << "\nThe two groups are equal!\n";
	else if (Gr1 >= Gr2) cout << "\nThe first group is bigger than the second!";
	else cout << "\nThe second group is bigger than the first!";


	cout << "\n=============================================\n";
	cout << "\nAdding the students from group 1 to group 2 and displaying the result\n";
	Gr2 += Gr1;
	Gr2.Print();

	cout << "\n=============================================\n";
	cout << "\nCreating new group by copying group 1\n";
	Group Gr3 = Gr1;
	Gr3.Print();

	cout << "\n=============================================\n";
	cout << "\nLoading data from file and copying it to group 3\n";
	Group Gr4;
	cout << "\nEnter the name of the source file:\n";
	cin.getline(sourcefile, 400);
	Gr4.Load(sourcefile);
	Gr4.Print();
	Gr3 = Gr4;
	Gr3.Print();

//And then follows the MENU which I had ambition to start but not enough time to finish))
/*
void Menu()
{
	cout << "\nCreate a group - press 1;\n";
	cout << "Add students to existing group - press 2;\n";
	cout << "Save to file - press 3;\n";
	cout << "Load from a file - press 4;\n";
	cout<<"Sort students - press 5;\n";
	cout << "Display information - press 6;\n";
	cout << "Add new group - press 7;\n";
	cout << "Clear screen - press 8;\n";
	cout << "Exit programme - press 0;\n";
}

void Submenu1()
{
	system("cls");
	cout << "\nDisplay everything - press 1;\n";
	cout << "Display personal information for all students - press 2;\n";
	cout << "Display academic information for all students - press 3;\n";
	cout << "Display information for one student - press 4;\n";
}

void Submenu2()
{
	system("cls");
	cout << "\nCreate new group from scratch - press 1;\n";
	cout << "Create new group merging it with the already existing one - press 2;\n";
	cout << "Load group from file - press 3;\n";
	cout << "Compare two groups (new and old) - press 4;\n";
	cout << "Add students to group - press 5;\n";
	cout<<"Sort students in the group - press 6; \n";
	cout << "Save to file - press 7;\n";
	cout << "Display information - press 8;\n";
	cout << "Exit from submenu - press 0;\n";
}

void AddSts(Group& source)
{
	char n1[80];
	char n2[80];
	int n3;
	char n4[80];
	cin.ignore();
	cout << "\nEnter person's name: ";
	cin.getline(n1, 80);
	cout << "\nEnter person's family name: ";
	cin.getline(n2, 80);
	cout << "\nEnter person's age: ";
	cin>>n3;
	cout << "\nEnter person's gender: ";
	cin.ignore();
	cin.getline(n4, 80);

	char s1[80];
	char s2[80];
	int s3;
	double s4;
	cout << "\nEnter faculty: ";
	cin.getline(s1, 80);
	cout << "\nEnter specialty: ";
	cin.getline(s2, 80);
	cout << "\nEnter year: ";
	cin >> s3;
	cout << "\nEnter average grade: ";
	cin>>s4;

	source.Add(n1, n2, n3, n4, s1, s2, s3, s4);

	return;
}


void main()
{
	int z = 1;
	int q = 0;
	cout << "\n\n\nEnter maximum number of students in the group: ";
	cin >> q;
	Group Gr1(q);
	

	while (z)
	{
		Menu();
		int sel0;
		cin >> sel0;
		try
		{
			if (sel0 > 8 || cin.fail())
			{
				throw Ex(2, "Wrong command!");
			}
		}
		catch (Ex& e)
		{
			e.Print();
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		switch (sel0)
		{
		case 1:
		{

			
			AddSts(Gr1);
			break;
		}

		case 2:
		{
			char n1[80];
			char n2[80];
			int n3;
			char n4[80];
			cin.ignore();
			cout << "\nEnter person's name: ";
			cin.getline(n1, 80);
			cout << "\nEnter person's family name: ";
			cin.getline(n2, 80);
			cout << "\nEnter person's age: ";
			cin >> n3;
			cout << "\nEnter person's gender: ";
			cin.ignore();
			cin.getline(n4, 80);

			char s1[80];
			char s2[80];
			int s3;
			double s4;
			cout << "\nEnter faculty: ";
			cin.getline(s1, 80);
			cout << "\nEnter specialty: ";
			cin.getline(s2, 80);
			cout << "\nEnter year: ";
			cin >> s3;
			cout << "\nEnter average grade: ";
			cin >> s4;

			Gr1.Add(new Student(n1, n2, n3, n4, s1, s2, s3, s4));

			break;
		}

		case 3:
		{
			char targetfile[400];
			cout << "\nEnter the name of the target file:\n";
			cin.ignore();
			cin.getline(targetfile, 400);
			Gr1.Save(targetfile);
			break;
		
		}

		case 4:
		{
			char sourcefile[400];
			cout << "\nEnter the name of the source file:\n";
			cin.ignore();
			cin.getline(sourcefile, 400);
			Gr1.Load(sourcefile);
			break;
		}

		case 5:
		{
			Gr1();
			break;
		}

		case 6:
		{
			

				Submenu1();
				int sel1 = 0;
				cin >> sel1;

				switch (sel1)
				{
				case 1:
				{
					Gr1.Print();
					break;
				}

				case 2:
				{
					Gr1.PPrint();
					break;
				}

				case 3:
				{
					Gr1.APrint();
					break;
				}

				case 4:
				{

				}
				}
			break;
		}

		case 7:
		{
			int x = 1;
			while (x)
			{
				int sel2 = 0;
				cin >> sel2;

				switch (sel2)

				{

				case 1:
				{}

				case 2:
				{}

				case 3:
				{}

				case 4:
				{}

				case 5:
				{}

				case 6:
				{}

				case 7:
				{}

				case 8:
				{}

				case 0:
				{
					x = 0;
					break;
				}
				}
			}
			break;
		}

		case 8:
		{
			system("cls");
			break;
		}

		case 0:
		{
			z = 0;
			break;
		}
		}
	}

*/	
	cout << "\nEoP\n";
return;
}










