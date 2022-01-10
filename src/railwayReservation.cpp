#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
using namespace std;
string f="f";
string s="s";
int addr, ad, flag, f1, d, m, i, amt;
float tamt;
class login
{
	public:
	string id;
	string pass;

	friend fstream& operator<<(fstream& os, login &log);
    friend fstream& operator>>(fstream& is, login &log);

	void getid()
	{
		cout << "\nEnter your id:";
		cin >> id;
		cout << "Enter the Password: ";
		cin >> pass;
		cout << "\n";
	}
	void displayid()
	{
	    cout << "\n|" << "User ID:" << "\t" << "|" << "Password\n";
		cout << "|" << id << "\t\t" << "|" << pass << "\n\n";
	}
};

fstream& operator<<(fstream& os, login &log)
{
	size_t size=log.id.size();
	os<<size;
	os.write(log.id.data(),size);

	size=log.pass.size();
	os<<size;
	os.write(log.pass.data(),size);

	//os.write("\n",1);

	return os;
}

fstream& operator>>(fstream& is, login &log)
{
	size_t size=0;
	is>>size;
	log.id.resize(size);
	is.read(&log.id[0],size);

	size=0;
	is>>size;
	log.pass.resize(size);
	is.read(&log.pass[0],size);

	return is;
}


class Detail
{
	public:
		int tno;
		string tname;
		string bp;
		string dest;

		int c1;
		int c1fare;
		int c2;
		int c2fare;
		int d;
		int m;
		int y;

		friend fstream& operator<<(fstream& os, Detail &Det);
        friend fstream& operator>>(fstream& is, Detail &Det);

		void getDetail()
		{
			cout << "\n--Add New details--\n";
			cout << "Train no: ";
			cin >> tno;
			cout << "Train Name: ";
			cin >> tname;
			cout << "Boarding point: ";
			cin >> bp;
			cout << "Destination pt: ";
			cin >> dest;
			cout << "No of seats in first class & fare per ticket: ";
			cin >> c1 >> c1fare;
			cout << "No of seats in second class & fare per ticket: ";
			cin >> c2 >> c2fare;
			cout << "Date of travel\n";
			cout << "Day: ";
			cin >> d;
			cout << "Month: ";
			cin >> m;
			cout << "Year: ";
			cin >> y;
		}
		void displaydetail()
		{
		    cout << "\n|Train No." << "\t" << "|Train Name" << "\t" << "|Boarding pt." << "\t" << "|Destination pt."  <<"\t";
			cout << "|F-Class" << "\t"<< "|F-Class Fare" << "\t" << "|S-Class" << "\t" << "|S-Class Fare" <<"\t";
			cout << "|Day" << "-" << "Month" << "-" << "Year" << "\n";

			cout << "|" << tno << "\t\t" << "|" << tname << "\t" << "|" << bp << "\t\t" << "|" << dest <<"\t\t\t";
			cout << "|" << c1 << "\t\t" << "|"<< c1fare << "\t\t" << "|" << c2<< "\t\t" << "|" << c2fare <<"\t\t";
			cout << "|" << d << "-" << m << "-" << y << "\n";
		}
};

fstream& operator<<(fstream& os, Detail &Det)
{
	os<<Det.tno;
	os.write(" ",1);

	size_t size;
	size=Det.tname.size();
	os<<size;
	os.write(Det.tname.data(),size);

	
	size=Det.bp.size();
	os<<size;
	os.write(Det.bp.data(),size);

	
	size=Det.dest.size();
	os<<size;
	os.write(Det.dest.data(),size);
	
	os.write(" ",1);
	
	os<<Det.c1;
	os.write(" ",1);
	
	os<<Det.c1fare;
	os.write(" ",1);
	os<<Det.c2;
	os.write(" ",1);

	os<<Det.c2fare;
	os.write(" ",1);

	os<<Det.d;
	os.write(" ",1);

	os<<Det.m;
	os.write(" ",1);

	os<<Det.y;

	//os.write("\n",1);

	return os;

}

fstream& operator>>(fstream& is, Detail &Det)
{
	size_t size;
	
	is>>Det.tno;

	size=0;
	is>>size;
	Det.tname.resize(size);
	is.read(&Det.tname[0],size);

	size=0;
	is>>size;
	Det.bp.resize(size);
	is.read(&Det.bp[0],size);

	size=0;
	is>>size;
	Det.dest.resize(size);
	is.read(&Det.dest[0],size);

	is>>Det.c1;
	is>>Det.c1fare;
	is>>Det.c2;
	is>>Det.c2fare;
	is>>Det.d;
	is>>Det.m;
	is>>Det.y;

	return is;
}


