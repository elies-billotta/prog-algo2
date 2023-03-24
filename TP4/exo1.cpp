//#include "tp4.h"
//#include "mainwindow.h"

/*#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChildIndex(int nodeIndex)
{
    return 0;
}

int Heap::rightChildIndex(int nodeIndex)
{
    return 0;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;
}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i_max = nodeIndex;
}

void Heap::buildHeap(Array& numbers)
{

}

void Heap::heapSort()
{

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}*/

#include <iostream>
#include <vector>

using namespace std;

struct Heap{

	std::vector<int> data;

	int Heap::leftChildIndex(int nodeIndex){
		return nodeIndex*2+1;
	}	

	int Heap::rightChildIndex(int nodeIndex)
{
    return nodeIndex*2+2;
}

	void Heap::insertHeapNode(int heapSize, int value)
	{
		// use (*this)[i] or this->data[i] to get a value at index i
		int i = heapSize;
		data[i] = value;
		while(i > 0 && data[i] > data[(i-1)/2]){
			int temp = data[i];
			data[i] = data[(i-1)/2];
			data[(i-1)/2] = temp;
			i = (i-1)/2;
		}
	}

	void Heap::heapify(int heapSize, int nodeIndex)
	{
		// use (*this)[i] or this->data[i] to get a value at index i
		int i = 0;
		int i_max = nodeIndex;
		if (i_max != i){
			int temp = data[i];
			data[i] = data[i_max];
			data[i_max] = temp;
			heapify(heapSize, i_max);
		}

	}

	void Heap::buildHeap(std::vector<int> numbers)
	{
		for(int i = 0 ; i< numbers.size() ; i++){
			heapify(data.size(), numbers[i]);
		}
	}

	void Heap::heapSort()
	{
		for (int i = data.size()-1; i != 0 ; i--){
			int temp = data[i];
			data[i] = data[0];
			data[0] = temp;
			heapify(i, 0);
		}
	}
};

int main(){
	return 1;
}
