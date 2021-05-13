#include "BOOK.h"
using namespace std;

int main()
{
	Book mybook;
	File myfile;

	while (1)
	{
		switch (mybook.menu())
		{
		case 1: // 전체 도서 목록 =>파일을 읽어 와서 연결리스트로 만든 다음에 출력 E
			myfile.printallindex();
			break;
		case 2: // 도서 추가 =>파일을 읽어 와서 연결리스트로 만든 다음에 추가하고 그걸 다시 파일에 뒤집어 씌우기 E !! 공백 입력 개선
			myfile.insertbook();
			break; 
		case 3: // 도서 삭제 =>파일을 읽어 와서 연결리스트로 만든 다음에 특정 노드 삭제 하고 그걸 다시 파일에 뒤집어 씌우기 E  !! 없는 값을 입력하면 오류가뜸
			myfile.deletebook();
			break;
		case 4: // 도서 검색 =>파일을 읽어 와서 특정 노드들 검색 하고 그것들을 연결리스트로 만들어서 출력하기
			myfile.searchbook();
			break; 
		case 5: // 전체 도서 목록 초기화 =>파일을 공백으로 다시 써버리기
			myfile.initializeindex();
			break;
		case 6: // 종료
			return 0;
		default: // 올바르지 않은 입력
			return 0;
		}
	}

	delete myfile.Head;
	cout << endl; system("pause"); return 0;
}