class reser
{
	public:
	int pnr;
	int tno;
	int nosr;
	string tname;
	string bp;
	string dest;
	string pname[100];
	int age[20];
	string clas;
	int d,m,y;
	int con;
	float amc;

	friend fstream& operator<<(fstream& os, reser &Res);
    friend fstream& operator>>(fstream& is, reser &Res);

	void getresdet()
	{
		cout<<"Enter the details as follows\n";
		cout<<"Train no:";
		cin>>tno;
		//cout<<"Train name:";
		//cin>>tname;
		//cout<<"Boarding point:";
		//cin>>bp;
		//cout<<"Destination pt:";
		//cin>>dest;
		cout<<"No of seats required:";
		cin>>nosr;
		for(int i=0;i<nosr;i++)
		{
			cout<<"Passenger First name:";
			cin >> pname[i];
			cout<<"Passenger age:";
			cin>>age[i];
		}
		cout<<"Enter the class f-first class s-second class:";
		cin >> clas;
		cout<<"Date of travel:";
		cin>>d>>m>>y;
		cout<<"Enter the concession category\n";
		cout<<"1.Military\n2.Senior citizen\n";
		cout<<"3.Children below 5 yrs\n4.None\n";
		cin>>con;
		cout<<"����END OF GETTING DETAILS����\n";
	}
	void displayresdet()
	{
		cout<<"Pnr no: "<<pnr;
		cout<<"\nTrain no: "<<tno;
		cout<<"\nTrain name: "<<tname;
		cout<<"\nBoarding point: "<<bp;
		cout<<"\nDestination pt: "<<dest;
		cout<<"\nNo of seats reserved: "<<nosr;
		for(int i=0;i<nosr;i++)
		{
			cout<<"\nPassenger name: ";cout<<pname[i];
			cout<<"Passenger age: "<<age[i];
		}

		cout<<"\nYour class: ";cout<<clas;
		cout<<"\nDate of reservation: "<<d<<"-"<<m<<"-"<<y;
		cout<<"\nYour concession category: "<<con;
		cout<<"\nYou must pay: "<<amc<<endl;
		cout<<"***********************************\n";
	}
};

fstream& operator<<(fstream& os, reser &Res)
{
	
	os<<Res.pnr;
	os.write(" ",1);

	os<<Res.tno;
	os.write(" ",1);

	os<<Res.nosr;
	os.write(" ",1);

	size_t size;
	size=Res.tname.size();
	os<<size;
	os.write(Res.tname.data(),size);

	
	size=Res.bp.size();
	os<<size;
	os.write(Res.bp.data(),size);

	
	size=Res.dest.size();
	os<<size;
	os.write(Res.dest.data(),size);


	for (int i = 0; i < Res.nosr; i++)
	{
		size=Res.pname[i].size();
		os<<size;
		os.write(Res.pname[i].data(),size);
	}
	for (int i = 0; i < Res.nosr; i++)
	{
		os<<Res.age[i];
		os.write(" ",1);
	}

	size=Res.clas.size();
	os<<size;
	os.write(Res.clas.data(),size);

	

	os<<Res.d;
	os.write(" ",1);

	os<<Res.m;
	os.write(" ",1);

	os<<Res.y;
	os.write(" ",1);

	os<<Res.con;
	os.write(" ",1);

	os<<Res.amc;

	//os.write("\n",1);

	return os;
}

fstream& operator>>(fstream& is, reser &Res)
{
	
	size_t size;
	
	is>>Res.pnr;
	is>>Res.tno;
	is>>Res.nosr;

	size=0;
	is>>size;
	Res.tname.resize(size);
	is.read(&Res.tname[0],size);
	
	size=0;
	is>>size;
	Res.bp.resize(size);
	is.read(&Res.bp[0],size);

	size=0;
	is>>size;
	Res.dest.resize(size);
	is.read(&Res.dest[0],size);

	for (int i = 0; i < Res.nosr; i++)
	{
		size=0;
		is>>size;
		Res.pname[i].resize(size);
		is.read(&Res.pname[i][0],size);
	}

	for (int i = 0; i < Res.nosr; i++)
	{
		is>>Res.age[i];
	}
	
	size=0;
	is>>size;
	Res.clas.resize(size);
	is.read(&Res.clas[0],size);

	
	is>>Res.d;
	is>>Res.m;
	is>>Res.y;
	is>>Res.con;
	is>>Res.amc;
	
	return is;

}

