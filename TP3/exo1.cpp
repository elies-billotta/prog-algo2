#include <iostream>
#include <vector>

using namespace std;

int binarySearch(std::vector<int> tab, int toSearch){
	int mid = 0;
	int start = 0; 
	int end = tab.size();
	while(start < end){
		mid = (start + end) / 2;
		if (toSearch > tab[mid]) start = mid + 1;
		else if (toSearch < tab[mid]) end = mid;
		else return mid; 
	}
	return -1;
}

int main(){
	std::vector<int> tab = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int toSearch = 10;
	int result = binarySearch(tab, toSearch);
	cout << "Le chiffre " << toSearch << " est à l'index : " << result << endl;
	return 0;
}