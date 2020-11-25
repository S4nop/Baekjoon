#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int num[1010];

struct vec{
	int val[1010];
	int top;
	vec(){ top = -1; }
	void push_back(int data) { val[++top] = data; }
	void pushidx(int data, int idx) { val[idx] = data; }
	int at(int idx) { return val[idx]; }
	int getTop() { return val[top]; }
	int getTopidx() { return top; }
};

int main(){
	ios_base::sync_with_stdio(0);
	int n, i, j, tmpNow, rslt = 0;
	vec myVec;
	
	
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> num[i];

	myVec.push_back(num[0]);
	for (i = 1; i < n; i++){
		if (myVec.getTop() < num[i]) myVec.push_back(num[i]);
		else{
			for (j = 0; j <= myVec.getTopidx(); j++)
				if (myVec.at(j) > num[i]){
					myVec.pushidx(num[i], j);
					break;
				}
		}
	}

	cout << myVec.getTopidx() + 1;

	return 0;
}