#include "BOOK.h"

int File::makeLinkedList(Book* Head, FILE* Filetxt)
{
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

	return npCount;
}

void File::returnNode()
{
	newNode = Head->next; //�� ó�������� ����
	while (newNode != NULL)//��尡 NULL�̾ƴϸ�
	{
		Head->next = newNode->next;//head�� �������� �ּҰ� ����Ű�� ���� ������
		delete newNode; // ȸ��
		newNode = Head->next; // �׸��� �ٽ� �����ޱ� = ��� �ּҸ� ���� �̵�
	}
}

void File::linkedlistTofile(FILE* Filetxt)
{
	newNode = Head->next;

	Filetxt = fopen("Book.txt", "w");

	while (newNode != NULL)
	{
		fprintf(Filetxt, "%s", newNode->chInformation);
		newNode = newNode->next;
	}

	fclose(Filetxt);
}

void File::printallindex()
{
	int naCount = 0;
	//���Ḯ��Ʈ �����
	naCount = makeLinkedList(Head, Filetxt);

	//����ϱ�
	int GetnCount = 1;

	if (Head->next == NULL)
	{
		cout << endl << "\t\t\t\t\t== ���� ������ å�� �����ϴ�. ==" << endl << endl;
	}
	else
	{
		newNode = Head->next;
		cout << endl << "\t\t\t\t\t ����     /     �۰�     /     ���ǳ⵵" << endl << endl;
		while (GetnCount <= naCount)
		{
			cout << "<" << GetnCount << ">" << " " << newNode->chInformation << endl << endl;
			newNode = newNode->next;
			GetnCount++;
		}
	}

	//ȸ���ϱ�
	returnNode();
	system("pause");
}

void File::insertbook()
{
	char chInformationBuffer[F_SIZE] = "\0";
	int nReturnIndex = 0;
	//���Ḯ��Ʈ �����
	nReturnIndex = makeLinkedList(Head, Filetxt);

	//���� �Է�
	Help.GetName();
	getchar();
	cin.getline(chFName, SIZE, '\n');

	//����
	if (chFName[0] == ' ') { Help.error(); return; }

	Help.GetWriter();
	cin.getline(chFWriter, SIZE, '\n');

	//����
	if (chFWriter[0] == ' ') { Help.error(); return; }

	Help.GetYear();
	cin >> nFYear;
	if (nFYear >= 0 && nFYear <= 9999)
	{
		sprintf(chInformationBuffer, "%s / %s / %d\n", chFName, chFWriter, nFYear);
	}

	//����
	else { Help.error(); return; }

	//�߰��ϱ�
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

	// ���Ḯ��Ʈ�� ���Ͽ� ������ �����
	linkedlistTofile(Filetxt);

	//ȸ���ϱ�
	returnNode();
	Help.CompleteInsert();
}

