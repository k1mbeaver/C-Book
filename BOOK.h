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
	cout << "\t\t\t\t\t환영합니다. 도서관리 프로그램입니다." << endl;
	cout << "=====================================================================================================================" << endl;
}

int Book::menu()
{
	system("cls");
	int nButton;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t\t메뉴" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t1. 전체 도서 목록 불러오기" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t2. 도서 추가하기" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t3. 도서 삭제하기" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t4. 도서 정보 검색" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t5. 도서 목록 초기화" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "\t\t\t\t\t\t6. 종료" << endl;
	cout << "=====================================================================================================================" << endl;
	cout << "사용할 기능의 번호를 입력하고 Enter를 눌러 주세요(6번을 누르거나 다른것을 누를시 프로그램이 종료됩니다.) : ";
	cin >> nButton;

	if (nButton >= 1 && nButton <= 6)
	{
		cout << "성공!" << " 값은 : " << nButton << endl;
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
	void FileRead() // 파일을 읽어 와서 연결리스트로 만들기( 자주 써먹을 예정 )
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

		//연결리스트 만들기 => 함수화
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

		//출력하기 =>함수화
		int GetnCount = 1;

		if (Head->next == NULL)
		{
			cout << endl << "\t\t\t\t\t== 현재 대출한 책이 없습니다. ==" << endl << endl;
		}
		else
		{
			newNode = Head->next;
			cout << endl << "\t\t\t 제목 \t/\t 작가\t/\t 출판년도" << endl << endl;
			while (GetnCount <= npCount)
			{
				cout << "<" << GetnCount << ">" << " " << newNode->chInformation << endl << endl;
				newNode = newNode->next;
				GetnCount++;
			} 
		}

		//회수하기 => 함수화
		newNode = Head->next; //맨 처음노드부터 시작
		while (newNode != NULL)//노드가 NULL이아니면
		{
			Head->next = newNode->next;//head가 현재노드의 주소가 가리키는 값을 가지고
			delete newNode; // 회수
			newNode = Head->next; // 그리고 다시 돌려받기 = 계속 주소를 따라서 이동
		}
		system("pause");
	}

	void insertbook()
	{
		//연결리스트 만들기 => 함수화
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

		//추가하기 =>함수화
		cout << endl << "책의 이름(영문 100자 이내, 한글 30자 이내, 공백포함, 처음에 공백이 있으면 실행실패) : ";
		cin >> chFName;
		cout << endl << "책의 작가(영문 100자 이내, 한글 30자 이내, 공백포함, 처음에 공백이 있으면 실행실패) : ";
		cin >> chFWriter;
		cout << endl << "출판 년도(0~9999까지의 숫자를 입력하여 주세요) : ";
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

		//회수하기 => 함수화
		newNode = Head->next; //맨 처음노드부터 시작
		while (newNode != NULL)//노드가 NULL이아니면
		{
			Head->next = newNode->next;//head가 현재노드의 주소가 가리키는 값을 가지고
			delete newNode; // 회수
			newNode = Head->next; // 그리고 다시 돌려받기 = 계속 주소를 따라서 이동
		}
		cout << "도서 추가가 완료되었습니다!!" << endl;
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

	void makeLinkedList(); // 시작할 때 파일을 이용한 연결리스트 만들기
	void insert(char chInformation[SIZE]); // 노드 추가
	int nListSize = 0;
};

void Link::insert(char chInformation[SIZE])// 연결리스트에 추가
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
