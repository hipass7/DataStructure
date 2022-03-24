#include <iostream>
using namespace std;

struct LineType
{
	char info[80];
	LineType* next;
	LineType* back;
};

class TextEditor
{
	LineType* currentLine;

public:
	TextEditor();
	~TextEditor();
	// 소멸자도 구현은 하였습니다.
	void GoToTop();
	void GoToBottom();
	void InsertItem(char newline[]);
	// class 구현 테스트 해보기 위한 함수 임의로 추가
	void Print();
};

TextEditor::TextEditor() {
	LineType* header = new LineType;
	LineType* tailer = new LineType;

	strcpy_s(header->info, sizeof("---Top of file---"), "---Top of file---");
	strcpy_s(tailer->info, sizeof("---Bottom of file---"), "---Bottom of file---");

	header->next = tailer;
	tailer->back = header;
	header->back = NULL;
	tailer->next = NULL;

	currentLine = header;
}

TextEditor::~TextEditor() {
	LineType* tempPtr;

	GoToTop();

	currentLine = currentLine->back;

	while (currentLine->next != NULL)
	{
		tempPtr = currentLine;
		currentLine = currentLine->next;
		delete tempPtr;
	}
	delete currentLine;
}

void TextEditor::GoToTop() {

	while (currentLine->back != NULL)
		currentLine = currentLine->back;

	currentLine = currentLine->next;
}

void TextEditor::GoToBottom() {

	while (currentLine->next != NULL)
		currentLine = currentLine->next;

	currentLine = currentLine->back;
}

void TextEditor::InsertItem(char newline[])
{
	LineType* location;

	GoToBottom();

	location = new LineType;

	for (int i = 0; i <= strlen(newline); i++) {
		location->info[i] = newline[i];
	}
	/*for (int i = 0; newline[i] != '\0'; i++) {
		location->info[i] = newline[i];
	}*/
	location->back = currentLine;
	location->next = currentLine->next;

	currentLine->next->back = location;
	currentLine->next = location;
}

void TextEditor::Print() {
	GoToTop();

	while (currentLine->next != NULL) {
		cout << currentLine->info << endl;
		currentLine = currentLine->next;
	}
}