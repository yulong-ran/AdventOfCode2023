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

long long getNumbers(string s){
	stringstream ss(s);
	string temp;
	string res;
	
	while(getline(ss, temp, ' ')){
		if(temp.empty()) continue;

		res += temp;
	}

	return stoll(res);
}

long long getWays(long long t, long long d){
	long long res = 0;

	for(long long speed=0; speed<=t; speed++){
		long long time_left = t - speed;

		if(time_left * speed > d){
			res += 1;
		}
	}

	return res;
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ifstream file;
	string text;
	file.open("input.txt", ios::in);

	string times, distances;

	getline(file, times);
	getline(file, distances);

	times = findAndReplace(times, "Time:");
	distances = findAndReplace(distances, "Distance:");

	long long time = getNumbers(times);
	long long distance = getNumbers(distances);

	// int n = time.size(), m = distance.size();

	// if(n != m){
	// 	cout << "Not matching time and distances" << endl;
	// 	return -1;
	// }

	long long res = 1;

	// for(int i=0; i<n; i++){
	// 	long long ways = getWays(time[i], distance[i]);
	// 	cout << "Time: " << time[i] << " Distance: " << distance[i] << " " << "ways: " << ways << endl;
	// 	res *= ways;
	// }
	res = getWays(time, distance);

	cout << res << endl;
	return 0;
}
