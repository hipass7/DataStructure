#include <iostream>
#include "TextEditor.h"
using namespace std;

int main() {

	TextEditor editor;

	char text1[80] = "The is the first line of text.";
	char text2[80] = "This is the current line of text.";
	char text3[80] = "This is the last line of text.";
	editor.InsertItem(text1);
	editor.InsertItem(text2);
	editor.Print();

	editor.InsertItem(text3);
	editor.Print();

	return 0;
}

// d �亯 : c�� Big-O�� O(N)�� ���Ѵ�.
// header�� trailer�� ����Ű�� �����͸� ���� class ��� ������ �����صθ� O(1)�� �����ϴ�. �ڼ��� ���ϸ�,
// header�� ����Ű�� �����Ϳ��� ->next�� �ϸ� GoToTop�� �����ϰ� trailer�� ����Ű�� �����Ϳ��� ->back�� �ϸ� GoToBottom�� �����ϴ�.