#include <iostream>
#include <cstring>
using namespace std;
class Unit{
public:
	Unit(){};
	Unit(char k[20]){strcpy(key,k);}
	void Add(){value++;}
	void Disp(){cout<<key<<'\t'<<value<<endl;}
	Unit *next=NULL;
	char key[20];
private:
	int value=1;

};