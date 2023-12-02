#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
#include <bitset>
#include <sstream>

using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

void solve(){
}

vector<string> split(string& s, char d){
	vector<string> res;
	
	stringstream ss(s);
	string temp;

	while(getline(ss, temp, d)) res.push_back(temp);

	return res;
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ifstream file;
	string text;
	file.open("input.txt", ios::in);

	long long res = 0;
	
	int RED = 12, GREEN = 13, BLUE = 14;
	vector<int> limit{RED, GREEN, BLUE};
	unordered_map<string, int> colors;
	colors["red"] = 0;
	colors["green"] = 1;
	colors["blue"] = 2;

	auto isValidGame = [&](string& s) -> int{
		s.erase(remove(s.begin(), s.end(), ','), s.end());

		stringstream ss(s);
		string set;
		vector<int> ans(3,0);

		while(getline(ss, set, ';')){
			set = trim(set);
			vector<string> A = split(set, ' ');

			vector<int> B(3);
			for(int i=0; i<A.size(); i+=2){
				int count = stoi(A[i]), color = colors[A[i + 1]];
				B[color] += count;
			}

			for(int i=0; i<3; i++){
				ans[i] = max(ans[i], B[i]);
			}
		}

		long long res = 1;

		for(auto& r: ans) res *= r;
			
		return res;

	};

	
	while(getline(file, text)){
		int game_index = text.find(":");
		string game = text.substr(0, game_index).substr(5);
		string sets = text.substr(game_index + 2);
		int game_id = stoi(game);

		res += isValidGame(sets);
	}

	cout << res << "\n";

	return 0;
}
