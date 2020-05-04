/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
Piotr's Ants UVA - 10881

https://vjudge.net/problem/UVA-10881
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return true;
}();

struct Ant {
	int id; // input id
	int p;  // postion
	char s; // stat LRTF
	bool operator < (const Ant& o) const {
		return p < o.p;
	}
};

int N,L,T,n,a,c=1;
vector<Ant> START, END;
vector<int> order;

void input() {
	cin>>L>>T>>n;
	START.reserve(n);
	END.reserve(n);
	order.reserve(n+1);
	int p,d;
	char s;
	for(a=0; a<n; ++a) {
		cin>>p>>s;
		START[a].id = a;
		START[a].p = p;
		START[a].s = s;
		d = s == 'L' ? -1 : 1;
		END[a].id = 0;
		END[a].p = p + T*d;
		END[a].s = s;
	}
}

void solve() {
	sort(begin(START), begin(START) + n);
	for(a=0; a<n; ++a) {
		order[START[a].id] = a;
	}

	sort(begin(END), begin(END) + n);
	for(a=0; a<n-1; ++a) {
		if(END[a].p == END[a+1].p)
			END[a].s = END[a+1].s = 'T';
	}
}

void output() {
	cout<<"Case #"<<c++<<":\n";
	int i;
	for(a=0; a<n; ++a) {
		i = order[a];
		if(END[i].p < 0 || END[i].p > L) cout<<"Fell off\n";
		else if(END[i].s == 'T')
			cout<<END[i].p<<" Turning\n";
		else
			cout<<END[i].p<<" "<<END[i].s<<'\n';
	}
	cout<<'\n';
}

int main(int argc, char* argv[]) {
	cin>>N;
	while(c < N+1) {
		input();
		solve();
		output();
	}
	return 0;
}
