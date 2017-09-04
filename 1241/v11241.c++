#include <iostream>
#include <cmath>
using namespace std;
int array[2000] = {0};
int T, N, M;
int DC(int array[], int left, int right, int& counter){
	// base case
	if(right - left == 1){
		if(array[left] && array[right]){
			return 1;
		}else if(array[left] || array[right]){
			counter++;
			return 1;
		}else{
			return 0;
		}
	}else{
		int left_exist = DC(array, left, (left + right + 1) / 2 - 1, counter);
		int right_exist = DC(array, (left + right + 1) / 2, right, counter);
		if(left_exist && right_exist){
			return 1; // this part is exist 
		}
		// if one of exist

		else if(left_exist || right_exist){
			counter++;
			return 1; // this part is exist
		}
		// if neither of them is exist
		else{
			return 0;

		}
	}
	return -1;
}
int main(){
	cin >> T;
	for(int i = 0; i < T; i++){
		int withdraw;
		int counter = 0;
		cin >> N >> M;
		// initial array
		for(int j = 0; j < pow(2, N); j++){
			array[j] = 1;
		}
		// withdraw
		for(int j = 0; j < M; j++){
			cin >> withdraw;
			array[withdraw - 1] = 0;
		}
		DC(array, 0, pow(2, N)-1, counter);
		cout << counter << "\n";

	}
	return 0;
}