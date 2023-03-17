#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief define indexMin and indexMax as the first and the last index of toSearch
 * @param array array of int to process
 * @param toSearch value to find
 * @param indexMin first index of the value to find
 * @param indexMax last index of the value to find
 */
void binarySearchAll(std::vector<int> array, int toSearch, int& indexMin, int& indexMax)
{
	
}



int main(int argc, char *argv[])
{
	std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int toSearch = 10;
	int indexMin = 0;
	int indexMax = 0;
	binarySearchAll(array, toSearch, indexMin, indexMax);
	cout << "Le chiffre " << toSearch << " est à l'index : " << indexMin << " et " << indexMax << endl;
	return 0;
}