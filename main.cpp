#include "StudentList.h"
#ifdef _WIN32 //In Windows
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
int main(){
	void systemPause();
    StudentList l;
    char choice[100];
	
	while(1)
	{
		l.Show_Menu();
		cout<<"please enter your choice:";
		cin.getline(choice,100); //ignore empty input
		if(choice[1]=='\0' && choice[0]>='0' && choice[0]<='5'){
			switch(choice[0])
			{
				case '0':return 0;break;
				case '1':l.Display();break;
				case '2':l.Add_Node();break;		
				case '3':l.Statistic();break;
				case '4':l.Search();break;
				case '5':l.Sort();break;
			}
			systemPause();
		}
		system(CLEAR);	
	}
	return 0;
}
void systemPause(){
	cout<<"<Enter> to continue..."<<endl;
	char c;
	cin.clear();//clear failbit
	while (( c = getchar()) != EOF && c != '\n');//Pause and clear the buffer
}