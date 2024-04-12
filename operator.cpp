# include <iostream>
# include <string>
# include <cctype>
#include <limits>
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
 string course;
 Stack()
{
 top= NULL;
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
 bool exist = false;
 while(temp != NULL)
{
 if(temp -> key == n -> key){
 exist = true;
 break;

}
 temp = temp -> next;

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
 top = n;
 //cout << "Node PUSHED successfully" << endl;
 } else if (checkIfNodeExist(n)) {
 cout << "Node already exist with this Key value." <<
 "Enter different Key value" << endl;
 } else {
 /*Node * temp = top;
 top = n;
 n -> next = temp;*/
 sortpush(n);
 //cout << "Node PUSHED successfully" << endl;
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
};
#endif
void createlist();
int main(){
    Stack s1;
 int option,key,phone;string name;char gender;
 do{
    cout<<"select the operation you want to perform"<<endl;
cout<<"1.create a list"<<'\n'<<"2.Add members"<<'\n'<<"3.Remove a member "<<'\n'<<"4.Print list \n enter 0 to exit"<<endl;
cin>>option;
Node* new_node=new Node;
switch(option){
    case 0: break;
    case 1:createlist();
           break;
    case 2:
        cout<<"Enter the registration no. i.e 2257"<<endl;
        cin>>key;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Name i.e Odayo Jemuel \n";
        getline(cin,name);
        cout<<"gender i.e M/F \n" ;cin>>gender;
        if(islower(gender)){
            gender=toupper(gender);
        }
       cout<<"Enter phone no.ie 07xxxxxxx \n";cin>>phone;
       new_node->key=key;
       new_node->name=name;
       new_node->gender=gender;
       new_node->phoneno=phone;
       s1.push(new_node);
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