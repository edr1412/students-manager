#include "StudentList.h"
StudentList::StudentList()
{
	cout<<"Welcome!"<<endl;
	head = new Student;
	end = head; 
	/*read from data file*/
	ifstream infile("data.dat", ios::binary);
    if (infile){
        while(infile.peek()!=EOF){
            end->next=new Student;
            end=end->next;
            infile.read((char*)&(*end), sizeof(Student));
        }
        infile.close();
    }
    if(end==head){	//no file or empty file
        cout<<"Data not Found..."<<endl;
    }
}
/*destructor*/
StudentList::~StudentList()
{
	Save();    //save when exit normally
	Student *pos = head;
	Student *temp;
	while(pos!=NULL)
	{
		temp = pos;
		pos = pos->next;
		delete temp;
	}
}
/*save Students info to data file*/
void StudentList::Save()
{
	if(head == end) //remove the file if no students
	{
		cout<<"List is Empty,Removing..."<<endl;
        remove("data.dat");
	}
	else
	{
        ofstream outfile("data.dat", ios::binary);
        Student *pos = head->next;
		for(pos;pos!=NULL;pos=pos->next)
		{
            outfile.write((char*)&(*pos), sizeof(Student));
		}
        outfile.close();
        cout<<"Save data success!"<<endl;
	}	
}
void StudentList::Display()
{
    cout<<"==========="<<endl;
	if(head==end){
		cout<<"Empty..."<<endl;
	}

	for(Student *pos= head->next;pos!=NULL;pos=pos->next){
		pos->Disp();	//display each node
	}
	cout<<"==========="<<endl;
}
void StudentList::Add_Node()
{
	while(1)
	{
        char na[20];
        cout<<"please enter student's name(<20 words):";
        cin.getline(na,20);
	    char nu[15];
        cout<<"please enter student's num(<15 words):";
        cin.getline(nu,15);
		char se[5];
		cout<<"please enter student's sex(<5 words):";
        cin.getline(se,5);
		char co[20];
		cout<<"please enter student's college(<20 words):";
        cin.getline(co,20);
		char fa[20];
		cout<<"please enter student's faculty(<20 words):";
        cin.getline(fa,20);
		char cl[10];
		cout<<"please enter student's classes(<10 words):";
        cin.getline(cl,10);
		char dor[10];
		cout<<"please enter student's dorm(<10 words):";
        cin.getline(dor,10);
		char ori[10];
		cout<<"please enter student's origin(<10 words):";
        cin.getline(ori,10);
		char te[15];
		cout<<"please enter student's telephone number(<15 words):";
        cin.getline(te,15);


		end->next=new Student(na,nu,se,co,fa,cl,dor,ori,te,NULL);
		end = end->next;
		cout<<"Node added successfully!"<<endl;
		char quit[100];
		cout<<"continue or not?,y/N"<<endl;
		cin.getline(quit,100);
		if(strlen(quit)==1){
			switch(quit[0]){ //enter to stop,or y/Y to continue
				case'Y':
				case'y':break;
				case'n':
				case'N':
				default:return;
			}
		}
		else
			return;
	}
}
void StudentList::Refresh(){
    length=0;
    Student *pos= head;
    for(;pos->next!=NULL;pos=pos->next){
		length++;
	}
    end=pos;
}
void StudentList::Sort()
{
    Refresh();
	cout<<"sort by ...?"<<endl;
	cout<<"0\tname\n1\tnum\n2\tsex\n3\tcollege\n4\tfaculty\n5\tclass\n6\tdorm\n7\torigin\n8\ttele\n"<<endl;
	char sortby[100];
	cin.getline(sortby,100);
	if(strlen(sortby)==1 && sortby[0]>='0' && sortby[0]<='8'){
		switch(sortby[0]){
			case '0':
				/*Bubble Sorting*/
				for(int i=0;i<length-1;i++)
				{
					for(Student *q=head;q->next->next!=NULL;q=q->next)
					{
						if(strcmp(q->next->name,q->next->next->name)>0)
						{
							Student *temp;
							temp=q->next->next->next;
							q->next->next->next=q->next;
							q->next=q->next->next;
							q->next->next->next=temp;
						}
					}
				}
				break;
			case '1':
				for(int i=0;i<length-1;i++)
				{
					for(Student *q=head;q->next->next!=NULL;q=q->next)
					{
						if(strcmp(q->next->num,q->next->next->num)>0)
						{
							Student *temp;
							temp=q->next->next->next;
							q->next->next->next=q->next;
							q->next=q->next->next;
							q->next->next->next=temp;
						}
					}
				}
				break;
			case '2':
				for(int i=0;i<length-1;i++)
				{
					for(Student *q=head;q->next->next!=NULL;q=q->next)
					{
						if(strcmp(q->next->sex,q->next->next->sex)>0)
						{
							Student *temp;
							temp=q->next->next->next;
							q->next->next->next=q->next;
							q->next=q->next->next;
							q->next->next->next=temp;
						}
					}
				}
				break;
			case '3':
				for(int i=0;i<length-1;i++)
				{
					for(Student *q=head;q->next->next!=NULL;q=q->next)
					{
						if(strcmp(q->next->college,q->next->next->college)>0)
						{
							Student *temp;
							temp=q->next->next->next;
							q->next->next->next=q->next;
							q->next=q->next->next;
							q->next->next->next=temp;
						}
					}
				}
				break;
			case '4':
				for(int i=0;i<length-1;i++)
				{
					for(Student *q=head;q->next->next!=NULL;q=q->next)
					{
						if(strcmp(q->next->faculty,q->next->next->faculty)>0)
						{
							Student *temp;
							temp=q->next->next->next;
							q->next->next->next=q->next;
							q->next=q->next->next;
							q->next->next->next=temp;
						}
					}
				}
				break;
			case '5':
				for(int i=0;i<length-1;i++)
				{
					for(Student *q=head;q->next->next!=NULL;q=q->next)
					{
						if(strcmp(q->next->classes,q->next->next->classes)>0)
						{
							Student *temp;
							temp=q->next->next->next;
							q->next->next->next=q->next;
							q->next=q->next->next;
							q->next->next->next=temp;
						}
					}
				}
				break;
			case '6':
				for(int i=0;i<length-1;i++)
				{
					for(Student *q=head;q->next->next!=NULL;q=q->next)
					{
						if(strcmp(q->next->dorm,q->next->next->dorm)>0)
						{
							Student *temp;
							temp=q->next->next->next;
							q->next->next->next=q->next;
							q->next=q->next->next;
							q->next->next->next=temp;
						}
					}
				}
				break;
			case '7':
				for(int i=0;i<length-1;i++)
				{
					for(Student *q=head;q->next->next!=NULL;q=q->next)
					{
						if(strcmp(q->next->origin,q->next->next->origin)>0)
						{
							Student *temp;
							temp=q->next->next->next;
							q->next->next->next=q->next;
							q->next=q->next->next;
							q->next->next->next=temp;
						}
					}
				}
				break;
			case '8':
				for(int i=0;i<length-1;i++)
				{
					for(Student *q=head;q->next->next!=NULL;q=q->next)
					{
						if(strcmp(q->next->tele,q->next->next->tele)>0)
						{
							Student *temp;
							temp=q->next->next->next;
							q->next->next->next=q->next;
							q->next=q->next->next;
							q->next->next->next=temp;
						}
					}
				}
				break;

			default:cout<<"invalid input..."<<endl;
		}	
    	Refresh();
		cout<<"sort success!"<<endl;
	}
	else
		cout<<"invalid input..."<<endl;
}
void StudentList::Search(){
    char q[50];
    int s=0;
    Student** qresult=new Student*[0];	//store query results
    cout<<"enter something to search...(< 50 word)"<<endl;
    cin.getline(q,50);
    for(Student *p = head;p!=end;p=p->next)
	{
		/*match all possible attributes;aiming for the previous node to make deleting convenient*/
		if(strcmp(p->next->name,q)==0 || strcmp(p->next->num,q)==0 || strcmp(p->next->sex,q)==0 || strcmp(p->next->college,q)==0 || strcmp(p->next->faculty,q)==0 || strcmp(p->next->classes,q)==0 || strcmp(p->next->dorm,q)==0 || strcmp(p->next->origin,q)==0 || strcmp(p->next->tele,q)==0 ) 
		{
            Student** presult=new Student*[++s];
            for(int i=0;i<s-1;i++){
                presult[i]=qresult[i];
            }
            presult[s-1]=p;
            delete[] qresult;
            qresult=presult;
            cout<<"+---------------------------------------\n|>> "<<s-1<<"\n|";
            p->next->Disp();
        }
	}
    
    if(s==0){
        cout<<"Not Found"<<endl;
    }
    else{
		cout<<"+---------------------------------------"<<endl;
        Student* pp;
        if(s==1){
            pp=qresult[0];	//needn't choose manually
        }
        else{
            cout<<"Choose the number(enter other words to exit):";
            char chosen[100];	//manage long wrong input
			cin.getline(chosen,100);
			if(chosen[1]!='\0' || chosen[0]<'0' || chosen[0]>=s+'0'){	//avoid infinite error
				cout<<"Value not listed.exiting..."<<endl;
				delete[] qresult;
				return;
			}
            pp=qresult[chosen[0]-'0'];
        }
        cout<<"\n0\tNothing\n1\tDisplay\n2\tDelete\n3\tEdit\n";
        cout<<"What to do:";
        char method[100];
        cin.getline(method,100);

		if(method[1]!='\0'|| method[0]<'0' || method[0]>'3'){
			cout<<"invalid input..."<<endl;
		}
		else{
			switch(method[0]-'0')
			{
				case 0:break;
				case 1:pp->next->Disp();break;
				case 2:pp->Del_next();Refresh();break;
				case 3:pp->next->Edit();break;
				default:cout<<"invalid input..."<<endl;
			}
		}
    }
    delete[] qresult;
}



