#include<iostream>
#include<math.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
std::vector<int> alternatingSums(std::vector<int> a)
{
	int team1 = 0;
	int team2 = 0;
	int stt = 1;
	for(int i = 0; i < a.size(); ++i){
		while(a[i] != 0){
			if(stt % 2 != 0){
				team1++;
				a[i]--;
			}
			if(stt % 2 == 0){
				team2++;
				a[i]--;
			}
			stt++;
		}
	}
	return {team1,team2};
}
int main() {
	vector<int> a = {3,3};
	for(int i = 0; i < alternatingSums(a).size(); ++i){
		cout<<alternatingSums(a)[i];
	}
	return 0;
}

