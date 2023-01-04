//
//  ECEditor.h
//
//
//
//

#ifndef ECEditor_h
#define ECEditor_h

#include "ECTextViewImp.h"
#include "ECObserver.h"
#include <vector>

using namespace std;

//********************************************
// Observer design pattern: subject

class ECEditor : public ECObserver
{
public:
    ECEditor(string filename);
    virtual ~ECEditor();

    void Update();
    void MoveCursorLeft(int x, int y);
    void MoveCursorRight(int x, int y);
    void MoveCursorUp(int x, int y);
    void MoveCursorDown(int x, int y);
    void EnterPressed(int x, int y);
    void InsertText(char c, int cx, int cy);
    void RemoveText(char c, int cx, int cy);
    void Screen();
    void WriteToFile(string filename);
   
private:
    vector<vector<char>> text;
    ECTextViewImp window;  
    string filename;
};


#endif