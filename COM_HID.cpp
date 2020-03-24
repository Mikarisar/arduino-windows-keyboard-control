/* This code was taken from here (https://blablacode.ru/programmirovanie/392) and then modified by me.
   Change buttons' codes and recieved from arduino buttons' names to what you need.
   Button codes you can find here: https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
   !!!Change COM port number in line 99 to your Arduino's COM!!!
*/
#include <windows.h>
#include <iostream>
#include <tchar.h>
using namespace std;

HANDLE hSerial;

void ReadCOM()
{
    DWORD iSize;
    char sReceivedChar;
    while (true)
    {
        ReadFile(hSerial, &sReceivedChar, 1, &iSize, 0);  // получаем 1 байт | recieving 1 byte
        if (iSize > 0)   // если что-то принято | if something recieved
        {
            cout << sReceivedChar; // выводим

            if (sReceivedChar == 'U')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_UP, 0L);
            }
            else if (sReceivedChar == 'D')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_DOWN, 0L);
            }
            else if (sReceivedChar == 'L')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_LEFT, 0L);
            }
            else if (sReceivedChar == 'R')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_RIGHT, 0L);
            }
            else if (sReceivedChar == 'O')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_SPACE, 0L);
            }
            //else if (sReceivedChar == 'A')
            //{
            //    SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_ESCAPE, 0L); // отключено за бесполезностью | disabled
            //}
            //else if (sReceivedChar == 'H')
            //{
            //    SendMessage(HWND_BROADCAST, WM_KEYDOWN, 0x48, 0L); // F - не работает - не тот код кнопки | wrong key code
            //}
            else if (sReceivedChar == '1')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD1, 0L);
            }
            else if (sReceivedChar == '2')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD2, 0L);
            }
            else if (sReceivedChar == '3')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD3, 0L);
            }
            else if (sReceivedChar == '4')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD4, 0L);
            }
            else if (sReceivedChar == '5')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD5, 0L);
            }
            else if (sReceivedChar == '6')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD6, 0L);
            }
            else if (sReceivedChar == '7')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD7, 0L);
            }
            else if (sReceivedChar == '8')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD8, 0L);
            }
            else if (sReceivedChar == '9')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD9, 0L);
            }
            else if (sReceivedChar == '0')
            {
                SendMessage(HWND_BROADCAST, WM_KEYDOWN, VK_NUMPAD0, 0L);
            }

        }
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	LPCTSTR sPortName = L"COM3"; //this is your Arduino's COM port. Change if it's not the same. 

	hSerial = ::CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    if (hSerial == INVALID_HANDLE_VALUE)
    {
        if (GetLastError() == ERROR_FILE_NOT_FOUND)
        {
            cout << "serial port does not exist.\n";
        }
        cout << "some other error occurred.\n";
    }

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams))
    {
        cout << "getting state error\n";
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams))
    {
        cout << "error setting serial port state\n";
    }

    char data[] = "Mikarisar is a God";  // тестовая строка для передачи | test string for transfer
    DWORD dwSize = sizeof(data);   // размер этой строки | size of this string
    DWORD dwBytesWritten;    // тут будет количество собственно переданных байт | number of transfered bytes

    BOOL iRet = WriteFile(hSerial, data, dwSize, &dwBytesWritten, NULL);

    cout << dwSize << " Bytes in string. " << dwBytesWritten << " Bytes sended. " << endl;

    while (1)
    {
        ReadCOM();
    }
    return 0;
}