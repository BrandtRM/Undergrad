// Test code for editor
#include "ECTextViewImp.h"
#include <iostream>
#include "ECEditor.h"

using namespace  std;

int myCounter = 0;

int main(int argc, char *argv[])
{
    if(argc == 2){
        ECEditor editor(argv[1]);
        editor.WriteToFile(argv[1]);
    }
    else{
        cout << "Invalid argument" << endl;
    }   

    return 0;
}
