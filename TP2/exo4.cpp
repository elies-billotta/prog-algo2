/*#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	// split
	
	// recursiv sort of lowerArray and greaterArray

	// merge
}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}*/

using namespace std;

#include <iostream>
#include <vector>

void quickSort(std::vector<int>& toSort){
	int size = toSort.size();
	if (size > 1){
		int pivot = rand()%toSort.size();
		int tab_pivot = toSort[pivot];
		std::vector<int> lowers;
		std::vector<int> greaters;
		for(int i = 0 ; i < size; i++){
			if (pivot != i){
				if (toSort[i] < toSort[pivot]) lowers.push_back(toSort[i]); 
				else greaters.push_back(toSort[i]);
			}
		}
		quickSort(lowers);
		quickSort(greaters);
		toSort.clear();
		toSort.insert(toSort.end(), lowers.begin(), lowers.end());
		toSort.push_back(tab_pivot);
		toSort.insert(toSort.end(), greaters.begin(), greaters.end());
	}
}

int main(){
	std::vector<int> toSort = {3, 2, 1, 5, 4};
	quickSort(toSort);
	for (int i = 0 ; i < toSort.size() ; i++){
		std::cout << toSort[i] << std::endl;
	}
	return 0;
}