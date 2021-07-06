#include <windows.h>
#include <time.h>
#include <strstream>
#include <iostream>
#include <fstream>
using namespace std;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
int SetDefaultFont(int identifier, HWND hwnd)
{
	SendDlgItemMessage(hwnd, identifier, WM_SETFONT, (WPARAM)GetStockObject(SYSTEM_FONT), MAKELPARAM(true, 0));
	return 0;
}

HINSTANCE hInst;
MSG msg;
HWND btn[10];   
HWND btn_dot,btn_plus,btn_minus,btn_times,btn_over,btn_equals;				
HWND btn_ce;					
HWND _hwnd;		 


const char ClassName[] = "Win32 Calculator";
const int	id_0 = 0,
id_1 = 1,
id_2 = 2,
id_3 = 3,
id_4 = 4,
id_5 = 5,
id_6 = 6,
id_7 = 7,
id_8 = 8,
id_9 = 9;							
										
const int id_dot = 10,
id_plus = 11,							
id_minus = 12,							
id_times = 13,							
id_over = 14,							
id_equals = 15;
								
const int id_ce = 16;		
const int lbl_id = 17;									
								  
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR,int nCmdShow)
{
	HWND hwnd; 
	WNDCLASSEX wc; //класс окна	
	hInst = hInstance;
	//конфиг окна
	wc.hInstance = hInst;//Дескриптор экземпляра, который содержит оконную процедуру для класса.
	wc.lpszClassName = ClassName;
	wc.lpfnWndProc = WindowProcedure; 
	wc.style = CS_VREDRAW | CS_HREDRAW; // перерисовывает окно при перемещений
	wc.cbSize = sizeof(WNDCLASSEX);
	
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//Дескриптор курсора класса. Этот член структуры должен быть дескриптором ресурса курсора. Если этот член структуры - ПУСТО (NULL), приложение должно явно устанавливать форму курсора всякий раз, когда мышь перемещается в окно прикладной программы.
	wc.lpszMenuName = NULL; //No menu
	wc.cbClsExtra = 0; //Устанавливает число дополнительных байт, которые размещаются вслед за структурой класса окна. Система инициализирует эти байты нулями.
	wc.cbWndExtra = 0; //Устанавливает число дополнительных байтов, которые размещаются вслед за экземпляром окна. Система инициализирует байты нулями. Если приложение использует WNDCLASSEX, чтобы зарегистрировать диалоговое окно, созданное при помощи использования директивы CLASS в файле ресурса, оно должно установить этот член структуры в DLGWINDOWEXTRA.	
	wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;//дефолтный цвет окна
	
	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Could not register the window class", "ERROR", MB_OK | MB_ICONERROR);
		return 0;
	}
	
	hwnd = CreateWindowEx(
		0, 
		ClassName,
		"Win32 Calculator",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,CW_USEDEFAULT,CW_USEDEFAULT,
		300,//ширина
		370,//высота
		HWND_DESKTOP,0,hInst,0);	
	ShowWindow(hwnd, nCmdShow);
	if (!hwnd) return false;
	while (GetMessage(&msg, 0, 0, 0)) 
	{
		// трансляция сообщений в текстовые поля
		TranslateMessage(&msg);
		// обработать сообщение
		DispatchMessage(&msg);
	}
	return 1;
}




LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	strstream charbuffer;	
	char Text[300];
	static bool dot;//если есть точка, еще одну не сделать
	static double  operand1;
	static double  operand2;
	double result; 
	static char Operator;//оператор для свича

	switch (msg)
	{
	case WM_CREATE:
		
		_hwnd = CreateWindowEx(WS_EX_CLIENTEDGE | WS_EX_RIGHT, "Static", "0", WS_VISIBLE | WS_CHILD, 10, 20, 120, 57, hwnd, (HMENU)lbl_id, hInst, NULL);
		btn_minus = CreateWindow("Button", "-", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 220, 20, 60, 57, hwnd, (HMENU)id_minus, hInst, NULL);
		btn_ce = CreateWindow("Button", "CE", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 150, 20, 60, 57, hwnd, (HMENU)id_ce, hInst, NULL);

		btn[0] = CreateWindow("Button", "0", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, 270, 130, 57, hwnd, (HMENU)id_0, hInst, NULL);
		btn_dot = CreateWindow("Button", ".", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 150, 270, 60, 57, hwnd, (HMENU)id_dot, hInst, NULL);
		btn_equals = CreateWindow("Button", "=", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 220, 270, 60, 57, hwnd, (HMENU)id_equals, hInst, NULL);

		btn[1] = CreateWindow("Button", "1", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, 210, 60, 57, hwnd, (HMENU)id_1, hInst, NULL);
		btn[2] = CreateWindow("Button", "2", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 80, 210, 60, 57, hwnd, (HMENU)id_2, hInst, NULL);
		btn[3] = CreateWindow("Button", "3", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 150, 210, 60, 57, hwnd, (HMENU)id_3, hInst, NULL);
		btn_over = CreateWindow("Button", "/", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 220, 210, 60, 57, hwnd, (HMENU)id_over, hInst, NULL);



		btn[4] = CreateWindow("Button", "4", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, 151, 60, 57, hwnd, (HMENU)id_4, hInst, NULL);
		btn[5] = CreateWindow("Button", "5", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 80, 151, 60, 57, hwnd, (HMENU)id_5, hInst, NULL);
		btn[6] = CreateWindow("Button", "6", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 150, 151, 60, 57, hwnd, (HMENU)id_6, hInst, NULL);
		btn_times = CreateWindow("Button", "x", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 220, 151, 60, 57, hwnd, (HMENU)id_times, hInst, NULL);



		btn[7] = CreateWindow("Button", "7", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, 90, 60, 57, hwnd, (HMENU)id_7, hInst, NULL);
		btn[8] = CreateWindow("Button", "8", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 80, 90, 60, 57, hwnd, (HMENU)id_8, hInst, NULL);
		btn[9] = CreateWindow("Button", "9", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 150, 90, 60, 57, hwnd, (HMENU)id_9, hInst, NULL);
		btn_plus = CreateWindow("Button", "+", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 220, 90, 60, 57, hwnd, (HMENU)id_plus, hInst, NULL);
		

		for (int i = 0; i <= 17; i++) SetDefaultFont(i, hwnd);
		break;


	case WM_COMMAND:

		if (HIWORD(wParam) == BN_CLICKED) 
		{
			switch (LOWORD(wParam))
			{
			case id_ce:
				operand1 = operand2 = result = 0.0;
				Operator = ' ';
				dot = false;
				SetWindowText(_hwnd, "0");
				break;
			case id_plus:
				GetWindowText(_hwnd, Text, 300);
				charbuffer << Text;
				charbuffer >> operand1;
				Operator = '+';
				dot = false;
				SetWindowText(_hwnd, "0");
				break;
			case id_minus:
				GetWindowText(_hwnd, Text, 300);
				charbuffer << Text;
				charbuffer >> operand1;
				Operator = '-';
				dot = false;
				SetWindowText(_hwnd, "0");
				break;

			case id_times:
				GetWindowText(_hwnd, Text, 300);
				charbuffer << Text;
				charbuffer >> operand1;
				Operator = '*';
				dot = false;
				SetWindowText(_hwnd, "0");
				break;

			case id_over:
				GetWindowText(_hwnd, Text, 300);
				charbuffer << Text;
				charbuffer >> operand1;
				Operator = '/';
				dot = false;
				SetWindowText(_hwnd, "0");
				break;

			case id_0: 
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) return 0;
				else strcat(Text, "0");
				SetWindowText(_hwnd, Text);
				break;

			case id_1: 
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) strcpy(Text, "1");
				else strcat(Text, "1");
				SetWindowText(_hwnd, Text);
				break;

			case id_2: 
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) strcpy(Text, "2");
				else strcat(Text, "2");
				SetWindowText(_hwnd, Text);
				break;

			case id_3:
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) strcpy(Text, "3");
				else strcat(Text, "3");
				SetWindowText(_hwnd, Text);
				break;

			case id_4: 
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) strcpy(Text, "4");
				else strcat(Text, "4");
				SetWindowText(_hwnd,Text);
				break;

			case id_5: 
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) strcpy(Text, "5");
				else strcat(Text, "5");
				SetWindowText(_hwnd, Text);
				break;

			case id_6: 
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) strcpy(Text, "6");
				else strcat(Text, "6");
				SetWindowText(_hwnd, Text);
				break;

			case id_7: 
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) strcpy(Text, "7");
				else strcat(Text, "7");
				SetWindowText(_hwnd, Text);
				break;

			case id_8: 
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) strcpy(Text, "8");
				else strcat(Text, "8");
				SetWindowText(_hwnd, Text);
				break;

			case id_9:
				GetWindowText(_hwnd, Text, 300);
				if ((Text[0] == '0') && (!dot)) strcpy(Text, "9");
				else strcat(Text, "9");
				SetWindowText(_hwnd,Text);
				break;

			case id_equals:
				GetWindowText(_hwnd, Text, 300);
				charbuffer << Text;
				charbuffer >> operand2;
				charbuffer.clear();
				switch (Operator)
				{
				case '+':
					result = operand1 + operand2;
					break;
				case '-':
					result = operand1 - operand2;
					break;
				case '*':
					result = operand1 * operand2;
					break;
				case '/':
					if (operand2 != 0) result = operand1 / operand2;
					else
					{
						operand1 = operand2 = result = 0.0;
						Operator = ' ';
						dot = false;
						SetWindowText(_hwnd, "Cannot divide by zero");
						return 0;
					}
				
				}
				charbuffer << result;
				charbuffer.getline(Text, 300);
				SetWindowText(_hwnd, Text);

				operand1 = operand2 = result = 0.0;
				Operator = ' ';
				dot = false;
				break;

			case id_dot:
				if (!dot)
				{
					GetWindowText(_hwnd, Text, 300);
					strcat(Text, ".");
					SetWindowText(_hwnd, Text);
					dot = true;
				}
				break;

			}
		}

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
		break;
	}
	return 0;
}