void StudentList::Statistic(){
	Chart c;	//create a new linked list to store data
	cout<<"0\tname\n1\tnum\n2\tsex\n3\tcollege\n4\tfaculty\n5\tclass\n6\tdorm\n7\torigin\n8\ttele"<<endl;
	cout<<"statistic by ...?\n>";
	char staby[100];
	cin.getline(staby,100);
	if(strlen(staby)==1 && staby[0]>='0' && staby[0]<='8'){
		cout<<"-*-*-*-*-*-*-*-*-"<<endl;
		switch(staby[0])
		{
			case '0':
				for(Student *p = head->next;p!=NULL;p=p->next)
					c.Add(p->name);
				break;
			case '1':
				for(Student *p = head->next;p!=NULL;p=p->next)
					c.Add(p->num);
				break;
			case '2':
				for(Student *p = head->next;p!=NULL;p=p->next)
					c.Add(p->sex);
				break;
			case '3':
				for(Student *p = head->next;p!=NULL;p=p->next)
					c.Add(p->college);
				break;
			case '4':
				for(Student *p = head->next;p!=NULL;p=p->next)
					c.Add(p->faculty);
				break;
			case '5':
				for(Student *p = head->next;p!=NULL;p=p->next)
					c.Add(p->classes);
				break;
			case '6':
				for(Student *p = head->next;p!=NULL;p=p->next)
					c.Add(p->dorm);
				break;
			case '7':
				for(Student *p = head->next;p!=NULL;p=p->next)
					c.Add(p->origin);
				break;
			case '8':
				for(Student *p = head->next;p!=NULL;p=p->next)
					c.Add(p->tele);
				break;

			default:cout<<"invalid input..."<<endl;
		}
		c.Disp();	//print the result.`c' will automatically call destructor with the end of this function.
		cout<<"-*-*-*-*-*-*-*-*-"<<endl;
	}
	else
		cout<<"invalid input..."<<endl;
}
void StudentList::Show_Menu()
{
	cout<<"0.Save and Exit"<<endl;
	cout<<"1.Print"<<endl;
	cout<<"2.New..."<<endl;
	cout<<"3.Analyse..."<<endl; 
	cout<<"4.Search (And Display,Delete,Edit...)"<<endl; 
	cout<<"5.Sort..."<<endl;

} 