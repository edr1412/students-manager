#include <fstream>
#include <iostream>
#include <cstring>
#include "Student.h"
#include "Chart.h"
class StudentList
{
public:
	StudentList();	
	~StudentList();
	/*Functions*/
	void Show_Menu();
	void Add_Node();
	void Display();
	void Search();  //Searching and edit,display or delete
	void Save();    //automatically called by destructor
	void Sort();    //interactively sort by any variable
    void Refresh(); //check `length' and `end' 
	void Statistic();   //show the number of each class,college,dorm,etc.
	
private: 
	/*StudentList is a linked list made up of Students */ 
	Student *head;  //head of the linked list
	Student *end;	//tail of the linked list
	int length=0;   //used for sorting
};

