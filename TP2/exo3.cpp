/*#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
	// bubbleSort
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}*/

using namespace std;

#include <iostream>
#include <vector>

vector<int> bubbleSort(std::vector<int>& toSort){
	for (int i = 0 ; i < toSort.size() ; i++){
		for (int j = 0 ;  )
	}
}

int main(){
	std::vector<int> toSort = {3, 2, 1, 5, 4};
	std::vector<int> result = bubbleSort(toSort);
	for (int i = 0 ; i < result.size() ; i++){
		std::cout << result[i] << std::endl;
	}
	return 0;
}


