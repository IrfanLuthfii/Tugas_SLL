#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Node
{
public:
    int info;
    Node* next;
};
class List:public Node
{
 
    Node *first,*last;
public:
    List()
    {
        first=NULL;
        last=NULL;
    }
	void create();
	void insert();
	void delet();
	void display();
	void search();
};
void List::create()
{
    Node *temp;
    temp=new Node;
    int n;
    cout<<"\nMasukkan Elemen:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=first;
    }
 
    else
    {
        last->next=temp;
        last=temp;
    }
}
void List::insert()
{
    Node *prev,*cur;
    prev=NULL;
    cur=first;
    int count=1,pos,ch,n;
    Node *temp=new Node;
    cout<<"\nMasukkan elemen:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    cout<<" =     Masukkan sebagai    =";
    cout<<"----------------------------";
	cout<<" = 1:Urutan Pertama        =";
	cout<<" = 2:Urutan Terakhir       =";
	cout<<" = 3:Antara Awal dan Akhir =";
	cout<<"----------------------------";
    cout<<" =  Masukkan pilihan anda: =";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=first;
        first=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"\nMasukkan posisi yang ingin dimasukkan:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\nData tidak dapat diinput";
        break;
 
    }
}
void List::delet()
{
    Node *prev=NULL,*cur=first;
    int count=1,pos,ch;
    cout<<" =            Hapus     		= ";
    cout<<"-------------------------------";
	cout<<" = 1:Urutan Pertama     		= ";
	cout<<" = 2:Urutan Terakhir 		= ";
	cout<<" = 3:Antara Awal dan Akhir 	= ";
	cout<<"-------------------------------";
    cout<<" =   Masukkan pilihan anda: 	= ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(first!=NULL)
        {
            cout<<"\nElemen yang dihapus adalah "<<first->info;
            first=first->next;
        }
        else
            cout<<"\nTidak dapat dihapus";
        break;
    case 2:
        while(cur!=last)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==last)
        {
            cout<<"\nElemen yang dihapus adalah: "<<cur->info;
            prev->next=NULL;
            last=prev;
        }
        else
            cout<<"\nTidak dapat dihapus";
        break;
    case 3:
        cout<<"\nMasukkan posisi yang ingin dihapus:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            cout<<"\nElemen yang dihapus adalah: "<<cur->info;
            prev->next=cur->next;
        }
        else
            cout<<"\nTidak dapat dihapus";
        break;
    }
}
void List::display()
{
    Node *temp=first;
    if(temp==NULL)
    {
        cout<<"\nList kosong";
    }
    while(temp!=NULL)
    {
        cout<<temp->info;
        cout<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void List::search()
{
    int value,pos=0;
    bool flag=false;
    if(first==NULL)
    {
        cout<<"List kosong";
        return;
    }
    cout<<"Masukkan nilai yang ingin dicari:";
    cin>>value;
    Node *temp;
    temp=first;
    while(temp!=NULL)
    {
        pos++;
        if(temp->info==value)
        {
            flag=true;
            cout<<"Element"<<value<<"terletak diposisi ke "<<pos;
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Elemen "<<value<<" tidak ditemukan di list";
    }
}
int main()
{
    List l;
    int ch;
    while(1)
    {
    	cout<<"Nama : Irfan Luthfi"<<endl;
        cout<<"NPM  : G1A021090"<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM LINKED LIST    ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. CREATE                	="<<endl;
        cout<<" = 2. INSERT          		="<<endl;
        cout<<" = 3. DELETE          		="<<endl;
        cout<<" = 4. SEARCH                 ="<<endl;
        cout<<" = 5. DISPLAY  				="<<endl;
		cout<<" = 6. EXIT              		="<<endl;
        cout<<" ============================="<<endl;
        cout<<" Masukan Pilihan : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.insert();
            break;
        case 3:
            l.delet();
            break;
        case 4:
            l.search();
            break;
        case 5:
            l.display();
            break;
        case 6:
            return 0;
        }
    }
    return 0;
}
