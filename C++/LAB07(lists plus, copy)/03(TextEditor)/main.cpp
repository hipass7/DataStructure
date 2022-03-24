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

// d 답변 : c의 Big-O는 O(N)에 속한다.
// header와 trailer를 가리키는 포인터를 각각 class 멤버 변수로 지정해두면 O(1)이 가능하다. 자세히 말하면,
// header를 가리키는 포인터에서 ->next를 하면 GoToTop이 가능하고 trailer를 가리키는 포인터에서 ->back을 하면 GoToBottom이 가능하다.