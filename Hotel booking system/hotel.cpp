#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
class customer{

    protected:
        char name[30];
        char address[50];
        char phone[10];

    public:
        void addc(){
            cout<<" Name: ";
            cin>>name;
            cout<<" Address: ";
            cin>>address;
            cout<<" Phone No: ";
            cin>>phone;
        }

};

class room{

    protected:
        int room_no;

    public:

        int addr(){
            int r;
            cout<<"\n Enter Customer Detalis";
            cout<<"\n ----------------------";
            cout<<"\n\n Room no: ";
            cout<<"\n Total no. of Rooms - 50";
            cout<<"\n Ordinary Rooms from 1 - 30";
            cout<<"\n Luxuary Rooms from 31 - 45";
            cout<<"\n Royal Rooms from 46 - 50";
            cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
            cin >> r;

            return r;
        }

};

class hotel : public customer, virtual room{

    public:

    void add();	
    void display(); 		
    void rooms();			
    int check(int);			

};

void hotel::add()
{

    int flag;
    ofstream fout("Record.dat",ios::app);
    int r = addr();

    flag=check(r);

    if(flag)
    cout<<"\n Sorry..!!!Room is already booked";

    else
    {

        room_no=r;
        addc();

        fout.write((char*)this,sizeof(hotel));
        cout<<"\n Room is booked...!!!";

    }

    cout<<"\n Press any key to continue.....!!";

    fout.close();

}

void hotel::display()
{


    ifstream fin("Record.dat",ios::in);
    int r,flag;

    cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
    cin>>r;

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)
        {

            cout<<"\n Cusromer Details";
            cout<<"\n ----------------";
            cout<<"\n\n Room no: "<<room_no;
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone no: "<<phone;
            flag=1;
            break;

        }

    }

    if(flag==0)
        cout<<"\n Sorry Room no. not found or vacant....!!";
        cout<<"\n\n Press any key to continue....!!";

    fin.close();
}

void hotel::rooms()
{


    ifstream fin("Record.dat",ios::in);
    cout<<"\n\t\t\t    List Of Rooms Allotted";
    cout<<"\n\t\t\t    ----------------------";
    cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(hotel));
        cout<<"\n\n "<<room_no<<"\t\t"<<name;
        cout<<"\t\t"<<address<<"\t\t"<<phone;

    }

    cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
    fin.close();

}



int hotel::check(int r)
{

    int flag=0;

    ifstream fin("Record.dat",ios::in);

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)
        {

            flag=1;
            break;

        }

    }

    fin.close();
    return(flag);

}

class facality{

};

class payment : public hotel, virtual room, facality{

    public:
    void main_menu();
    void edit();
    void modify(int);		
    void delete_rec(int);		
    void bill(int);   
		


};

void payment::main_menu()
{

    int choice;
    while(choice!=5)
    {
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\t\t\t\t SIMPLE HOTEL MANAGEMENT ";
        cout<<"\n\t\t\t\t      * MAIN MENU *";
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\n\n\t\t\t1.Book A Room";
        cout<<"\n\t\t\t2.Customer Records";
        cout<<"\n\t\t\t3.Rooms Allotted";
        cout<<"\n\t\t\t4.Edit Record";
        cout<<"\n\t\t\t5.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>choice;

        switch(choice)
        {

            case 1:	add();
            break;

            case 2: display();
            break;

            case 3: rooms();
            break;

            case 4:	edit();
            break;

            case 5: break;

            default:
            {

                cout<<"\n\n\t\t\tWrong choice.....!!!";
                cout<<"\n\t\t\tPress any key to   continue....!!";

            }

        }

    }

}

void payment::edit()
{


    int choice,r;
    cout<<"\n EDIT MENU";
    cout<<"\n ---------";
    cout<<"\n\n 1.Modify Customer Record";
    cout<<"\n 2.Delete Customer Record";
    cout<<"\n 3. Bill Of Customer";
    cout<<"\n Enter your choice: ";

    cin>>choice;

    cout<<"\n Enter room no: " ;
    cin>>r;

    switch(choice)
    {

        case 1:	modify(r);
        break;

        case 2:	delete_rec(r);
        break;

        case 3: bill(r);
        break;

        default: cout<<"\n Wrong Choice.....!!";

    }
    cout<<"\n Press any key to continue....!!!";

}

void payment::modify(int r)
{

    long pos,flag=0;

    fstream file("Record.dat",ios::in|ios::out|ios::binary);

    while(!file.eof())
    {

        pos=file.tellg();
        file.read((char*)this,sizeof(hotel));

        if(room_no==r)
        {

            cout<<"\n Enter New Details";
            cout<<"\n -----------------";
            cout<<"\n Name: ";
            cin>>name;
            cout<<" Address: ";
            cin>>address;
            cout<<" Phone no: ";
            cin>>phone;
            file.seekg(pos);
            file.write((char*)this,sizeof(hotel));
            cout<<"\n Record is modified....!!";
            flag=1;
            break;

        }

    }

    if(flag==0)
        cout<<"\n Sorry Room no. not found or vacant...!!";
        file.close();

}




void payment::delete_rec(int r)
{

    int flag=0;
    char ch;
    ifstream fin("Record.dat",ios::in);
    ofstream fout("temp.dat",ios::out);

    while(!fin.eof())
    {

        fin.read((char*)this,sizeof(hotel));
        if(room_no==r)

        {

            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Pone No: "<<phone;
            cout<<"\n\n Do you want to delete this record(y/n): ";
            cin>>ch;

            if(ch=='n')
            fout.write((char*)this,sizeof(hotel));
            flag=1;

        }

        else
            fout.write((char*)this,sizeof(hotel));

    }

        fin.close();
        fout.close();

        if(flag==0)
        cout<<"\n Sorry room no. not found or vacant...!!";

        else
        {

        remove("Record.dat");
        rename("temp.dat","Record.dat");

        }

}



void payment::bill(int r)
{

    payment h1;
    ifstream f1;
    f1.open("Record.dat",ios::in);

    if(!f1)
        cout<<"cannot open";

    else
    {

        f1.read((char*)&h1,sizeof (hotel));
        while(f1)

        {

            f1.read((char*)&h1,sizeof(hotel));

        }

        if (h1.room_no == r)
        {

            if(h1.room_no>=1&&h1.room_no<=30)
                cout<<"your bill = 2000";

            else if (h1.room_no>=35&&h1.room_no<=45)
                cout<<"your bill = 5000" ;

            else
                cout<<"your bill = 7000";

        }

        else
        { cout<<"room no. not found";}

    }

    f1.close();
}

int main(){

    payment p1;
    p1.main_menu();
    return 0;
}