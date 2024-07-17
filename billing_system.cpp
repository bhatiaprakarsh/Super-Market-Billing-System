//this is our header file
#include<iostream>
//fstream file is used for file handling
// fstream provides the capability of creating, writing and reading a file.
#include<string>
#include<fstream>
using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t______________________________\n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t    *Supermarket main menu*   \n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t______________________________\n";
    cout<<"\t\t\t\t                              \n";
    cout<<"\t\t\t\t|       1)Administrator      |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t|       2)Buyer              |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\t\t\t\t|       3)Exit               |\n";
    cout<<"\t\t\t\t|                            |\n";
    cout<<"\n\t\t\t Please select from the above menu!\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        

        cout<<"\t\t\t Please login  \n";
        cout<<"\t\t\t Enter email: ";
        cin>>email;
        cout<<endl;
        cout<<"\t\t\t Password: ";
        cin>>password;
        ////////////////////////////////////    
        if(email=="bhatiaprakarsh@gmail.com" && password=="bhatia@12")
            administrator();
        else 
            cout<<"Invalid username or password";
        
        break;
        

    case 2:
        {
            buyer();
        }
    
    case 3:
        {
            exit(0);
        }
    
    default : 
        {
            cout<<"Please select from the given options";
        }
    }


goto m;
//goto statement is a jump statement (it will help us in jumping to the main menu)
}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Admininstrator menu";
    cout<<"\n\t\t\t|_____1)Add the product_____|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|_____2)Modify the product__|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|_____3)Delete the product__|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|_____4)Back to main menu___|";

    cout<<"\n\n\t Please enter  your choice ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    
    case 2:
        edit();
        break;
    
    case 3:
        rem();
        break;
        
    case 4:
        menu();
        break;

    default:
        cout<<"Invalid choice";
    }
    goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t Buyer \n";
    cout<<"\t\t\t_______________\n";
    cout<<"                     \n";
    cout<<"\t\t\t 1)Buy product \n";
    cout<<"                     \n";
    cout<<"\t\t\t 2)Go back     \n";
    cout<<"\t\t\t Enter your choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    
    case 2:
        menu();
    
    default:
        cout<<"Invalid choice";
    }
    goto m;
}

void shopping :: add()
{
    m:
    //file handling (using fstream class)
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n Name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on the product";
    cin>>dis;
    //file handling operation (object name.open means open the file and 'in' means reading mode ('out' is used for writing mode))
    data.open("database.txt",ios::in);
    
    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        //this is how we read from file
        data>>c>>n>>p>>d;

        while (!data.eof())
        {
            if(c == pcode)
                token++;

            data>>c>>n>>p>>d;    
        }
        data.close();
        
        if(token==1)
            goto m;
        else
        {
            data.open("database.txt", ios::app|ios::out);
            //this is how we write on file
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t\t Record inserted !";
}

void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if (!data)
    {
        cout<<"\n\n File doesn't exist! ";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while (!data.eof())
        {
            if (pkey==pcode)
            {
                cout<<"\n\t\t New product code : ";
                cin>>c;
                cout<<"\n\t\t Name of the product : ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found!";
        }
    }
    
}

void shopping:: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while (!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
            cout<<"\n\n Record not found";

    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|__________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|__________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<" "<<pname<<" "<<price<<" "<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database ";
    }
    else 
    {
        data.close();
        list();
        cout<<"\n_________________________________________\n";
        cout<<"\n|                                       |\n";
        cout<<"\n         Please place the order          \n";
        cout<<"\n|                                       |\n";
        cout<<"\n_________________________________________\n";

        do
        {
            m:
            cout<<"\n\nEnter product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter quantity of the product";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code. Please try again! ";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product ? If yes then press y else no";
            cin>>choice;
        } 
        while (choice=='y');

        cout<<"\n\n\t\t\t_______________Reciept______________\n";
        cout<<"\nProduct No\tProduct quantity\tprice\tAmount\tAmount with discount\n";
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while (!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-((amount)*dis/100);
                    total = total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
        
        

    }

}

int main()
{
    shopping s;
    s.menu();
    return 0;
}