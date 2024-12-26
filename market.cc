#include<iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;
class Market{
private:
string Name;
int Quantity, Price;
public:
void setName(string name){
Name= name;}
void setQuant(int quantity){
Quantity = quantity;}

void setPrice(int price){
Price= price;}
string getName(){
return Name;}
int getQuant(){
return Quantity;}
int getPrice(){
return Price;
}};
void addItem(Market m){
string name;
int quantity, price;
cout<<"Enter Name Of Item: ";
cin>>name;
m.setName(name);
cout<<"Enter Quantity: ";
cin>>quantity;
m.setQuant (quantity) ;
cout<<"Enter Price: ";
cin>>price;
m.setPrice(price);
ofstream out("Super Market.txt",ios::app);
if(!out){
cout<<"Fi1e Can not open!"<<endl;}
else{
out<<m.getName()<<", "<<m.getQuant()<<", "<<m.getPrice()<<endl;
cout<<"ltem Save Successfuly!"<<endl;
out.close();
}
}

void search(Market m){
string name;
cout<<"Enter Name of item: ";
cin>>name;
ifstream in("Super Market.txt");
if(!in){
cout<<"File not found!"<<endl;}
else{
string line;
bool found = false;
while(getline(in,line)){
int pos = line.find(name);
if(pos!=string::npos){
cout<<"Item I Quant I Price"<<endl;
cout<<line<<endl;
found = true;}
if(!found){
cout<<"Item not found!"<<endl;}
}
}
}
int main(){
Market m;
bool exit = false;
while( ! exit) {
system("cls");
cout<<"We1come To Super market Management system"<<endl;
cout<<"* * * * * * * * * * * * * * * * * * * * * *"<<endl;
cout<<"1.Add Items"<<endl;
cout<<"2.Search Items"<<endl;
cout<<"Enter Choice:";
int val;
cin>>val;
if(val==1){
system("cls");
addItem(m);
Sleep(5000);
}
else if (val==2){
system("cls");
search(m);
Sleep(5000);
}
else if (val==3){
    system("cls");
    exit = true;
    cout<<"Good Luck!"<<endl;
    Sleep(3000);}
}
}