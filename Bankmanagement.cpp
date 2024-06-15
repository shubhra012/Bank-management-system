 #include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
using namespace std;
class Bank_acc
{
    float damt;
    char type;
    int pin;
    int acc_no;
    public:
    void report() const;
    int retdamt() const;
    void create_acc();
    void dep(int);
    int retacc_no() const;
    void display() const;
    void updation();
    char rettype() const;
    void draw(int);

 };
 void Bank_acc::create_acc()
 {
    system("cls");
    cout<<"Enter the account nummber:";
    cin>>acc_no;
    cout<<"\nEnter PIN:";
    cin>>pin;
    cout<<"\nEnter type of account(current or savings) C/S:";
    cin>>type;
    type=toupper(type);
    cout<<"\nEnter the initial amount:";
    cin>>damt;
    cout<<"BANK ACCOUNT CREATED.";
 }
 void Bank_acc::display() const
 {    
     
      cout<<"\n\tAccount number:"<<acc_no;
      cout<<"\n\tType of bank account:"<<type;
      cout<<"\n\tTotal balance:"<<damt;

 }
 void Bank_acc::updation()
 {
      cout<<"\nEnter bank account number:";
      cin>>acc_no;
      cout<<"\nEnter new PIN:";
      cin>>pin;
      cout<<"\nEnter updated type of account:";
      cin>>type;
      cout<<"\nEnter updated balance:";
      cin>>damt;
}
 void Bank_acc::dep(int x)
 {
    damt+=x;
 }
 void Bank_acc::draw(int x)
 {
    damt-=x;
 }
 int Bank_acc::retacc_no() const
 {
    return acc_no;
 }
 char Bank_acc::rettype() const
 {
    return type;
 }
 int Bank_acc::retdamt() const
 {
    return damt;
 }
 void Bank_acc::report() const
 {
    
   cout<<"\t     "<<acc_no<<setw(10)<<"  "<<type<<setw(6)<<"   "<<damt<<endl;
 
 }

 void write_Bank_acc();
 void display_balance_acc(int);
 void display_all();
 void delete_bank_acc(int);
 void money_deposit_withdraw(int,int);
 void modify_bank_acc(int);
 int main()
 {
    char ch;
    int num;
    int a1;
    char t1;
    string address;
    do
    {
       system("cls");   
       cout<<"\t\t+++++++++++++++++++++++++++++++++++++++++++++";
       cout<<"\n\t\t\t    BANK MANAGEMENT SYSTEM";
       cout<<"\n\t\t+++++++++++++++++++++++++++++++++++++++++++++";
       cout<<"\n\n\t\t1. Create new account";
       cout<<"\n\t\t2. Balance enquiry";
       cout<<"\n\t\t3. Deposit money";
       cout<<"\n\t\t4. Withdraw money";
       cout<<"\n\t\t5. Display account lists";
       cout<<"\n\t\t6. Updation of account";
       cout<<"\n\t\t7. Checkbook request";
       cout<<"\n\t\t8. Close the account";
       cout<<"\n\t\t9. Exit";
       cout<<"\n\t\tSelect option(1-9):";
       cin>>ch;
       switch(ch)
       {
        case '1':
        {
            write_Bank_acc();
            break;
        }
        case '2':
        {
            system("cls");
            cout<<"Enter account number:";
            cin>>num;
            display_balance_acc(num); //balance enquiry function
            break;
        }
        case '3':
        {
            system("cls");
            cout<<"\t\tEnter account number:";
            cin>>num;
            money_deposit_withdraw(num,1); //deposit money
            break;
        }
        case '4':
        {
            system("cls");
            cout<<"Enter account number:";
            cin>>num;
            money_deposit_withdraw(num,2);//withdraw money
            break;
        }
        case '5':
        {
             display_all();//  Display all function
            break;
        }
        case '6':
        {
            system("cls");
            cout<<"Enter account number:";
            cin>>num;
            modify_bank_acc(num);//updation function
            break;
        }
        case '7':
        {
            system("cls");
            cout<<"\nEnter account number:";
            cin>>a1;
            cout<<"\nEnter address:";
            cin>>address;
            cout<<"\nCheckbook request made.";//checkbook request function
            getchar();
            break;
        }
        case '8':
        {
            system("cls");
            cout<<"Enter account number:";
            cin>>num;
            delete_bank_acc(num); //close account function
            break;
        }
        case '9':
        {
            system("cls");
            cout<<"THANK YOU FOR BANKING WITH US.";
            break;
        }
        }
        cin.ignore();
        cin.get();
    }while (ch!='8');
    return 0;
 }
    
    void write_Bank_acc()
    {
        Bank_acc ac;
	ofstream outFile;
	outFile.open("Bank_acc.dat",ios::binary|ios::app);
	ac.create_acc();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_acc));
	outFile.close();
    }

    void display_balance_acc(int n)
    {
       Bank_acc ac;
	   bool flag=false;
	   ifstream inFile;
	    inFile.open("Bank_acc.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_acc)))
	{
		if(ac.retacc_no()==n)
		{
			ac.display();
			flag=true;
		}
    }
    inFile.close();
	if(flag==false)
		cout<<"\n\n\tBank_Account number does not exist";
    }

    void display_all()
    {
	system("CLS");
	Bank_acc ac;
	ifstream inFile;
	inFile.open("Bank_acc.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tBank_Account HOLDER LIST\n\n";
	cout<<"\t-----------------------------------\n";
	cout<<"\t    A/c no.   Type    Balance\n";
	cout<<"\t------------------------------------\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_acc)))
	{
		ac.report();
	}
	inFile.close();
}

 void modify_bank_acc(int n)
  {
        bool found=false;
	     Bank_acc ac;
	     fstream File;
                File.open("Bank_acc.dat",ios::binary|ios::in|ios::out);
	     if(!File)
	    {
		cout<<"File could not be open !! Press any Key...";
		return;
	    }
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_acc));
		if(ac.retacc_no()==n)
		{
			ac.display();
			cout<<"\n\n\tPlease Enter The New Details of Bank_Account"<<endl;
			ac.updation();
			int pos=(-1)*static_cast<int>(sizeof(Bank_acc));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_acc));
		    cout<<"\n\n\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
    }

    void money_deposit_withdraw(int n ,int option)
    {
        int amt;
	bool found=false;
	Bank_acc ac;
	fstream File;
             File.open("Bank_acc.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_acc));
		if(ac.retacc_no()==n)
		{
			ac.display();
			if(option==1)
			{
				cout<<"\n\n\tTO Money_DepositSS Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be deposited:";
               		            cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be withdraw: ";
				cin>>amt;
				int bal=ac.retdamt()-amt;
				if(bal<0)
					cout<<"Insufficienct balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_acc));
			cout<<"\n\n\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
    }

    void delete_bank_acc(int n)
    {
        Bank_acc ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Bank_acc.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_acc)))
	{
		if(ac.retacc_no()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_acc));
		}
	}
    inFile.close();
	outFile.close();
	remove("Bank_acc.dat");
	rename("Temp.dat","Bank_acc.dat");
	cout<<"\n\nRecord Deleted ..";
    }


