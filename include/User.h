#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    int id;             // User ID
    string username;    // System login name
    string password;    // User account password

public:
    // Constructor
    User(int id, string username, string password);

    // Virtual Destructor
    virtual ~User() = default;

    //Check log in information 
    bool login(string uname, string pwd);

    // Getter Functions 
    int getID() const;
    string getUsername() const;
    
    //Pure virtual function
    virtual void displayMenu() = 0; 
};

#endif