#include <iostream>
using namespace std;

void main()
{

	char Filename1[200];
	cout << "Enter name of first file: ";
	cin.getline(Filename1, 200);

	char Filename2[200];
	cout << "Enter name of second file: ";
	cin.getline(Filename2, 200);


	FILE* File1 = fopen(Filename1, "rb");
	if (File1 != nullptr)
	{
		fseek(File1, 0, SEEK_END);
		size_t fileSize1 = ftell(File1);
		fseek(File1, 0, SEEK_SET);
		
		
			
			FILE* File2 = fopen(Filename2, "rb");
			if (File2 != nullptr)
			{
				fseek(File2, 0, SEEK_END);
				size_t fileSize2 = ftell(File2);
				fseek(File2, 0, SEEK_SET);
				
				
					if (fileSize1 != fileSize2)
					{
						cout << "Fails are different " << endl;
					}
					else
					{
						cout << "Fails are the same " << endl;
					}


				
				fclose(File2);
			}
			
			
		fclose(File1);
		
	}

}


