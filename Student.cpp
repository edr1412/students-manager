#include "Student.h"
void Student::Disp(){
    cout<<"name:"<<name<<'\t';
	cout<<"num:"<<num<<'\t';
	cout<<"sex:"<<sex<<'\t';
	cout<<"college:"<<college<<'\t';
	cout<<"faculty:"<<faculty<<'\t';
	cout<<"class:"<<classes<<'\t';
	cout<<"dorm:"<<dorm<<'\t';
	cout<<"origin:"<<origin<<'\t';
	cout<<"Tel:"<<tele<<'\t';
	cout<<endl;
}
void Student::Del_next(){
    Student* p=next;
    next=next->next;
    delete p;
    cout<<"Deleted Successly"<<endl;
}
void Student::Edit(){
    cout<<"\n0\t\t1\t\t\t2\t3\t\t4\t\t5\t\t6\t\t7\t\t8"<<endl; //trim in most conditions
    Disp();
    cout<<"Which To Change:";
    char attr[100];
    cin.getline(attr,100);
    if(attr[1]!='\0'|| attr[0]<'0' || attr[0]>'8'){
			cout<<"invalid input..."<<endl;
	}
    else{
        cout<<"enter the new value:";
        switch(attr[0]-'0')
        {
            case 0:cin.getline(name,20);;break;
            case 1:cin.getline(num,15);break;
            case 2:cin.getline(sex,5);break;
            case 3:cin.getline(college,20);break;
            case 4:cin.getline(faculty,20);break;
            case 5:cin.getline(classes,10);break;
            case 6:cin.getline(dorm,10);break;
            case 7:cin.getline(origin,10);break;
            case 8:cin.getline(tele,15);break;
            default:cout<<"invalid input..."<<endl;
        }
    }
}