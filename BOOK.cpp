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
		case 1: // ��ü ���� ��� =>������ �о� �ͼ� ���Ḯ��Ʈ�� ���� ������ ��� E
			myfile.printallindex();
			break;
		case 2: // ���� �߰� =>������ �о� �ͼ� ���Ḯ��Ʈ�� ���� ������ �߰��ϰ� �װ� �ٽ� ���Ͽ� ������ ����� E
			myfile.insertbook();
			break; 
		case 3: // ���� ���� =>������ �о� �ͼ� ���Ḯ��Ʈ�� ���� ������ Ư�� ��� ���� �ϰ� �װ� �ٽ� ���Ͽ� ������ �����
			break;
		case 4: // ���� �˻� =>������ �о� �ͼ� Ư�� ���� �˻� �ϰ� �װ͵��� ���Ḯ��Ʈ�� ���� ����ϱ�
			break; 
		case 5: // ��ü ���� ��� �ʱ�ȭ =>������ �������� �ٽ� �������
			break;
		case 6: // ����
			return 0;
		default: // �ùٸ��� ���� �Է�
			return 0;
		}
	}

	delete myfile.Head;
	cout << endl; system("pause"); return 0;
}