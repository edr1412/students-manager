#include <iostream>
#include <cstring>
using namespace std;
class Student
{
public:
	char name[20]="000";
	char num[15]="000";
	char sex[5]="000";
	char college[20]="000";
	char faculty[20]="000";
	char classes[10]="000";
	char dorm[10]="000";
	char origin[10]="000";
	char tele[15]="000";
	Student *next=NULL;
    Student(){} //default constructor
	Student(char na[20],char nu[15],char se[5],char co[20],char fa[20],char cl[10],char dor[10],char ori[10],char te[15],Student* p):next(p){
		strcpy(name,na);
		strcpy(num,nu);
		strcpy(sex,se);
		strcpy(college,co);
		strcpy(faculty,fa);
		strcpy(classes,cl);
		strcpy(dorm,dor);
		strcpy(origin,ori);
		strcpy(tele,te);
	}
    void Disp(); //show its infomation
    void Del_next(); //delete next node
    void Edit(); //edit interactively
};
