/*#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);

void allEvens(Array& evens, Array& array, int evenSize, int arraySize)
{
    Context _("allEvens", evenSize, arraySize); // do not care about this, it allow the display of call stack

    // your code

    return;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new AllEvensWindow(allEvens); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}*/

#include <iostream>

using namespace std;

void printArray(int array[], int size){
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int* allEvens(int evens[], int array[], int evenSize, int arraySize){
    if (arraySize == 0) return evens;
    if (array[arraySize-1]%2 == 0){
        evens[evenSize-1] = array[arraySize-1];
        return allEvens(evens, array, evenSize-1, arraySize-1);
    }
    return allEvens(evens, array, evenSize, arraySize-1);
}

int main(){
    int evens[] = {0, 0, 0, 0, 0};
    int array[] = {1, 2, 3, 4, 5};
    printArray(allEvens(evens, array, 5, 5), 5);
    return 0;
}




