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

int solve(vector<int>& A, vector<int>& B){
	int res = 0, score = 0;
	
	unordered_map<int, int> mp;
	for(auto& b: B) mp[b] += 1;

	for(auto& a: A){
		if(mp.find(a) == mp.end()) continue;

		for(int i=0; i<mp[a]; i++){
			score += 1;
		}
	}

	return score;
}

vector<int> getList(string& s){
	stringstream ss(s);
	string number;
	
	vector<int> res;

	while(getline(ss, number, ' ')){
			if(number.empty()) continue;
			res.push_back(stoi(number));
	}

	return res;
}

void print(vector<int>& arr){
	for(auto& a: arr) cout << a << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ifstream file;
	string text;
	file.open("input.txt", ios::in);

	long long res = 0;

	vector<int> game = {0};

	while(getline(file, text)){
		int i = text.find(":");
		string lists = text.substr(i + 1);
		int j = lists.find("|");
		string l1 = lists.substr(0, j);
		string l2 = lists.substr(j + 1);
		vector<int> first = getList(l1);
		vector<int> second = getList(l2);
		game.push_back(solve(first, second));
	}
	
	int n = game.size();
	vector<int> count(game.size(), 1);

	for(int i=1; i<game.size(); i++){
		int c = game[i];
		if(c == 0) continue;

		int cur_count = count[i];

		cout << "Game " << i  << " instances: " << cur_count << endl;

		for(int j=i+1; j<=i+c && j < n; j++){
			count[j] += cur_count;
		}
	}

	res = accumulate(count.begin() + 1, count.end(), 0LL);
	
	cout << res << endl;

	return 0;
}
