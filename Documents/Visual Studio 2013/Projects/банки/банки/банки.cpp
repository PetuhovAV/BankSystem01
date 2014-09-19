// банки.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "web.h";
#include <iostream>

#pragma warning(disable : 4996)

using namespace std;

char BankId;

int _tmain(int argc, _TCHAR* argv[])
{
	char buffer[1024];
	web w(PORT, ADRESS);
	cout << "Id banka:" << endl;
	cin >> BankId;
	memccpy(buffer, &BankId,1,sizeof(char));
	sprintf(buffer + sizeof(char), ":b;\n", BankId);

	w.connect();

	do
	{
		w.sendMessage(buffer);
		cin.getline(buffer, 1024, '\n');
		printf("message:[%s]\n", w.getMessage());
	} while (true);
	return 0;
	return 0;
}

