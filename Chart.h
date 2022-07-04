#include "Unit.h"
class Chart{
public:
	Chart(){head=new Unit;end=head;}
	~Chart(){
		Unit *pos = head;
		Unit *temp;
		while(pos!=NULL)
		{
			temp = pos;
			pos = pos->next;
			//cout<<"deleted!"<<endl;
			delete temp;
		}
	}
	void App(char k[20]){end->next=new Unit(k);end=end->next;}
	void Add(char k[20]){
		int f=0;
		for(Unit *p= head->next;p!=NULL;p=p->next){
			if(strcmp(p->key,k)==0){
				p->Add();
				f=1;
			}
		}
		if(f==0)
			App(k);
	}
	void Disp(){
		for(Unit *p= head->next;p!=NULL;p=p->next)
			p->Disp();
	}

private:
	Unit *head;
	Unit *end;
};