void File::deletebook()
{
	char chInformationBuffer[F_SIZE] = "\0";
	int nReturnIndex = 0;

	//���Ḯ��Ʈ �����
	nReturnIndex = makeLinkedList(Head, Filetxt);

	//���� �Է�
	Help.GetName();
	getchar();
	cin.getline(chFName, SIZE, '\n');

	//����
	if (chFName[0] == ' ') { Help.error(); return; }

	Help.GetWriter();
	cin.getline(chFWriter, SIZE, '\n');

	//����
	if (chFWriter[0] == ' ') { Help.error(); return; }

	Help.GetYear();
	cin >> nFYear;
	if (nFYear >= 0 && nFYear <= 9999)
	{
		sprintf(chInformationBuffer, "%s / %s / %d\n", chFName, chFWriter, nFYear);
	}
	//����
	else { Help.error(); return; }

	//������ ���� ���
	int nGetCount = 0;
	Filetxt = fopen("Book.txt", "r");

	while (fgets(chBuffer, F_SIZE, Filetxt)) // ������ �� ������ �� �� ���� ����
	{
		if (strstr(chInformationBuffer, chBuffer) != NULL)
		{
			nGetCount++;
		}

		else if (strstr(chInformationBuffer, chBuffer) == NULL)
		{
			continue;//��� 0���� ����
		}
	}

	if (nGetCount == 0)
	{
		Help.NoBook();
		return;
	}

	// Ư�� ��� �����ϱ�
	Book* delNode = new Book();
	delNode = Head->next;
	Book* befNode = Head;
	Book* nextNode;
	nextNode = delNode->next;

	int nIndex = 0; // ó���� ǥ��

	while (delNode != NULL) // ��尡 NULL �� �� ����
	{
		if (strstr(delNode->chInformation, chInformationBuffer) != NULL) // ���ȿ� �ִ� chInformation �ȿ� �Ʊ� �Է��� chBuffer�� ���� ��
		{
			if (delNode->next == NULL) // ���� ��尡 ���� ��
			{
				if (nIndex == 0) // ��尡 �ϳ��� ���� ��
				{
					delete delNode;

					Head->next = NULL;
					Tail = Head;

					//���Ḯ��Ʈ �ؽ�Ʈ ���Ͽ� ������ �����
					linkedlistTofile(Filetxt);

					//ȸ���ϱ� => �Լ�ȭ
					returnNode();
					Help.CompleteDelete();
					return;
				}

				else // ��尡 �� ���� ���� ��
				{
					befNode->next = NULL;
					delete delNode;
					Tail = befNode;

					//���Ḯ��Ʈ �ؽ�Ʈ ���Ͽ� ������ �����
					linkedlistTofile(Filetxt);

					//ȸ���ϱ�
					returnNode();
					Help.CompleteDelete();
					return;
				}
			}
			else // ���� ��尡 ���� ��
			{
				if (nIndex == 0) // ó�� �� ��
				{
					Head->next = nextNode;
					delete delNode;

					//���Ḯ��Ʈ �ؽ�Ʈ ���Ͽ� ������ �����
					linkedlistTofile(Filetxt);

					//ȸ���ϱ�
					returnNode();
					Help.CompleteDelete();
					return;
				}

				else // ó���� �ƴ� ��
				{
					befNode->next = nextNode;
					delete delNode;

					//���Ḯ��Ʈ �ؽ�Ʈ ���Ͽ� ������ �����
					linkedlistTofile(Filetxt);

					//ȸ���ϱ�
					returnNode();
					Help.CompleteDelete();
					return;
				}
			}
		}

		befNode = delNode;
		delNode = delNode->next;
		nextNode = delNode->next;
		nIndex++;
	}
}

void File::searchbook()
{
	system("cls");
	char chBookInformation[SIZE] = "\0";
	char chPrintInformation[F_SIZE] = "\0";
	char chBuffer[F_SIZE] = "\0";
	int nPrintCount = 1;

	Help.GetInformation();
	getchar();
	cin.getline(chBookInformation, SIZE, '\n');

	//����
	if (chBookInformation[0] == ' ') { Help.error(); return; }

	//������ ���� ���
	int nGetCount = 0;
	Filetxt = fopen("Book.txt", "r");

	while (fgets(chBuffer, F_SIZE, Filetxt)) // ������ �� ������ �� �� ���� ����
	{
		if (strstr(chBuffer, chBookInformation) != NULL)
		{
			nGetCount++;
		}


		else if (strstr(chBuffer, chBookInformation) == NULL)
		{
			continue;//��� 0���� ����
		}
	}

	if (nGetCount == 0)
	{
		Help.NoBook();
		fclose(Filetxt);
		return;
	}
	fclose(Filetxt);

	//Ư�� ���� ���
	Filetxt = fopen("Book.txt", "r");
	while (fgets(chPrintInformation, F_SIZE, Filetxt))
	{
		if (strstr(chPrintInformation, chBookInformation) != NULL)
		{
			cout << "<" << nPrintCount << "> " << chPrintInformation << endl;
			nPrintCount++;
		}
	}

	fclose(Filetxt);
	system("pause");
}

void File::initializeindex()
{
	system("cls");

	char chinitialize[10] = {};
	Help.HowInitialize();
	cin >> chinitialize;

	if (chinitialize[0] == 'y' || chinitialize[0] == 'Y')
	{
		Filetxt = fopen("Book.txt", "w");
		fclose(Filetxt);

		Help.InitializeComplete();
		return;
	}
	//����
	else { Help.error(); return; }
}