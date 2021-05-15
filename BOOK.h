#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#define SIZE 100
#define F_SIZE 210
using namespace std;

class Book {
public:
	Book* next = nullptr;

	char chInformation[F_SIZE] = "\0";
	int nButton = 0;

	int menu();
	void error();
	void NoBook();
	void CompleteDelete();
	void CompleteInsert();
	void GetName();
	void GetWriter();
	void GetYear();
	void GetInformation();
	void HowInitialize();
	void InitializeComplete();
};

class File {

public:
	char chFName[SIZE] = "\0";
	char chFWriter[SIZE] = "\0";
	int nFYear = 0;
	char chBuffer[F_SIZE] = "\0";

	Book chInformation[F_SIZE];
	FILE* Filetxt = NULL;
	Book* Head = new Book();
	Book* newNode = NULL;
	Book* Tail = NULL;

	int makeLinkedList(Book* Head, FILE* Filetxt);
	void returnNode();
	void linkedlistTofile(FILE* Filetxt);
	void printallindex();
	void insertbook();
	void deletebook();
	void searchbook();
	void initializeindex();
	Book Help;
};


