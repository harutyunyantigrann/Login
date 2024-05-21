#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class User 
{
public:
    
    
    User() { while (true) { choice(); } }
private:
    void choice()
    {
        int ch;
        cout << "Choice " << endl <<
            "1.Register" << endl <<
            "2.Login" << endl <<
            "Enter choice: ";
        cin >> ch;
        while (ch != 1 && ch != 2) {
            cout << "You write wrong number, Please try again \n Enter: ";
            cin >> ch;
        }
        if (ch == 1) { Registration(); }
        else if (ch == 2) { Login(); }
    }
    bool IsLoggedIn()
    {
        string username, password, un, pw;
        cout << "Enter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;
        ifstream read("Database\\" + username + ".txt");
        getline(read, un);
        getline(read, pw);
        if (un == username && pw == password)
        {
            return true;
        }
        else { return false; }
    }
    bool IsLoggedIn(string username)
    {
        string un;
        ifstream read("Database\\" + username + ".txt");
        getline(read, un);
        if (un == username)
        {
            return true;
        }
        else { return false; }
    }
    
    void Registration()
    {
        string username, password;
        cout << "select a username: "; cin >> username;
        if (IsLoggedIn(username))
        {
            cout << "We have account with this login" << endl;
            choice();
        }
        cout << "select a password: "; cin >> password;


        ofstream file;
        file.open("Database\\" + username + ".txt");
        file << username << endl << password;
        file.close();
        choice();
    }
    void Login()
    {
        bool status = IsLoggedIn();
        if (!status)
        {
            cout << "False login or password";

        }
        else {
            cout << "Succesfuly login in!" << endl;

        }
    }
};


int main()
{   
    User user;
}

