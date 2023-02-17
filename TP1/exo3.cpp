/*#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);


int search(int value, Array& toSort, int size)
{
    Context _("search", value, size); // do not care about this, it allow the display of call stack

    // your code
    // check the last cell and if it does not correspond
    // then consider a smaller array when recalling search
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new SearchWindow(search); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}*/

#include <iostream>

using namespace std;

int search(int value, int toSort[], int size){
    if (size == -1) return -1;
    if(toSort[size] == value) return size;
    return search(value, toSort, size-1);
}

int main(){
    int toSort[] = {1, 2, 3, 4, 5};
    cout << search(3, toSort, 4) << endl;
    cout << search(13, toSort, 4) << endl;
    return 0;
}