#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
using namespace std;
bool isequal(int array1[5][5],int array2[5][5]);
void function(int array[5][5]);
int find_index(int array[5][5]);
int find_index(int array[5][5]){
	int zeromatrix[5][5] = {0}, array2[5][5] = {0};
	int counter = 0;
	//preprocess:
	//1. copy array to array2
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			array2[i][j] = array[i][j];
		}
	}
	//2. check if array is all zero 
	if(isequal(array,zeromatrix)) return -1;
	//while loop
	while(true){
		//function mapping
		function(array2);
		//check if array 2 is all zero
		if(isequal(array2,zeromatrix)) return counter;
		//if not, check if array2 is not equal to original array
		if(!isequal(array,array2)) counter++;
	}
	return counter;
}
void function(int array[5][5]){
	int storage[5][5] = {0};
	//store value
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			storage[i][j] = array[i-1][j] + array[i+1][j] + array[i][j-1] + array[i][j+1];
		}
	}
	//convert
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			array[i][j] = storage[i][j] % 2;
			// cout << array[i][j] << " ";
		}
		// cout << endl;
	}
	return;
}
bool isequal(int array1[5][5],int array2[5][5]){
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <=3; j++){
			if(array1[i][j] != array2[i][j])
				return false;
		}
	}
	return true;
}
int main(){
	int n; cin >> n;
	int array[5][5] = {0};
	for(int i = 1; i <= n; i++){
		//input
		char input[10];
		if(i == 1) cin.ignore(2);
		else cin.ignore(1);
		for(int j = 1; j <= 3; j++){
			cin.getline(input,10);
			for(int k = 1; k <= 3; k++){
				array[j][k] = input[k-1] - '0';
				// cout << array[j][k] << " ";
			}
			// cout <<endl;
		}

		//
		cout << find_index(array) << endl;
	}
}