class canc
{
    public:
    int pnr;
    int tno;
	int nosc;
    string tname;
	string bp;
	string dest;
    string pname[100];
    int age[20];
    string clas;
    int d, m, y;
    float amr;

	friend fstream& operator<<(fstream& os, canc &Canc);
    friend fstream& operator>>(fstream& is, canc &Canc);


    void getcancdet()
    {
        cout << "Enter the details as follows\n";
        cout << "Pnr no:";
        cin >> pnr;
        cout << "Date of cancellation:";
        cin >> d >> m >> y;
        cout << "���..END OF GETTING DETAILS���..\n";
    }
    void displaycancdet()
    {
        cout << "��������������.\n";
        cout << "��������������.\n";
        cout << "Pnr no:" << pnr;
        cout << "\nTrain no:" << tno;
        cout << "\nTrain name:";
        cout << tname;
        cout << "Boarding point:";
        cout << bp;
        cout << "Destination pt:";
        cout << dest;
        cout << "\nYour class:";
        cout << clas;
        cout << "no of seats to be cancelled:" << nosc;
        for (int i = 0; i < nosc; i++)
        {
            cout << "Passenger First name:";
            cout << pname[i];
            cout << "passenger age:" << age[i];
        }
        cout << "\nDate of cancellation:" << d << "-" << m << "-" << y;
        cout << "\nYou can collect:" << amr << "rs" << endl;
        cout << "*****************************************\n";
        cout << "���END OF CANCELLATION����.\n";
        cout << "*****************************************\n";
    }
};

fstream& operator<<(fstream& os, canc &Canc)
{
	os<<Canc.pnr;
	os.write(" ",1);

	os<<Canc.tno;
	os.write(" ",1);

	os<<Canc.nosc;
	os.write(" ",1);

	size_t size;
	size=Canc.tname.size();
	os<<size;
	os.write(Canc.tname.data(),size);

	
	size=Canc.bp.size();
	os<<size;
	os.write(Canc.bp.data(),size);

	
	size=Canc.dest.size();
	os<<size;
	os.write(Canc.dest.data(),size);

	for (int i = 0; i < Canc.nosc; i++)
	{
		size=Canc.pname[i].size();
		os<<size;
		os.write(Canc.pname[i].data(),size);
	}
	for (int i = 0; i < Canc.nosc; i++)
	{
		os<<Canc.age[i];
		os.write(" ",1);
	}

	size=Canc.clas.size();
	os<<size;
	os.write(Canc.clas.data(),size);

	

	os<<Canc.d;
	os.write(" ",1);

	os<<Canc.m;
	os.write(" ",1);

	os<<Canc.y;
	os.write(" ",1);

	os<<Canc.amr;

	//os.write("\n",1);

	return os;
}
fstream& operator>>(fstream& is, canc &Canc)
{
	size_t size;
	
	is>>Canc.pnr;
	is>>Canc.tno;
	is>>Canc.nosc;

	size=0;
	is>>size;
	Canc.tname.resize(size);
	is.read(&Canc.tname[0],size);
	
	size=0;
	is>>size;
	Canc.bp.resize(size);
	is.read(&Canc.bp[0],size);

	size=0;
	is>>size;
	Canc.dest.resize(size);
	is.read(&Canc.dest[0],size);

	for (int i = 0; i < Canc.nosc; i++)
	{
		size=0;
		is>>size;
		Canc.pname[i].resize(size);
		is.read(&Canc.pname[i][0],size);
	}

	for (int i = 0; i < Canc.nosc; i++)
	{
		is>>Canc.age[i];
	}
	
	size=0;
	is>>size;
	Canc.clas.resize(size);
	is.read(&Canc.clas[0],size);

	
	is>>Canc.d;
	is>>Canc.m;
	is>>Canc.y;
	is>>Canc.amr;
	
	return is;	
}


void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();
int main(void)
{
	int ch;
	cout << "----- RAILWAY RESERVATION SYSTEM ----- \n";
	do
	{
		cout << "\n MAIN MENU \n";
		cout << "1.Admin mode\n2.User mode\n3.Exit \n";
		cout << "Enter your choice : ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				database();
				break;
			case 2:
				user();
				break;
			default:
				exit(0);
		}
	}while(ch<3);

	return 0;
}

