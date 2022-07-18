#include <bits/stdc++.h>
#include<conio.h>
#include<map>
using namespace std;
map<string,string> q;
class LoginSystem
{
private:
    string username,password;
public:
    friend istream& operator >> (istream&,LoginSystem &a);
    friend ostream& operator << (ostream&,LoginSystem a);
};
istream& operator >> (istream&,LoginSystem &a)
{
    cout<<"Moi ban nhap username:"; cin>>a.username;
    cout<<"Moi ban nhap password:"; cin>>a.password;
}
ostream& operator << (ostream&,LoginSystem a)
{
    ofstream output("LOGIN.INP",ios::app);
    output<<endl<<a.username<<endl<<a.password;
    output.close();
}
//LOGIN
void Login()
{
   string username,password;
   cout<<"Nhap username:"; cin>>username;
   cout<<"Nhap password:";
   char x;
   while(1>0)
      {
      x=getch();
      if ((x==' ')||(x==13)) break;
      if (x==8) {password.erase(password.size()-1,1); cout<<"\b \b";} else
      {
      cout<<"*";
      password+=x;
      }
      }
      cout<<endl<<"Wait a minetu to check your password";
      if (q[username]==password)
         {
        system("cls");
        cout<<"Hello:"<<username;
         }
      else
         {
         cout<<endl<<"Wrong Password. Please check your password."<<endl;
         Login();
         }
}
void Menu()
{
    int NumberChosen;
    cout<<"Hello. What can i do for you"<<endl;
    cout<<"1. Login"<<endl<<"2.Register"<<endl;
    ifstream input("LOGIN.INP");
    //freopen("Login.OUT","w",stdout);
    string x,y;

    while(input>>x>>y)
    {
    q[x]=y;
    }
    input.close();
    cout<<"Which number do you choose: ";
    cin>>NumberChosen;
    switch(NumberChosen)
    {
    case 1:
        {
            Login();
            break;
        }
    case 2:
        {
          LoginSystem a;
          cin>>a;
          cout<<a;
          break;
        }
    }
}
int main()
{
    Menu();
    cout<<endl<<"Press any key to exit:";
    getch();
    return 0;
}
