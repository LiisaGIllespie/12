#include <iostream>
#include <windows.h>
using namespace std;

void randomarray(int* a, int size) // ��������� ������
{
	srand(time(NULL));
	for (int i = 0; i < size; a++, i++)
		*a = rand() % 100 + 1;
}

void arrayout(int* a, int size) // ����� ������� �� �����
{
	for (int i = 0; i < size; a++, i++)
		cout << *a << " ";
	cout << "\n";
}

void sort(int* a, int size) // ���������� ��������� ������� �� �����������
{
	int x, i, j;
	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (*(a + j - 1) > *(a + j))
			{
				x = *(a + j - 1);
				*(a + j - 1) = *(a + j);
				*(a + j) = x;
			}
		}
	}
}

void array3out(int* a, int size) // ����� �������� ������� �� �����
{
	for (int i = 0; i < size; a++, i++)
		if (*a > 0) cout << *a << " ";
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");

	const int size1 = 15,
		size2 = 15,
		size3 = size1 + size2;

	int button,
		array1[size1], // ������ ������
		array2[size2], // ������
		array3[size3], // ������
		*parray1,
		*parray2,
		*parray3,
		tmp = 0;
	parray1 = &array1[0],
		parray2 = &array2[0],
		parray3 = &array3[0];

	cout << "���� ��� ��������� �������:\n";
	randomarray(array1, size1);
	arrayout(array1, size1); // ����� ������� ���������� ������� 

	Sleep(1000); // ����� ��� �������� ������� ���������� ������� (��� ��� ������ ������ ����� ����������� �������)

	randomarray(array2, size2);
	arrayout(array2, size2); // ����� ������� ���������� ������� 

	cout << "\n�� ��� ����� �������� ������ ������, �� �����?\n"
		<< "1. �� ���� ��������� ����� �������� � ������������� �� �����������;\n"
		<< "2. �� ����� ���������;\n"
		<< "3. �� ��������� ������� �������, ������� ��� �� ������;\n"
		<< "4. �� ��������� ������� �������, ������� ��� � ������;\n"
		<< "5. �� ���� ���������, ��� �� �������� ������ (�� ��, ��� � ���������� ��� ������ ������);\n\n";
	cin >> button;
	switch (button) 
	{
	case 1:
		sort(array1, size1); // ���������� ������� �������
		sort(array2, size2); // ���������� �������
		for (parray3 = array3, parray1 = array1; parray3 < array3 + size1 + size2; parray3++, parray1++)
			*parray3 = *parray1;
		for (parray3 = array3 + size1, parray2 = array2; parray3 < array3 + size1 + size2; parray3++, parray2++)
			*parray3 = *parray2;
		sort(array3, size3);
		cout << "\n������!\n\n";
		array3out(array3, size3);
		break;
	case 2:
		parray3 = array3;
		for (parray1 = array1; parray1 < array1 + size1; parray1++) 
		{
			for (parray2 = array2; parray2 < array2 + size2; parray2++) 
			{
				if (*parray1 == *parray2) 
				{
					*parray3 = *parray1;
					parray3++;
				}
			}
		}
		cout << "\n������!\n\n";
		array3out(array3, size3);
		break;
	case 3:
		parray3 = array3;
		tmp = 0;
		for (parray1 = array1; parray1 < array1 + size1; parray1++) 
		{
			for (parray2 = array2; parray2 < array2 + size2; parray2++) 
			{
				if (*parray1 == *parray2)
					tmp++;
			}
			if (tmp == 0) {
				*parray3 = *parray1;
				parray3++;
			}
			tmp = 0;
		}
		cout << "\n������!\n\n";
		array3out(array3, size3);
		break;
	case 4:
		parray3 = array3;
		tmp = 0;
		for (parray2 = array2; parray2 < array2 + size2; parray2++) 
		{
			for (parray1 = array1; parray1 < array1 + size1; parray1++) 
			{
				if (*parray2 == *parray1)
					tmp++;
			}
			if (tmp == 0) {
				*parray3 = *parray2;
				parray3++;
			}
			tmp = 0;
		}
		cout << "\n������!\n\n";
		array3out(array3, size3);
		break;
	case 5:
		parray3 = array3;
		tmp = 0;
		for (parray1 = array1; parray1 < array1 + size1; parray1++) 
		{
			for (parray2 = array2; parray2 < array2 + size2; parray2++) 
			{
			if (*parray1 == *parray2)
						tmp++;
			}
			if (tmp == 0) 
			{
				*parray3 = *parray1;
				parray3++;
			}
			tmp = 0;
		}
		for (parray2 = array2; parray2 < array2 + size2; parray2++) 
		{
			for (parray1 = array1; parray1 < array1 + size1; parray1++) 
			{
				if (*parray2 == *parray1)
					tmp++;
			}
			if (tmp == 0) 
			{
				*parray3 = *parray2;
				parray3++;
			}
			tmp = 0;
		}
		cout << "\n������!\n\n";
		array3out(array3, size3);
		break;
	}
	return 0;
}