void database()
{
	string password;
	string pass = "admin";
	cout << "\nEnter the Admin Password: ";
	cin >> password;
	Detail a;
	Detail temp;
	fstream f;
	int ch;
	char c;
	if(pass!=password)
	{
		cout << "Enter the password correctly \n";
		cout << "You are not permitted to login this mode\n";
	}
	if(pass==password)
	{
		char c;
		do
		{
			cout << "\n --- ADMINISTRATOR MENU --- \n";
			cout << "1. Create detail Database \n";	
			cout << "2. Add details \n";
			cout << "3. Display details \n";
			cout << "4. User Management \n";
			cout << "5. Diplay Passenger details \n";
			cout << "6. Return to Main Menu \n";
			cout << "Enter your choice : ";
			cin >> ch;

			switch(ch)
			{
				case 1:
					f.open("t.txt",ios::out|ios::binary);
					do
					{
					a.getDetail();
					//f.write((char *) &a,sizeof(a));
					f<<a;
					f.write("\n",1);
					cout << "\nDo you want to add one more record?\n";
					cout << "y-for Yes\nn-for No\n";
					cin >> c;
					}while(c=='y');
					f.close();
					break;
				case 2:
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					a.getDetail();
					//f.write((char *) & a,sizeof(a));
					f<<a;
					f.write("\n",1);
					f.close();
					break;
				case 3:
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					f.seekg(0);
					while(f>>temp)
					{
					// cout<<"\nhere\n";
						
						temp.displaydetail();
					}
					f.close();
					break;
				case 4:
					manage();
					break;
				case 5:
					displaypassdetail();
					break;
			}
		}while(ch<=5);
	}
}

void reserve()
{
    int ch;
    do
    {
        cout << "1.Reserve\n2.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            res();
            break;
        }
    } while (ch == 1);
}

void res()
{
    Detail a;
    reser b;
    fstream f1, f2;
    time_t t;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);
    int ch;
    b.getresdet();
	addr=0;
	int j=0;
    while (/*f1.read((char *)&a, sizeof(a))*/f1>>a)
    {
        if (a.tno == b.tno)
        {
            b.tname=a.tname;
			b.bp=a.bp;
			b.dest=a.dest;
			flag=1;
			if (b.clas==f)
            {
                if (a.c1 >= b.nosr)
                {
                    amt = a.c1fare;
                    a.c1 = a.c1 - b.nosr;
                    //f1.write((char *)&a.c1, sizeof(a.c1));
					int i=f1.tellg();
					
					f1.seekg(addr);
					f1<<a;
				
					while (f1.tellg()<i)
					{
						f1.write(" ",1);
					}
					
					
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PERSONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
                    srand((unsigned)time(&t));
                    b.pnr = rand()%(10000000);
                   // f2.write((char *)&b, sizeof(b));
				   f2<<b;
				   f2.write("\n",1);
				   
                    b.displayresdet();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "**********Sorry req seats not available********\n";
                }
            }
            else if (b.clas==s)
            {
                if (a.c2 >= b.nosr)
                {
                    amt = a.c2fare;
                    
                    
                    a.c2 = a.c2 - b.nosr;
                    //f1.write((char *)&a.c2, sizeof(a.c2));
					f1.seekg(addr);
					f1<<a;
					for (j = 0; j < f1.tellg(); i++)
					{
						f1.write(" ",1);
					}
					
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PRESONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
					srand((unsigned)time(&t));
                    b.pnr = rand()%(10000000);
                    //f2.write((char *)&b, sizeof(b));
					f2<<b;
					f2.write("\n",1);
                    b.displayresdet();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "********Sorry requested number of seats not available*******\n";
                }
            }
        }
        else
        {
            flag = 0;
        }
	string temp;
	getline(f1,temp);
    addr=f1.tellg();
	}
    if (flag == 0)
    {
        cout << "!\n";
    }
    f1.close();
    f2.close();
}

