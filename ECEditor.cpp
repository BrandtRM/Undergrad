//
//  ECEditor.cpp
//  
//
//
//

#include "ECTextViewImp.h"
#include "ECObserver.h"
#include "ECEditor.h"
#include <string>
#include <fstream>

using namespace std;

ECEditor :: ECEditor(string filename) {
    // take in filename
    ifstream file(filename);

    // import file contents
    int linecount = 0;
    string line;
    vector<char> copyline;
    
    text.push_back({});
    if(file.is_open()){
        while(getline(file, line)){ 
            for(int i = 0; i < line.size(); i++){
                copyline.push_back(line.at(i));
            }
            text.push_back(copyline);
            copyline.clear();
            linecount++;
        }
    }

    // close file
    file.close();
    
    for(int i = 0; i < window.GetRowNumInView() - linecount - 1; i++){
        text.push_back({});
    }
    
    // setup window, attach observer, and show
    window.AddRow("");  
    window.AddStatusRow("Ryan Brandt", "Press ctrl-q to quit", 1);
    window.Attach(this);
    window.Show();
}


ECEditor :: ~ECEditor() {
    text.clear();
}


void ECEditor :: Update() {
    // get pressed key, x, and y cursor position
    int key = window.GetPressedKey();
    int x = window.GetCursorX();
    int y = window.GetCursorY();

    // move cursor left
    if(key == 1000){
        MoveCursorLeft(x, y);
    }

    // move cursor right
    if(key == 1001){
        MoveCursorRight(x, y);
    }

    // move cursor up
    if(key == 1002){
        MoveCursorUp(x, y);
    }

    // move cursor down
    if(key == 1003){
        MoveCursorDown(x, y);
    }

    // insert text
    if(key > 32 && key < 126){
        InsertText(key, x, y);
    }

    // remove text
    if(key == 127){
        if(x == 0){
            for(int i = 0; i < text[y + 1].size(); i++){
                text[y].push_back(text[y + 1].at(i));
            }
            auto it = text.erase(text.begin() + y + 1);
        }
        else{
            char c = text[y + 1].at(x - 1);
            RemoveText(c, x, y);
        }
    }

    // spacebar pressed
    if(key == 32){
        InsertText(' ', x, y);
    }

    // enter pressed
    if(key == 13){
        EnterPressed(x, y);
    }

    // undo
    if(key == 26){

    }

    // redo
    if(key == 25){

    }

    // Screen assembly
    Screen();
    
    // refresh window
    window.Refresh();
}


// move cursor left from position (x, y)
void ECEditor :: MoveCursorLeft(int x, int y){
    // cannot move left of 0
    if(x > 0){
        window.SetCursorX(x - 1);
    }
}


// move cursor right from position (x, y)
void ECEditor :: MoveCursorRight(int x, int y){
    // cannot move right of text or past window
    if(x < text[y + 1].size() && x < window.GetColNumInView()){
        window.SetCursorX(x + 1);
    }
}


// move cursor up from position (x, y)
void ECEditor :: MoveCursorUp(int x, int y){
    // cannot move above 0 and above text is larger
    if(y > 0 && text[y].size() >= x){
        window.SetCursorY(y - 1);
    }
    // cannot move above 0 and above text is smaller
    else if(y > 0 && text[y].size() < x){
        window.SetCursorX(text[y].size());
        window.SetCursorY(y - 1);
    }
}


// move cursor down from position (x, y)
void ECEditor :: MoveCursorDown(int x, int y){
    // cannot move past window and below text is larger
    if(y < window.GetRowNumInView() - 2 && text[y + 2].size() >= x){
        window.SetCursorY(y + 1);
    }
    // cannot move past window and below text is smaller
    else if(y < window.GetRowNumInView() - 2 && text[y + 2].size() < x){
        window.SetCursorX(text[y + 2].size());
        window.SetCursorY(y + 1);
    }
}


// enter pressed
void ECEditor :: EnterPressed(int x, int y){
    // enter pressed at end of line
    if(x == text[y + 1].size()){
        vector<char> blank = {};
        auto it = text.insert(text.begin() + y + 2, blank);

        if(y < window.GetRowNumInView() - 2){
            window.SetCursorX(0);
            window.SetCursorY(y + 1);
        }
    }
    // enter pressed at beginning of line
    else if(x == 0){
        vector<char> blank = {};
        auto it = text.insert(text.begin() + y + 1, blank);

        if(y < window.GetRowNumInView() - 2){
            window.SetCursorX(0);
            window.SetCursorY(y + 1);
        }
    }
    // enter pressed in the middle of a line
    else{
        vector<char> first;
        vector<char> second;

        for(int i = 0; i < text[y + 1].size(); i++){
            if(i < x){
                first.push_back(text[y + 1].at(i));
            }
            else{
                second.push_back(text[y + 1].at(i));
            }
        }

        text[y + 1].clear();
        for(int i = 0; i < first.size(); i++){
            text[y + 1].push_back(first.at(i));
        }
        auto it = text.insert(text.begin() + y + 2, second);


        if(y < window.GetRowNumInView() - 2){
            window.SetCursorX(0);
            window.SetCursorY(y + 1);
        }
    }    
}


// insert character c at position (cx, cy)
void ECEditor :: InsertText(char c, int cx, int cy) {
    if(cx == text[cy + 1].size()){
        text[cy + 1].push_back(c);
        window.SetCursorX(cx + 1);
    }
    else{
        vector<char> temp;

        // add characters to the left
        for(int i = 0; i < cx; i++){
            temp.push_back(text[cy + 1].at(i));
        }

        // insert character
        temp.push_back(c);

        // add characters to the right
        for(int i = cx; i < text[cy + 1].size(); i++){
            temp.push_back(text[cy + 1].at(i));
        }
        
        // clear old row and set new
        text[cy + 1].clear();
        text[cy + 1] = temp;
        window.SetCursorX(cx + 1);
    }
}


// remove character c at position (cx, cy)
void ECEditor :: RemoveText(char c, int cx, int cy) {
    if(c == text[cy + 1].at(cx - 1)){
        auto it = text[cy + 1].erase(text[cy + 1].begin() + cx - 1);
        window.SetCursorX(cx - 1);
    }
}


// set up screen
void ECEditor :: Screen(){
    // clears screen, creates strings, and prints screen
    window.InitRows();
    string curRow;
    for(int i = 0; i < window.GetRowNumInView(); i++){
        for(int j = 0; j < text[i].size(); j++){
            curRow += text[i].at(j);
        }
        if(curRow == ""){
            window.AddRow("~");
        }
        else{
            window.AddRow(curRow);
        }
        curRow.clear();
    }
}


// write back to the file
void ECEditor :: WriteToFile(string filename){
    // create output stream
    ofstream file(filename);

    //write to file
    string curRow;
    if(file.is_open()){
        for(int i = 0; i < text.size(); i++){
            for(int j = 0; j < text[i].size(); j++){
                curRow += text[i].at(j);
            }
            if(curRow != ""){
                curRow += "\n";
                file << curRow;
                curRow.clear();
            }
        }
    }

    // close file
    file.close();
}