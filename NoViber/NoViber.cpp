#include <windows.h>
#include <shellapi.h>

#define path L"C:\\Users\\Fakku\\AppData\\Local\\Viber\\Viber.exe" // full path to Viber.exe
#define title L"Viber +1234567890" // title of the viber window, usually it's "Viber +1234567890" where +1234567890 is the user's phone number

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	HKEY hKey;
	TCHAR pPath[MAX_PATH];
	RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hKey);
	GetModuleFileName(0, pPath, MAX_PATH);
	RegSetValueEx(hKey, L"NoViber", 0, REG_SZ, (LPBYTE)pPath, sizeof(pPath));
	RegCloseKey(hKey);

	ShellExecute(NULL, L"open", path, NULL, NULL, SW_SHOWMINIMIZED);
	HWND viber = NULL;
	while (viber == NULL)
	{
		viber = FindWindow(NULL, title);
		Sleep(1);
	}
	SendMessage(viber, WM_CLOSE, NULL, NULL);
	return 0;
}
