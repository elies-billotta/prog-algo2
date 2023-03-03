/*#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
	// split

	// recursiv splitAndMerge of lowerArray and greaterArray

	// merge
}

void merge(Array& first, Array& second, Array& result)
{

}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}*/

#include <iostream>
#include <vector>

using namespace std; 

int min(std::vector<int> tab1, std::vector<int> tab2, int cursor);

void mergeSort(std::vector<int>& toSort){
	if (toSort.size() > 1){
		std::size_t const half_size = toSort.size() / 2;
		std::vector<int> split_lo(toSort.begin(), toSort.begin() + half_size);
		std::vector<int> split_hi(toSort.begin() + half_size, toSort.end());
		mergeSort(split_lo);
		mergeSort(split_hi);
		for (int i = 0 ; i < toSort.size() ; i++){
			toSort[i] = min(split_lo, split_hi, i);
		}
	}
	else{
		std::vector<int> split_lo;
		split_lo.push_back(toSort[0]);
	}
}

int min(std::vector<int> tab1, std::vector<int> tab2, int cursor){
	if (tab1[cursor] < tab2[cursor]){
		return tab1[cursor];
	}
	else{
		return tab2[cursor];
	}
}

int main(){
	std::vector<int> toSort = {3, 2, 1, 5, 4};
	mergeSort(toSort);
	for (int i = 0 ; i < toSort.size() ; i++){
		std::cout << toSort[i] << std::endl;
	}
	return 0;
}
