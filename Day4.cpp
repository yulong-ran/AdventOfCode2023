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
	int res = 0, score = 1;
	
	unordered_map<int, int> mp;
	for(auto& b: B) mp[b] += 1;

	for(auto& a: A){
		if(mp.find(a) == mp.end()) continue;

		for(int i=0; i<mp[a]; i++){
			score <<= 1;
		}
	}

	return score / 2;
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

	while(getline(file, text)){
		int i = text.find(":");
		string lists = text.substr(i + 1);
		int j = lists.find("|");
		string l1 = lists.substr(0, j);
		string l2 = lists.substr(j + 1);
		vector<int> first = getList(l1);
		vector<int> second = getList(l2);
		
		long long ans =  solve(first, second);
		print(first);
		print(second);
		cout << ans << endl;
		res += ans;

	}
	
	cout << res << endl;

	return 0;
}
