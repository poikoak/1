/**
 ������������ ����� �������� �����, ��������� ������������ ����� ������
���� ������ � ���� ����� � � ���������, � ����� ������������ ���������� ��������
 * */
#include <iostream>
#include <io.h>

using namespace std;

void scan_dir(const char* dir_path, const char* mask, int& fileSize, int& folders)
{
	char* new_path = new char[4000];
	char* mask_path = new char[4000];
	strcpy(mask_path, dir_path);
	strcat(mask_path, "\\");
	strcat(mask_path, mask);
	// ����������, �������� ���������� �� ����� �����
	_finddata_t c_file;
	// ����� ������ ��������� ������
	long hFile;	
	// ����� ����� �� ����� � ������� ����� ������ ��������� ������ � ���������� � ������ �����
	hFile = _findfirst(mask_path, &c_file);	
	if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0){		
		// ���� ���� �������� ������
		if (c_file.attrib & _A_SUBDIR){			
			cout << c_file.name << "   " << "<DIR>" << endl;			
			// ������������ ���� � ��������
			strcpy(new_path, dir_path);
			strcat(new_path, "\\");
			// �������� � ������� ���� ��� ������� �����
			strcat(new_path, c_file.name);
			//cout << "Go to -> " << new_path << endl;
			// ����������� ����� �������
			scan_dir(new_path, mask, fileSize, folders);			
		}
	}	
	// ���� ��� ��������� ���������� �� ��������� ��������� ������
	while (_findnext(hFile, &c_file) == 0)	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)		{
			if (c_file.attrib & _A_SUBDIR)			{
				folders++;				
				// ������������ ���� � ��������
				cout << c_file.name << "   " << "<DIR>" << endl;				
				strcpy(new_path, dir_path);
				strcat(new_path, "\\");
				// �������� � ������� ���� ��� ������� �����
				strcat(new_path, c_file.name);		
				// ����������� ����� �������
				scan_dir(new_path, mask, fileSize, folders);				
			}	
			fileSize = fileSize + c_file.size;
		}	
	}
	
	// ���������� ������ �� ������ ��������� ������
	_findclose(hFile);
	delete[] new_path;
	delete[] mask_path;
}
void main(){
	int fileSize=0;
	int folders=0;
	scan_dir("g:\\1", "*.*",fileSize, folders);
	cout<<"total size = " << fileSize << endl;
	cout << "count folders = " << folders << endl;
}



