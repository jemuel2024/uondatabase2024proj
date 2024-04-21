# include <iostream>
# include <string>
# include <cctype>
#include <limits>
#include <iomanip>
using namespace std;
string stackname;
#ifndef STACK_H
#define STACK_H
#include<iostream>
# include <string>
using namespace std;
class Node
{
public:
 int key;
 string name;
 char gender;
 int phoneno;
 Node* next;
 int pos,pure1,pure2,comp,ds,applied1,applied2,phyc1,phyc2,ect1,wkshop1,wkshop2;
    double total,aggpoints;
 Node()
{
 key=0;
 phoneno=0;
 next = NULL;
}
 Node
(int k, string d)
{
 key=k;
name=d;
gender= '*';
phoneno=0700000000;
}
Node(int k,string n,char g,int p){
key=k;
name=n;
gender=g;
phoneno=p;
}
};
class Stack
{
public:
 Node* top;
 Node* bottom;
 string course;
 Node* nodeexist;
 Stack()
{
 top= NULL;
 bottom= NULL;
 course="ELECRICAL AND ELECRONIC ENGINEERING 2023";
}
 bool isEmpty()
{
 if(top == NULL)
 {
 return true;
 } 
 else
  {
  return false;
  }

}
 bool checkIfNodeExist(Node* n)
{
 Node* temp = top;
 int T,B,mid;
 T=top->key;
 B=bottom->key;
 bool exist = false;
 while(T<= B)
{
  mid=T + (B-T)/2;
  if(T==n->key){
    exist= true;
    break;
  }
  if(mid<n->key){
    T=mid + 1;
  }
  if(mid> n->key){
      B=mid-1;
  }

}
 return exist;
 }
 
 
 void sortpush(Node * n){
  if((n-> key)< (top-> key)){
    n->next=top;
    top=n;
  }else{
    Node* temp=top;
    Node* great=top;
    while(temp!=NULL){
        if(temp->key >n->key){
          great=temp;
          break;
        }if(temp->next==NULL){
          break;

        }
        temp=temp->next;
    }if (temp->next==NULL){
      temp->next=n;
      bottom=n;
      n-> next = NULL;
    }else{
    temp = top;
    while(temp!=NULL){
      if(temp->next==great){
        temp->next=n;
        n->next=great;
        break;
      }
      temp=temp->next;
    }
  }
 }
 }
 void push(Node * n) {
 if (top == NULL) {
 top = n;bottom=n;
 cout << "Student details added  successfully" << endl;
 } else if (checkIfNodeExist(n)) {
 cout << "Reg no. already exist " <<
 "Enter different Reg no." << endl;//cout the reg no with the details;
 } else {
 /*Node * temp = top;
 top = n;
 n -> next = temp;*/
 sortpush(n);
 cout << "Student details added  successfully" << endl;
 }
 }
 Node * pop() {
 Node * temp = NULL;
 if (isEmpty()) {
 cout << "stack underflow" << endl;
 return temp;
 } else {
 temp = top;
 top = top -> next;
 return temp;
 } 
 }
 Node * pop(int k) {
 Node * temp = NULL;
 Node * tempreturn= NULL;
 Node* tempnode=new Node;
 tempnode->key=k;
 if (isEmpty()) {
 cout << "stack underflow" << endl;
 delete tempnode;
 return temp;
 }/*else if(!checkIfNodeExist(tempnode)){
  delete tempnode;
  cout<<"No match found"<<endl;
  return temp;
 }*/
  else if(checkIfNodeExist(tempnode)){
  temp= top;
  if(nodeexist==top){
//tempreturn=top;

top=top->next;
return nodeexist;
  }else{
while(temp!=NULL){
  if(temp->next==nodeexist){
    temp->next=(temp->next)->next;
    break;
  }
  temp=temp->next;
}
}
}
else{
 // delete tempnode;
  cout<<"No match found"<<endl;
}
 
// else{
  //cout<<"Node doesn't exist"<<endl;
//}
 delete tempnode;
 return nodeexist;
 }
 Node * peek() {
 //Node *temp = NULL;
 if (isEmpty()) {
 cout << "stack underflow" << endl;
 return NULL;
 } else {
 return top;
 }
 }
 int count() {
 int count = 0;
 Node * temp = top;
 while (temp != NULL) {
 count++;
 temp = temp -> next;
 }
 return count;
 }
 void display() {

 cout << "All values in the Stack are :" << endl;
 Node * temp = top;
 while (temp != NULL) {
 cout << "(" << temp -> key << "," << temp -> phoneno << ")" << "-> " <<endl;
 temp = temp -> next;
 }

 cout << endl;
 }
 void display2(){
  /*cout<<fixed<<setw(60)<<left<<setfill('_')<<endl;
  cout<<endl;
  cout<<endl<<"|"*/cout<<fixed<<setw(50)<<left<<course<<endl;
 // cout<<fixed<<setw(60)<<left<<setfill('_')<<endl;
  Node* temp=top;
  cout<<fixed<<setw(8)<<left<<"Reg No."<<fixed<<setw(25)<<left<<"Name";
  cout<<fixed<<setw(8)<<left<<"Gender"<<fixed<<setw(15)<<left<<"Contact"<<endl;
  //cout<<fixed<<setw(60)<<left<<setfill('_')<<endl;
  while(temp!=NULL){
     cout<<fixed<<setw(8)<<left<<temp->key<<fixed<<setw(25)<<left<<temp->name;
  cout<<fixed<<setw(8)<<left<<temp->gender<<fixed<<setw(15)<<left<<temp->phoneno<<endl;
    //cout<<fixed<<setw(60)<<left<<setfill('_')<<endl;
    temp=temp->next;
  }
 }
 void assesment(){
Node* temp=top;
while(temp!=NULL){
  display2();
  cout<<"You are currently inputing assesment marks for:"<<temp->key<<" "<<temp->name<<endl;
  cout<<endl;
  cout<<"INSERT THE RESULTS IN THE GIVEN ORDER"<<endl;
  cout<<" pure1 pure2 comp DS$algorithm applied1 applied2 "<<endl;
  cin>>temp->pure1>>temp->pure2>>temp->comp>>temp->ds>>temp->applied1>>temp->applied2;
  cout<<"PHY1 PHY2 wkshop1 wkshop2 ECT"<<endl;
  cin>>temp->phyc1>>temp->phyc2>>temp->wkshop1>>temp->wkshop2>>temp->ect1;
  temp->total=((temp->pure1)+(temp->pure2)+(temp->comp)+(temp->ds)+temp->applied1+temp->applied2+temp->phyc1+temp->phyc2+temp->wkshop1+temp->wkshop2+temp->ect1);
    temp->aggpoints=(temp->total/11);

    cout<<temp->name<<"'s total marks is: "<<temp->total<<"and Agg.:"<<temp->aggpoints<<endl;
  temp=temp->next;
  cout<<endl;
}
cout<<"the updated assesment list is \n";
assesDisplay();
 }
 void assesDisplay(){
  cout<<fixed<<setw(50)<<left<<course<<endl;
  Node* temp=top;
  cout<<fixed<<setw(8)<<left<<"Reg No."<<fixed<<setw(25)<<left<<"Name";
  cout<<fixed<<setw(8)<<left<<"Gender"<<fixed<<setw(15)<<left<<"Contact";
  cout<<fixed<<setw(8)<<left<<"Pure1"<<fixed<<setw(8)<<left<<"Pure2"<<fixed<<setw(8)<<left<<"COMP"<<fixed<<setw(8)<<left<<"DS&ALG";
  cout<<fixed<<setw(9)<<left<<"Applied1"<<fixed<<setw(9)<<left<<"Applied2"<<fixed<<setw(8)<<left<<"Phyc1"<<fixed<<setw(8)<<left<<"Phyc2";
  cout<<fixed<<setw(9)<<left<<"Workshop1"<<fixed<<setw(9)<<left<<"Workshop2"<<fixed<<left<<setw(8)<<"ECT";
  cout<<fixed<<setw(8)<<left<<"Total"<<fixed<<setw(8)<<left<<"Agg"<<endl;
  while(temp!=NULL){
     cout<<fixed<<setw(8)<<left<<temp->key<<fixed<<setw(25)<<left<<temp->name;
  cout<<fixed<<setw(8)<<left<<temp->gender<<fixed<<setw(15)<<left<<temp->phoneno;
  //edit this
  cout<<fixed<<setw(8)<<left<<temp->pure1<<fixed<<setw(8)<<left<<temp->pure2<<fixed<<setw(8)<<left<<temp->comp<<fixed<<setw(8)<<left<<temp->ds;
  cout<<fixed<<setw(9)<<left<<temp->applied1<<fixed<<setw(9)<<left<<temp->applied2<<fixed<<setw(8)<<left<<temp->phyc1<<fixed<<setw(8)<<left<<temp->phyc2;
  cout<<fixed<<setw(9)<<left<<temp->wkshop1<<fixed<<setw(9)<<left<<temp->wkshop2<<fixed<<left<<setw(8)<<temp->ect1;
  cout<<fixed<<setw(8)<<setprecision(2)<<left<<temp->total<<fixed<<setw(8)<<left<<setprecision(2)<<temp->aggpoints<<endl;
    temp=temp->next;
  }
 }

};
#endif
void createlist();
/*class Assesstack:class Stack{
    public:
    int pure1,pure2,comp,ds,applied1,applied2,phyc1,phyc2,ect1,wkshop1,wkshop2;
    double total,aggpoints;
    AssesStack(){
        Stack();
    }
};*/
int main(){
    Stack s1;
 int option,key,phone;string name;char gender;
 do{
    cout<<"\nselect the operation you want to perform"<<endl;
cout<<"1.create a list"<<'\n'<<"2.Add members"<<'\n'<<"3.Remove a member "<<'\n'<<"4.Print list\n5.Assesment Update and display \n enter 0 to exit"<<endl;
while(!(cin>>option)){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout<<"please input a no. corresponding to your selection \n";
 // cin>>option;
}

Node* new_node=new Node;
switch(option){
    case 0: break;
    case 1:createlist();
           break;
    case 2:
    //Reg No handler
       cout<<"Enter the registration no. i.e 2257"<<endl;
        while(!(cin>>key)){
       cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"!!!please put the reg no without the course code \n";     
        
        }
       //Name handler
        cout<<"Name i.e Odayo Jemuel \n";
          cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');                                                                                                                                  
        getline(cin,name);
        //Gender handler
       /*because the cin.ignore() function clears the input buffer up to the newline character ('\n'), 
       any additional characters entered after "dfg" (e.g., pressing Enter) will also be ignored.*/
        do{
        cout<<"gender i.e M/F \n" ;
        string input;
        cin>>input;
        if(input.size()==1&&(input[0]=='m'||input[0]=='M'||input[0]=='f'||input[0]=='F')){
          gender=input[0];
          break;
        }else cout<<"Insert a single letter either m/f"<<endl;
         
        }while(true);
        if(islower(gender)){
            gender=toupper(gender);
        }
       cout<<"Enter phone no.ie 07xxxxxxx \n if it is foreign ignore  the '+' \n  ";
       while(!(cin>>phone)||((to_string(phone).size())<9))//an unpredictable issue occurs here
       {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"length too short or invalid phone no."<<endl;
       }
       new_node->key=key;
       new_node->name=name;
       new_node->gender=gender;
       new_node->phoneno=phone;
       s1.push(new_node);
       cout<<"this is the updated list\n"<<endl;
       s1.display2();
       break;
    case 3:
        //delete new_node;
        cout<<"Enter the Reg no. of the student to remve from list"<<endl;
        cin>>key;
        new_node=s1.pop(key);
        cout<<"student with details: \n"<<new_node->key<<"  "<<new_node->name<<"\n removed successfully\n";
        delete new_node;
        cout<<endl;
        break;   
     case 4:s1.display2();
        break;
      case 5:
      if(s1.isEmpty()){
        cout<<"please add students to the list 1st"<<endl;
      } else{
           s1.assesment();}
        break;  
    default:
          cout<<"please enter a valid option"<<endl;     

} 
}while(option!=0);
}
void createlist(){
/*cout<<"what is the name of your list"<<endl;
cin>>stackname;
stack s1;
s1.course=stackname;*/
cout<<"service still not available"<<endl;
}
