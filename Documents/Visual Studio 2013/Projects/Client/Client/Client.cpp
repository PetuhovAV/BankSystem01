// Client.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "../../�����/�����/web.h"

int main()
{
	char buffer[1024];
	web w(PORT, ADRESS);
	w.connect();

	do
	{
		cin.getline(buffer, 1024,'\n');
		w.sendMessage(buffer);
		printf("message:[%s]\n", w.getMessage());
	} while (true);
	return 0;
}

