#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;
typedef pair<string, int> PAIR;
int counter = 0;
ostream& operator<<(ostream& out, const PAIR& p){
	return out << p.first << " "<<fixed<<setprecision(4) <<(double)p.second*100 / counter <<"\n";
}
int main(){
	int n; cin >> n;
	cin.ignore(2);
	for(int i = 0; i < n; i++){
		// build map with key = name , value = counter of tree
		map<string,int> treemap;
		string inputline; // tree's name
		while(getline(cin, inputline)){
			// if is newline character
			if(inputline.compare("") == 0) break;
			//cout << "inputline: " <<inputline <<endl;
			counter++; //count total tree number
			treemap[inputline]++; // count tree
		}
		for(map<string,int>::iterator it = treemap.begin();it != treemap.end();it++){
			cout << *it;
		}
		//reinitialize
		counter = 0;
		treemap.erase(treemap.begin(),treemap.end());
		if(i != n-1)cout << "\n";
	}

}