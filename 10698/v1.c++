#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <cctype>
using namespace std;
struct Team_Attribute{
	string teamname;
	int point; // Compare priority 1
	int number_of_games;
	int scored_goal; // Compare priority 3
	int scored_suffer; 
	int goal_difference; // Compare priority 2
};
bool compare(const Team_Attribute &t1, const Team_Attribute &t2){
	if(t1.point > t2.point){
		return true;
	}
	else if(t1.point == t2.point){
		if(t1.goal_difference > t2.goal_difference){
			return true;
		}else if(t1.goal_difference == t2.goal_difference){
			if(t1.scored_goal > t2.scored_goal){
				return true;
			}else if(t1.scored_goal == t2.scored_goal){
				//alphabetical oreder, there will some uppercase and lower case
				string tmp1 = t1.teamname, tmp2 = t2.teamname;
				for(int i = 0; i < tmp1.size(); i++){
					tmp1[i] = tolower(tmp1[i]);
				}
				for(int i = 0; i < tmp2.size(); i++){
					tmp2[i] = tolower(tmp2[i]);
				}
				if(tmp1.compare(tmp2) < 0){
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main(){
	int T, G;
	unordered_map<string, int> map_name_to_vector_position;
	vector<Team_Attribute> team_list; team_list.reserve(1000);
	int counter = 0;
	while(cin >> T && cin >> G){
		if(T == 0 && G == 0) break;
		if(counter != 0) cout << "\n";
		counter++;
		// set up name associated to attribute
		for(int i = 0; i < T; i++){
			string teamname;
			cin >> teamname;
			Team_Attribute tmp = {teamname,0,0,0,0,0};
			team_list.push_back(tmp);
			map_name_to_vector_position[teamname] = i;
		}
		//start to count win loss
		for(int i = 0; i < G; i++){
			string t1, t2, useless;
			int score1,score2;
			cin >> t1 >> score1 >> useless >> score2 >> t2;
			//number of games
			team_list[map_name_to_vector_position[t1]].number_of_games++;
			team_list[map_name_to_vector_position[t2]].number_of_games++;
			//scored goal, suffed goal
			team_list[map_name_to_vector_position[t1]].scored_goal += score1;
			team_list[map_name_to_vector_position[t2]].scored_goal += score2;
			team_list[map_name_to_vector_position[t1]].scored_suffer += score2;
			team_list[map_name_to_vector_position[t2]].scored_suffer += score1;
			//point
			if(score1 > score2){
				team_list[map_name_to_vector_position[t1]].point += 3;
			}else if(score1 == score2){
				team_list[map_name_to_vector_position[t1]].point += 1;
				team_list[map_name_to_vector_position[t2]].point += 1; 
			}else{
				team_list[map_name_to_vector_position[t2]].point += 3; 
			}
		}
		//set up goal difference
		for(int i = 0; i < T; i++){
			team_list[i].goal_difference = team_list[i].scored_goal - team_list[i].scored_suffer;
		}
		//sort it
		sort(team_list.begin(), team_list.end(),compare);
		//print out
		int now_position = 1;
		int tmp_point = -1, tmp_goal_difference = -1, tmp_scored_goal = -1;
		for(int i = 0; i < T; i++){
			if(team_list[i].point == tmp_point && team_list[i].goal_difference == tmp_goal_difference 
				&& team_list[i].scored_goal == tmp_scored_goal){
				cout << setw(19) << team_list[i].teamname << setw(4) << team_list[i].point;
				cout << setw(4) << team_list[i].number_of_games << setw(4) << team_list[i].scored_goal;
				cout << setw(4) << team_list[i].scored_suffer << setw(4) << team_list[i].goal_difference;
				if(team_list[i].number_of_games != 0)
					cout << setw(7) << fixed <<setprecision(2) << (double)100 *(double)team_list[i].point / (3 * team_list[i].number_of_games); 
				else cout << setw(7) << "N/A";
				cout << "\n";
			}else{
				tmp_point = team_list[i].point;
				tmp_goal_difference = team_list[i].goal_difference;
				tmp_scored_goal = team_list[i].scored_goal;
				cout << setw(2) <<now_position << ".";
				cout << setw(16) << team_list[i].teamname << setw(4) << team_list[i].point;
				cout << setw(4) << team_list[i].number_of_games << setw(4) << team_list[i].scored_goal;
				cout << setw(4) << team_list[i].scored_suffer << setw(4) << team_list[i].goal_difference;
				if(team_list[i].number_of_games != 0)
					cout << setw(7) << fixed <<setprecision(2) << (double)100 *(double)team_list[i].point / (3 * team_list[i].number_of_games); 
				else cout << setw(7) << "N/A";
				cout << "\n";
			}
			now_position++;
		}
		//clear up map and vector
		map_name_to_vector_position.clear();
		team_list.clear();
	}
}
