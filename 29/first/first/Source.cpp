#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    int number = 0;
    char path[100];
    cout << "Enter the path to the file: ";
    cin >> path; 
   
  
        cout <<"Enter the number of parts: ";
        cin >> number;
 
 
    ifstream fin;
    fin.open(path, ios::in | ios::binary);
 
    if(fin.is_open())
    {
        cout << "File is open" << endl;

        string str;
        int countSTR = 0;
        while (getline(fin, str)) countSTR++;
        int size = countSTR /number;
 
    
        fin.clear();
        fin.seekg(0);
        int n = 0;        
        ofstream f;        
        while(getline(fin, str))
        {
            char name[12];
            if (n!= number )//cчетчик n не равен к
            {                
                n++;
                sprintf_s(name, 12, "out%d.txt", n);
                f.close();
                f.open(name,ios::out | ios::binary);              
            }
            f << str << endl;
            
        }
 
    }
 
    return 0;
}
//int main()
//{
//    ifstream fin;
//    vector<string> lines;
//    int parts;
//    bool correct = true;
//
//    do
//    {
//        string path;
//
//        cout << "Enter the path to the file: ";
//        cin >> path;
//
//        fin.open(path);
//
//        if (!fin.is_open())
//        {
//            cout << "Wrong path to the file." << endl;
//            correct = false;
//        }
//        else
//            correct = true;
//    } while (!correct);
//
//    for (string line; getline(fin, line); lines.push_back(line)) {}
//
//    cout << "Enter the number of parts: ";
//    cin >> parts;
//
//    int numStr = lines.size() / parts;
//    int k = 0;
//    for (int i = 0; i < parts; i++)
//    {
//        ofstream fout;
//        char name[12];
//        k++;
//       
//        sprintf_s(name, 12, "out%d.txt", k);
//         
//           fout.open(name, ios::out | ios::binary);
//            
//        
//
//        for (int j = 0; j < numStr; j++)
//        {
//            fout << lines[j + numStr * i] << endl;
//            if (parts - 1 == i)
//            {
//                int left = lines.size() % parts;
//                if (j + 1 == numStr)
//                {
//                    for (int k = 1; k <= left; k++)
//                        fout << lines[j + numStr * i + k] << endl;
//                    fout.close();
//                }
//            }
//
//            //fout.close();
//        }
//        return 0;
//    }
//}
//int main()
//{
//    char path[100];
//    cout << "Enter the path to the file: ";
//    cin >> path;
//    int n = 0; 
//    cout << "Enter the number of parts: ";
//    cin >> n;  
//    ifstream File;
//    File.open(path, ios::in | ios::binary);
//
//    if (File.is_open())
//    {
//        //становимся в конец файла
//        File.seekg(0, ios_base::end);
//        //Получаем текущую позицию
//        cout << "size in bites: " << File.tellg()<<endl;
//        size_t fileSize = File;
//        char* buffer = new char[fileSize];
//        size_t q = fileSize / n;
//        File.seekg(0);
//        cout << "File is open" << endl;//
//        string str;     
//              
//        int k = 0;
//        int kk = 0;
//        ofstream f;
//        for (size_t i = 0; i < n; i++)
//        {
//            while (getline(File, str));
//            //while (k==n);
//            {
//                char name[12];
//                if (k != n - 1 && kk % q == 0)
//                {
//                    
//                    k++;
//                    sprintf_s(name, 12, "out%d.txt", k);                   
//                    f.open(name, ios::out | ios::binary); 
//                    
//                    kk = 0;
//                    
//
//                }
//               
//                f << str << endl;
//                kk++;
//                f.close();
//            }
//        }
//    }    
//}
