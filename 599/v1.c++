#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
int N;
bool visit[100] = {0};
int parent[100] = {0};
vector<int> linklist[100]; // A's link B's link
vector<int> available_node;
void DFS(int node, bool& istree, int& counter){
	visit[node] = true;
	counter++;
	for(int i = 0; i < linklist[node].size(); i++){
		if(!visit[linklist[node][i]]){
			parent[linklist[node][i]] = node; // set parent
			DFS(linklist[node][i], istree, counter);
		}else{
			// traverse linklist node is not node's parent
			if(parent[node] != linklist[node][i]) istree = false;
		}
	}
	return;
}
int main(){
	cin >> N;
	cin.ignore();
	for(int i = 0; i < N; i++){
		string input;
		// parse edge input
		while(getline(cin, input)){
			if(input[0] == '('){
				linklist[input[1]-'A'].push_back(input[3] - 'A');
				linklist[input[3]-'A'].push_back(input[1] - 'A');
			}else break;
		}
		// parse available node
		getline(cin, input);
		for(int j = 0; j < input.size(); j++){
			if(input[j] != ','){
				available_node.push_back(input[j] - 'A');
			}
		}
		// traverse tree
		int tree = 0;
		int acorn = 0;
		for(int j = 0; j < available_node.size(); j++){
			bool istree = true;
			int counter = 0;
			if(!visit[available_node[j]])
				DFS(available_node[j], istree, counter);
			if(istree && counter > 1) tree++;
			else if(counter == 1) acorn++; 
		}
		cout << "There are " << tree <<" tree(s) and "<< acorn << " acorn(s)." << "\n";
		//clear
		available_node.clear();
		for(int j = 0; j < 100; j++){
			visit[j] = false;
			parent[j] = 0;
			linklist[j].clear();
		}
	}
}