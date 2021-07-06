#include <windows.h>
#include <time.h>

#define ID_ADD_BUTTON			3000
// назание класса главного окна
char className[] = "WindowClass1";
// структура, хранящая сообщение 
MSG msg;
// адрес приложения
HINSTANCE hInst;
// адрес кнопки
HWND button;
int counter = 1;
int _x, _y;

// оконная функция
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) 
    {     
        case WM_LBUTTONDOWN:
        {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            char s[20];
            _itoa_s(counter++, s, 10);
            button = CreateWindow("button", s, WS_CHILD | WS_VISIBLE, x, y, 50, 20, wnd,(HMENU)ID_ADD_BUTTON, hInst, 0);
            //присвоение кординат
           _x = x;
           _y = y;

           //запустить таймер
           SetTimer(wnd, 1, 1, 0);
            return 0;
        }   
        case WM_TIMER:
        {
            RECT rect;
            GetWindowRect(wnd, &rect);
            int size = rect.bottom - rect.top - 59;
            //переместить кнопку
            MoveWindow(button, _x, _y, 50, 20, 1);
            if (_y >= size)
                KillTimer(wnd, 1);
            else
                _y++;

            return 0;
        }
        case WM_DESTROY: {
            // в ответ на закрытие главного окна закрыть приложение
            PostQuitMessage(0);
            return 0;
        }
    }

    // вернуть необработанные сообщения Windows
    return DefWindowProc(wnd, msg, wParam, lParam);
}

// функция, которая запускается первой (точка входа в программу)
int APIENTRY WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow)
{
    // структура-класс окна, хранящая свойства окна
    WNDCLASS wc;

    hInst = hInstance;

    // адрес главного окна
    HWND hwnd;

    // заполнение класса окна

    // адресс приложения
    wc.hInstance = hInstance;

    // значок гланого окна
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    // курсор в гланом окне
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    // оконная функция
    wc.lpfnWndProc = WndProc;

    // адрес оконного меню
    wc.lpszMenuName = NULL;

    // кисть окна
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    // название класса окна
    wc.lpszClassName = className;

    // флаги окна
    wc.cbClsExtra = wc.cbWndExtra = wc.style = 0;

    // регистрация оконного класса в Windows
    int k = RegisterClass(&wc);

    // создание главного окна
    hwnd = CreateWindow(className, "Hellooooo!", WS_VISIBLE | WS_OVERLAPPEDWINDOW,
        300, 300, 600, 400, NULL, NULL, hInstance, 0);

    // если главное окно не удалось создать, то выйти с ошибкой
    if (!hwnd) return false;

    // цикл обработки сообщений
    while (GetMessage(&msg, 0, 0, 0)) {

        // трансляция сообщений в текстовые поля
        TranslateMessage(&msg);

        // обработать сообщение
        DispatchMessage(&msg);
    }

    return 1;
}
