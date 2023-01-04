all:
	g++ -std=c++11 ECTextViewImp.h ECObserver.h ECEditor.h ECEditorTest.cpp ECTextViewImp.cpp ECEditor.cpp -o myeditor