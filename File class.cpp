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
	newNode = Head->next; //맨 처음노드부터 시작
	while (newNode != NULL)//노드가 NULL이아니면
	{
		Head->next = newNode->next;//head가 현재노드의 주소가 가리키는 값을 가지고
		delete newNode; // 회수
		newNode = Head->next; // 그리고 다시 돌려받기 = 계속 주소를 따라서 이동
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
	//연결리스트 만들기
	naCount = makeLinkedList(Head, Filetxt);

	//출력하기
	int GetnCount = 1;

	if (Head->next == NULL)
	{
		cout << endl << "\t\t\t\t\t== 현재 대출한 책이 없습니다. ==" << endl << endl;
	}
	else
	{
		newNode = Head->next;
		cout << endl << "\t\t\t\t\t 제목     /     작가     /     출판년도" << endl << endl;
		while (GetnCount <= naCount)
		{
			cout << "<" << GetnCount << ">" << " " << newNode->chInformation << endl << endl;
			newNode = newNode->next;
			GetnCount++;
		}
	}

	//회수하기
	returnNode();
	system("pause");
}

void File::insertbook()
{
	char chInformationBuffer[F_SIZE] = "\0";
	int nReturnIndex = 0;
	//연결리스트 만들기
	nReturnIndex = makeLinkedList(Head, Filetxt);

	//정보 입력
	Help.GetName();
	getchar();
	cin.getline(chFName, SIZE, '\n');

	//오류
	if (chFName[0] == ' ') { Help.error(); return; }

	Help.GetWriter();
	cin.getline(chFWriter, SIZE, '\n');

	//오류
	if (chFWriter[0] == ' ') { Help.error(); return; }

	Help.GetYear();
	cin >> nFYear;
	if (nFYear >= 0 && nFYear <= 9999)
	{
		sprintf(chInformationBuffer, "%s / %s / %d\n", chFName, chFWriter, nFYear);
	}

	//오류
	else { Help.error(); return; }

	//추가하기
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

	// 연결리스트를 파일에 뒤집어 씌우기
	linkedlistTofile(Filetxt);

	//회수하기
	returnNode();
	Help.CompleteInsert();
}

void File::deletebook()
{
	char chInformationBuffer[F_SIZE] = "\0";
	int nReturnIndex = 0;

	//연결리스트 만들기
	nReturnIndex = makeLinkedList(Head, Filetxt);

	//정보 입력
	Help.GetName();
	getchar();
	cin.getline(chFName, SIZE, '\n');

	//오류
	if (chFName[0] == ' ') { Help.error(); return; }

	Help.GetWriter();
	cin.getline(chFWriter, SIZE, '\n');

	//오류
	if (chFWriter[0] == ' ') { Help.error(); return; }

	Help.GetYear();
	cin >> nFYear;
	if (nFYear >= 0 && nFYear <= 9999)
	{
		sprintf(chInformationBuffer, "%s / %s / %d\n", chFName, chFWriter, nFYear);
	}
	//오류
	else { Help.error(); return; }

	//도서가 없는 경우
	int nGetCount = 0;
	Filetxt = fopen("Book.txt", "r");

	while (fgets(chBuffer, F_SIZE, Filetxt)) // 파일의 맨 끝까지 갈 때 까지 진행
	{
		if (strstr(chInformationBuffer, chBuffer) != NULL)
		{
			nGetCount++;
		}

		else if (strstr(chInformationBuffer, chBuffer) == NULL)
		{
			continue;//계속 0으로 진행
		}
	}

	if (nGetCount == 0)
	{
		Help.NoBook();
		return;
	}

	// 특정 노드 삭제하기
	Book* delNode = new Book();
	delNode = Head->next;
	Book* befNode = Head;
	Book* nextNode;
	nextNode = delNode->next;

	int nIndex = 0; // 처음을 표현

	while (delNode != NULL) // 노드가 NULL 일 때 까지
	{
		if (strstr(delNode->chInformation, chInformationBuffer) != NULL) // 노드안에 있는 chInformation 안에 아까 입력한 chBuffer가 있을 때
		{
			if (delNode->next == NULL) // 다음 노드가 없을 때
			{
				if (nIndex == 0) // 노드가 하나만 있을 때
				{
					delete delNode;

					Head->next = NULL;
					Tail = Head;

					//연결리스트 텍스트 파일에 뒤집어 씌우기
					linkedlistTofile(Filetxt);

					//회수하기 => 함수화
					returnNode();
					Help.CompleteDelete();
					return;
				}

				else // 노드가 맨 끝에 있을 때
				{
					befNode->next = NULL;
					delete delNode;
					Tail = befNode;

					//연결리스트 텍스트 파일에 뒤집어 씌우기
					linkedlistTofile(Filetxt);

					//회수하기
					returnNode();
					Help.CompleteDelete();
					return;
				}
			}
			else // 다음 노드가 있을 때
			{
				if (nIndex == 0) // 처음 일 때
				{
					Head->next = nextNode;
					delete delNode;

					//연결리스트 텍스트 파일에 뒤집어 씌우기
					linkedlistTofile(Filetxt);

					//회수하기
					returnNode();
					Help.CompleteDelete();
					return;
				}

				else // 처음이 아닐 때
				{
					befNode->next = nextNode;
					delete delNode;

					//연결리스트 텍스트 파일에 뒤집어 씌우기
					linkedlistTofile(Filetxt);

					//회수하기
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

	//오류
	if (chBookInformation[0] == ' ') { Help.error(); return; }

	//도서가 없는 경우
	int nGetCount = 0;
	Filetxt = fopen("Book.txt", "r");

	while (fgets(chBuffer, F_SIZE, Filetxt)) // 파일의 맨 끝까지 갈 때 까지 진행
	{
		if (strstr(chBuffer, chBookInformation) != NULL)
		{
			nGetCount++;
		}


		else if (strstr(chBuffer, chBookInformation) == NULL)
		{
			continue;//계속 0으로 진행
		}
	}

	if (nGetCount == 0)
	{
		Help.NoBook();
		fclose(Filetxt);
		return;
	}
	fclose(Filetxt);

	//특정 도서 출력
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
	//오류
	else { Help.error(); return; }
}