#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <stdio.h>
#define LL long long int
using namespace std;
int main(){
	unordered_map<string, int> map;
	string input;
	int counter = 0;
	int lamda = 0;
	while(getline(cin, input, '\n')){
		// end of text
		if(input.compare("****END_OF_TEXT****") == 0){
			//ouput statistic
			double loglamda = log10((double)lamda);
			//
			double tmpsum = 0;
			for(unordered_map<string, int>::iterator i = map.begin();i != map.end(); i++){
				// cout << i -> first << endl;
				tmpsum += (double)(i->second)*(loglamda - log10((double)i->second));
			}
			// if(counter++ != 0) cout << "\n";
			cout << lamda << " " ;
			printf("%.1lf %.0lf\n", tmpsum / lamda , ((tmpsum /(double)lamda) /loglamda)*100);
			// cout << " " <<(int)round(((tmpsum /(double)lamda) /loglamda)*100);
			map.clear();
			lamda = 0;
			continue;
		}
		// end of input
		else if(input.compare("****END_OF_INPUT****") == 0){
			break;
		}
		int pos = 0;
		bool isfirst = false;
		for(int i = 0; i < input.size(); i++){
			input[i] = tolower(input[i]);
			// chech punctuation
			if(input[i] == ',' || input[i] == '.' || input[i] == ':' ||
				input[i] == ';'|| input[i] =='!'  || input[i] =='?'  || 
				input[i] == '\"'|| input[i] =='(' || input[i] ==')' || 
				input[i] == ' ' || input[i] == '\t'){
				if(isfirst){
					map[input.substr(pos, i - pos)]++;
					// cout << input.substr(pos, i - pos) << "\n";
					isfirst = false;
				}
			}
			// first not delimiter letter
			else if(!isfirst){
				pos = i;
				lamda++;
				isfirst = true;
			}
		}
		//last element
		if(isfirst){
			map[input.substr(pos, input.size() - pos)]++;
			// cout << input.substr(pos,input.size() - pos) << "\n";
		}

	}
	return 0;
}