/*#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
	Array& sorted=w->newArray(toSort.size());

	// insertion sort from toSort to sorted
	
	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}*/

using namespace std;

#include <iostream>
#include <vector>

vector<int> insertionSort(std::vector<int>& toSort){
	std::vector<int> result;
	result.push_back(toSort[0]);
	for(int i = 1 ; i < toSort.size() ; i++){
		bool inserted = false;
		for (int m = 0 ; m < result.size() ; m++){
			if (result[m] > toSort[i]){
				result.insert(result.begin() + m, toSort[i]);
				inserted = true;
				break;
			}
		}
		if (!inserted)result.push_back(toSort[i]);
	} 
	return result;
}

int main(){
	std::vector<int> toSort = {3, 2, 1, 5, 4};
	std::vector<int> result = insertionSort(toSort);
	for (int i = 0 ; i < result.size() ; i++){
		std::cout << result[i] << std::endl;
	}
	return 0;
}