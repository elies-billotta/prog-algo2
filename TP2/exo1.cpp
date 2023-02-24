/*#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w = nullptr;

void selectionSort(Array& toSort){
	// selectionSort
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    w->show();

	return a.exec();
}*/ 

using namespace std;

#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& toSort){
    for (int i = 0 ; i < toSort.size() ; i++){
        int min = i;
        for(int j = i+1 ; j < toSort.size() ; j++){
            if (toSort[j] < toSort[min]){
                min = j;
            }
        }
        swap(toSort[i], toSort[min]);
    }
}

int main(){
    std::vector<int> toSort = {3, 2, 1, 5, 4};
    selectionSort(toSort);
    for (int i = 0 ; i < toSort.size() ; i++){
        std::cout << toSort[i] << std::endl;
    }
    return 0;
}