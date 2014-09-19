// Throuter.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../банки/банки/web.h"

#pragma warning(disable : 4996)

int BankId;
void client(web &w);

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Id troutera:" << endl;
	cin >> BankId;

	web serv(PORT);
	serv.Listen(client);

	return 0;
}

void client(web &w)
{
	char buffer[1024] = "Hello;\r\n\0";
	cout << "+1" << endl;
	strcpy(buffer, w.getMessage());
	cout << buffer << endl;
	strcpy(buffer, "Ok\0");
	w.sendMessage(buffer);
	do
	{
		strcpy(buffer, w.getMessage());
		cout << buffer;
	} while (w.sendMessage(buffer));
	cout << "-1" << endl;
}