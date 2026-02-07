#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct task{
    string description;
    string status; 
    task* link;
};
class ToDoList{
public:
    task*start,*curr,*temp;
    ToDoList(){
        start=NULL;
    }
    void addTask(){
        if(start==NULL) {
            start=new task;
            cout<< "Enter task:";
            cin>>start->description;
            start->status="Pending"; 
            start->link=NULL;
        }
		else{
            curr=start;
            while(curr->link!=NULL)
            curr=curr->link;
            temp=new task;
            cout<<"Enter task:";
            cin>>temp->description;
            temp->status="Pending";
            temp->link=NULL;
            curr->link=temp;
        }
    }
    void display(){
        if(start==NULL){
        cout<<"List is empty"<<endl;
        }
        curr=start;
        while(curr!=NULL){
        cout<<"Task:"<<curr->description<<endl;
		cout<<"Status:"<<curr->status<<endl;
        curr=curr->link;
        }
    }
    void deleteTask(int n){
        if (start==NULL)
        curr=start;
        if(n==1){
        start=start->link;
        delete curr;
        }
        for(int i=1;i<n- 1&&curr!=NULL;i++){
        curr=curr->link;
        }
        if(curr!=NULL&&curr->link!=NULL){
        temp = curr->link;
        curr->link = temp->link;
        delete temp;
        }
    }
    void update(int n){
    curr=start;
    for(int i=1;i<n&&curr!=NULL;i++){
    curr=curr->link;
    }
    if(curr!=NULL){
    cout<<"Enter new description:";
    cin>>curr->description;
        }
    }
    void markCompleted(int n){
    curr=start;
    for(int i=1;i<n&&curr!=NULL;i++){
    curr=curr->link;
        }
        if(curr!=NULL){
            curr->status="Completed";
        }
    }
    void search(string s){
        curr=start;
        while(curr!=NULL){
            if(curr->description==s){
                cout<<"Found:"<<curr->description<<"["<<curr->status<<"]"<<endl;
            }
            curr=curr->link;
        }
        cout<<"Not found"<<endl;
    }
};
int main(int argc, char** argv){
    ToDoList t;
    int choice,pos;
    string s;
    while(true){
        cout<<"\n 1.Add \n 2.Display\n 3.Delete\n 4.Update\n 5.Search\n 6.Complete\n 7.Exit\nChoice: ";
        cin>>choice;
        switch(choice){
            case 1:
                t.addTask();
                break;
            case 2:
                t.display();
                break;
            case 3:
                cout<<"Position:";
				cin>>pos;
                t.deleteTask(pos);
                break;
            case 4:
                cout<<"Position:"; 
				cin>>pos;
                t.update(pos);
                break;
            case 5:
                cout<<"Name:";
				cin>>s;
                t.search(s);
                break;
            case 6:
                cout<<"Position:";
				cin>>pos;
                t.markCompleted(pos);
                break;
            case 7:
                exit(0);
            default:
                cout<<"Invalid Choice";
        }
    }
    return 0;
}