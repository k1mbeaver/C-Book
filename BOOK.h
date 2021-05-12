#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#define SIZE 100
#define F_SIZE 210
using namespace std;

class Book {
public :
	Book* next = nullptr;
	char chInformation[F_SIZE] = "\0";
	int nButton = 0;

	void start();
	int menu();
};

void Book::start()
{
	cout << "=====================================================================================================================" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\tȯ���մϴ�. �������� ���α׷��Դϴ�." << endl;
	cout << "=====================================================================================================================" << endl;
}

int Book::menu()
{
	system("cls");
	int nButton;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t\t�޴�" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t1. ��ü ���� ��� �ҷ�����" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t2. ���� �߰��ϱ�" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t3. ���� �����ϱ�" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t4. ���� ���� �˻�" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t5. ���� ��� �ʱ�ȭ" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t6. ����" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "����� ����� ��ȣ�� �Է��ϰ� Enter�� ���� �ּ���(6���� �����ų� �ٸ����� ������ ���α׷��� ����˴ϴ�.) : ";
	cin >> nButton;

	if (nButton >= 1 && nButton <= 6)
	{
		cout << "����!" << " ���� : " << nButton << endl;
		return nButton;
	}
	else
	{
		return 0;
	}
}

class File {

public:
	char chFName[SIZE] = "\0";
	char chFWriter[SIZE] = "\0";
	int nFYear = 0;
	char chBuffer[F_SIZE] = "\0";
	Book chInformation[F_SIZE];
	FILE* Filetxt = NULL;
	FILE* Filetxt2 = NULL;
	Book* Head = new Book();
	Book* newNode = NULL;
	Book* Tail = NULL;
	
	/*
	void FileRead() // ������ �о� �ͼ� ���Ḯ��Ʈ�� �����( ���� ����� ���� )
	{
		Head->next = NULL;
		Filetxt = fopen("Book.txt", "r");

		while (fgets(chBuffer, F_SIZE, Filetxt) != NULL)
		{
			Book* newNode = new Book();

			strcpy(newNode->chInformation, chBuffer);

			if (Head->next == NULL)
			{
				Head->next = newNode;
			}
			else
			{
				Tail->next = newNode;
			}
			newNode->next = NULL;
			Tail = newNode;
		}

		fclose(Filetxt);
	}
	*/

	void printallindex()
	{

		//���Ḯ��Ʈ ����� => �Լ�ȭ
		system("cls");
		int npCount = 0; // 
		Head->next = NULL;
		Filetxt = fopen("Book.txt", "r");

		while (fgets(chBuffer, F_SIZE, Filetxt) != NULL)
		{
			Book* newNode = new Book();

			strcpy(newNode->chInformation, chBuffer);

			if (Head->next == NULL)
			{
				Head->next = newNode;
			}
			else
			{
				Tail->next = newNode;
			}
			newNode->next = NULL;
			Tail = newNode;
			npCount++;
		}

		fclose(Filetxt);

		//����ϱ� =>�Լ�ȭ
		int GetnCount = 1;

		if (Head->next == NULL)
		{
			cout << endl << "\t\t\t\t\t== ���� ������ å�� �����ϴ�. ==" << endl << endl;
		}
		else
		{
			newNode = Head->next;
			cout << endl << "\t\t\t ���� \t/\t �۰�\t/\t ���ǳ⵵" << endl << endl;
			while (GetnCount <= npCount)
			{
				cout << "<" << GetnCount << ">" << " " << newNode->chInformation << endl << endl;
				newNode = newNode->next;
				GetnCount++;
			} 
		}

		//ȸ���ϱ� => �Լ�ȭ
		newNode = Head->next; //�� ó�������� ����
		while (newNode != NULL)//��尡 NULL�̾ƴϸ�
		{
			Head->next = newNode->next;//head�� �������� �ּҰ� ����Ű�� ���� ������
			delete newNode; // ȸ��
			newNode = Head->next; // �׸��� �ٽ� �����ޱ� = ��� �ּҸ� ���� �̵�
		}
		system("pause");
	}

	void insertbook()
	{
		//���Ḯ��Ʈ ����� => �Լ�ȭ
		system("cls");
		int npCount = 0; // 
		Head->next = NULL;
		Filetxt = fopen("Book.txt", "r");

		while (fgets(chBuffer, F_SIZE, Filetxt) != NULL)
		{
			Book* newNode = new Book();

			strcpy(newNode->chInformation, chBuffer);

			if (Head->next == NULL)
			{
				Head->next = newNode;
			}
			else
			{
				Tail->next = newNode;
			}
			newNode->next = NULL;
			Tail = newNode;
			npCount++;
		}

		fclose(Filetxt);

		//�߰��ϱ� =>�Լ�ȭ
		cout << endl << "å�� �̸�(���� 100�� �̳�, �ѱ� 30�� �̳�, ��������, ó���� ������ ������ �������) : ";
		cin >> chFName;
		cout << endl << "å�� �۰�(���� 100�� �̳�, �ѱ� 30�� �̳�, ��������, ó���� ������ ������ �������) : ";
		cin >> chFWriter;
		cout << endl << "���� �⵵(0~9999������ ���ڸ� �Է��Ͽ� �ּ���) : ";
		cin >> nFYear;

		char chInformationBuffer[F_SIZE] = "\0";

		sprintf(chInformationBuffer, "%s / %s / %d\n", chFName, chFWriter, nFYear);

		Book* newNode = new Book();

		strcpy(newNode->chInformation, chInformationBuffer);

		if (Head->next == NULL)
		{
			Head->next = newNode;
		}
		else
		{
			Tail->next = newNode;
		}
		newNode->next = NULL;
		Tail = newNode;

		newNode = Head->next;

		Filetxt = fopen("Book.txt", "w");

		while (newNode != NULL)
		{
			fprintf(Filetxt, "%s", newNode->chInformation);
			newNode = newNode->next;
		}

		fclose(Filetxt);

		//ȸ���ϱ� => �Լ�ȭ
		newNode = Head->next; //�� ó�������� ����
		while (newNode != NULL)//��尡 NULL�̾ƴϸ�
		{
			Head->next = newNode->next;//head�� �������� �ּҰ� ����Ű�� ���� ������
			delete newNode; // ȸ��
			newNode = Head->next; // �׸��� �ٽ� �����ޱ� = ��� �ּҸ� ���� �̵�
		}
		cout << "���� �߰��� �Ϸ�Ǿ����ϴ�!!" << endl;
		system("pause");
	}
};
/*
class Link {
public :
	Book* head = new Book();
	Link() {
		head = NULL;
	};

	void makeLinkedList(); // ������ �� ������ �̿��� ���Ḯ��Ʈ �����
	void insert(char chInformation[SIZE]); // ��� �߰�
	int nListSize = 0;
};

void Link::insert(char chInformation[SIZE])// ���Ḯ��Ʈ�� �߰�
{
	if (nListSize == 0)
	{
		strcpy(head->chInformation, chInformation);
		head->next = NULL;
	}
	else
	{
		Book* currentNode = new Book();

		strcpy(currentNode->chInformation, chInformation);
		currentNode->next = NULL;

		Book* tempNode = head;

		while (tempNode->next != nullptr)
		{
			tempNode = tempNode->next;
		}

		tempNode->next = currentNode;
	}

	++nListSize;
}
*/