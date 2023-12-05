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

void solve(){
}

string findAndReplace(string s, string t){
	s.replace(s.find(t), t.length(), "");

	return s;
}

vector<long long> getNumbers(string s){
	stringstream ss(s);
	string temp;
	vector<long long> res;
	
	while(getline(ss, temp, ' ')){
		res.push_back(stoll(temp));
	}

	return res;
}

long long getMapped(vector<vector<long long>>& map, long long seed){
	long long res = LLONG_MAX;

	for(auto& m: map){
		long long dest = m[0], source = m[1], range = m[2];
		long long source_upper = source + range;

		if(seed >= source && seed <= source_upper){
			long long delta = seed - source;
			long long dest_mapped = dest + delta;
			res = min(res, dest_mapped);
		}
	}

	return res == LLONG_MAX ? seed : res;
}	

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ifstream file;
	string text;
	file.open("input.txt", ios::in);
	string seeds;

	getline(file, seeds);
	seeds = findAndReplace(seeds, "seeds: ");

	vector<vector<vector<long long>>> maps;
	vector<vector<long long>> map;

	while(getline(file, text)){
		if(text.length() == 0){
			continue;
		}

		bool isNewMap = text.find("map") != string::npos;
		
		if(isNewMap){
			if(map.size()) maps.push_back(map);
			map = vector<vector<long long>>();
			continue;
		}
		
		vector<long long> numbers = getNumbers(text);
		map.push_back(numbers);
	}

	if(map.size()) maps.push_back(map);

	long long res = LLONG_MAX;

	for(auto seed: getNumbers(seeds)){
		long long ans = seed;

		for(auto& map: maps){
			ans = getMapped(map, ans);
		}

		res = min(res, ans);
	}

	cout << "Answer: " << res << endl;

	return 0;
}
