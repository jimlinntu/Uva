#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> path;
vector<vector<int>> answer;
void DFS(int number,int div){
	int bound = (int)sqrt(number);
	for(int i = div; i <= bound; i++){
		if(number % i == 0){
			path.push_back(i);
			DFS(number/i,i);
			path.pop_back();
		}
	}

	path.push_back(number);
	answer.push_back(path);
	path.pop_back();
}
int main(){
	int number;
	while(cin >> number){
		if(number == 0) break;
		DFS(number,2);
		answer.pop_back(); // since answer's last element is itself
		cout << answer.size() << "\n";
		for(int i = 0; i < answer.size(); i++){
			for(int j = 0; j < answer[i].size(); j++){
				if(j != 0){
					cout << " " << answer[i][j];
				}else cout << answer[i][j];
			}
			cout << "\n";
		}
		path.clear();
		answer.clear();
	}
	return 0;
}