void displaypassdetail()
{
	cout << "\n--------Passenger Details--------\n";
	fstream f;
	reser b;
	f.open("p.txt",ios::in|ios::binary);
	while(/*f.read((char *) & b,sizeof(b))*/f>>b)
	{
		b.displayresdet();
	}
	f.close();
}
void enquiry()
{
    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);
    Detail a;
    while(/*f.read((char *) & a,sizeof(a))*/f>>a)
    {
            a.displaydetail();
    }
}
void cancell()
{
    Detail a;
    reser b;
    canc c;
    fstream f1, f2, f3;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary);
    f3.open("cn.txt",ios::in|ios::out|ios::binary);
    cout<<"**********CANCELLATION MENU*********\n";
    c.getcancdet();
	addr=0;
    while(/*f2.read((char *) & b,sizeof(b))*/f2>>b)
    {	cout<<b.pnr<<" pn=  "<<c.pnr<<endl;
        if (b.pnr == c.pnr)
        {
            flag=1;
			c.tno = b.tno;
            c.tname=b.tname;
            c.bp == b.bp;
            c.dest == b.dest;
            c.nosc = b.nosr;
            for (int j = 0; j < c.nosc; j++)
            {
                c.pname[j] = b.pname[j];
                c.age[j] = b.age[j];
            }
            c.clas = b.clas;
            if (c.clas == f)
            {
                while (/*f1.read((char *)&a, sizeof(a))*/f1>>a)
                {
                    if (a.tno == c.tno)
                    {
                        a.c1 = a.c1 + c.nosc;
                        d = a.d;
                        m = a.m;
						f1.seekg(addr);
                        ad = sizeof(a.c1);
						f1<<a;
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        f3<<b;
                        c.displaycancdet();

						break;
                    }
				    string temp;
					getline(f1,temp);
    				addr=f1.tellg();
                }
            }
            else if (c.clas == s)
            {
                while (/*f1.read((char *)&a, sizeof(a))*/f1>>a)
                {
                    if (a.tno == c.tno)
                    {
                        a.c2 = a.c2 + c.nosc;
                        d = a.d;
                        m = a.m;
                        f1.seekg(addr);
                        //f1.write((char *)&a.c2, sizeof(a.c2));
						f1<<a;
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
						f3<<b;
                        c.displaycancdet();
                    }
					string temp;
					getline(f1,temp);
    				addr=f1.tellg();
                }
            }
			break;
        }
        else
        {
            flag = 0;
        }
	}
    if(flag==0)
    {
            cout << "Enter the correct pnr no\n";
    }
    f1.close();
    f2.close();
    f3.close();
}
void can()
{
    int ch;
    do
    {
        cout << "�����..CANCELLATION MENU���\n";
        cout << "1.Cancel\n2.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            cancell();
            break;
        }
    } while (ch == 1);
}
void user()
{
	login a;
	int ch;
	cout<<"\n-----Login User-----\n";
	string password;
	fstream f;
	f.open("id.txt",ios::in|ios::out|ios::binary);
	string id;
	cout << "Enter your ID : ";
	cin >> id;
	cout << "Enter your Password : ";
	cin >> password;
	while(/*f.read((char *) &a,sizeof(a))*/f>>a)
	{
		if((a.id==id)&&(a.pass==password))
		{
			do
			{
				cout<<"\n1.Reserve\n2.Cancel\n3.Enquiry\n4.Return to the main menu\n";
				cout<<"Enter your choice:";
				cin>>ch;
				switch(ch)
				{
					case 1:
						reserve();
						break;
					case 2:
						cancell();
						break;
					case 3:
						enquiry();
						break;
				}
			}while(ch<=3);
		}
		else
		{
			d=1;
		}
	}
	if(d==1)
	{
		cout<<"Enter your user id and password correctly\n";
	}
}

void manage()
{
	int ch;
	fstream f;
	char c;
	login a;
	cout<<"\n---WELCOME TO THE USER MANAGEMENT MENU---\n";
	do
	{
		cout << "1. Create id database\n";
		cout << "2. Add details\n";
		cout << "3. Display details\n";
		cout << "4. Return to the main menu\n";
		cout << "Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				f.open("id.txt",ios::out|ios::binary);
				do
				{
					a.getid();
					//f.write((char *) & a,sizeof(a));
					f<<a;
					f.write("\n",1);
					cout << "Do you want to add one more record\n";
					cout << "y-Yes\nn-No\n";
					cin>>c;
				}while(c == 'y');
				f.close();
				break;
			case 2:
				f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
				a.getid();
				//f.write((char *) & a,sizeof(a));
				f<<a;
				f.write("\n",1);
				f.close();
				break;
			case 3:
				f.open("id.txt",ios::in|ios::out|ios::binary);
				f.seekg(0);
				while(/*f.read((char *) &a,sizeof(a))*/f>>a)
				{
					a.displayid();
				}
				f.close();
				break;
			}
		}while(ch<=3);
}