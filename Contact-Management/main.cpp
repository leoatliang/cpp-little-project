#include <iostream>
#include <string>

using namespace std;

// Menu interface
void showMenu(){
    cout << "******************************************" << endl;
    cout << "***********  1. Add contact     **********" << endl;
    cout << "***********  2. Show contact    **********" << endl;
    cout << "***********  3. Delete contact  **********" << endl;
    cout << "***********  4. Find contact    **********" << endl;
    cout << "***********  5. Modify contact  **********" << endl;
    cout << "***********  6. Empty contact   **********" << endl;
    cout << "***********  0. Exit            **********" << endl;
    cout << "******************************************" << endl;
}

// Contacts
struct Person{
    string m_Name; // name
    int m_Sex; // sex: 0(male) 1(female)
    int m_Age; // age
    string m_Phone; // phone
    string m_Addr; // address
};

// Address book (Max = 100)
#define MAX 100
struct Addressbooks{
    struct Person personArray[MAX];
    int m_Size;
};

// 1. Add contact
void addPerson(Addressbooks *abs){
    if (abs->m_Size == MAX){
        cout << "Address book is full, can't be added!" << endl;
        return;
    }
    else{
        // name
        string name;
        cout << "Please enter a name:";
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        // sex
        cout << "Please enter gender(0->male 1->female):";
        int sex = 0;
        cin >> sex;
        while(true){
            if (sex == 0 || sex == 1){
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "Incorrect input, please re-enter!";
        }

        // age
        cout << "Please enter age:";
        int age=0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        // phone
        cout << "Please enter phone(four digits):";
        string phone = "";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // address
        cout << "Please enter address:";
        string address = "";
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        // updated number of persons
        abs->m_Size++;

        cout << "Added Successfully!" << endl << endl;
    }

}

// 2. Show contact
void showPerson(Addressbooks *abs){
    if (abs->m_Size == 0){
        cout << "current record is empty" << endl << endl;
    }
    else{
        for (int i = 0; i < abs->m_Size; i++){
            cout << "Name: " << abs->personArray[i].m_Name << "\t";
            cout << "Sex: " << (abs->personArray[i].m_Sex == 0 ? "male" : "female") << "\t";
            cout << "Age: " << abs->personArray[i].m_Age << "\t";
            cout << "Phone: " << abs->personArray[i].m_Phone << "\t";
            cout << "Address: " << abs->personArray[i].m_Addr << endl;
        }
    }
    cout << endl;
}

// 3. Delete contact
// Determines if the queried person exists, returns its index position if it exists, and returns-1 if it does not exist.
int isExist(Addressbooks *abs, string name){
    for (int i = 0; i < abs->m_Size; i++){
        if (abs->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;
}

void deletePerson(Addressbooks *abs){
    cout << "Please enter the contact you want to delete:";
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1){
        for (int i = ret; i < abs->m_Size; i++){
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "Deleted Successfully!" << endl;
    }
    else{
        cout << "This person does not exist!" << endl;
    }
    cout << endl;
}

// 4. Find contact
void findPerson(Addressbooks *abs){
    cout << "Please enter the contact you want to find:";
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1){
        cout << "Name: " << abs->personArray[ret].m_Name << "\t";
        cout << "Sex: " << (abs->personArray[ret].m_Sex == 0 ? "male" : "female") << "\t";
        cout << "Age: " << abs->personArray[ret].m_Age << "\t";
        cout << "Phone: " << abs->personArray[ret].m_Phone << "\t";
        cout << "Address: " << abs->personArray[ret].m_Addr << endl;
    }
    else{
        cout << "This person does not exist!" << endl ;
    }
    cout << endl;
}

// 5. Modify person
void modifyperson(Addressbooks *abs){
    cout << "Please enter the contact you want to modify:";
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1){
        // name
        cout << "Please enter a modified name:";
        cin >> name;
        abs->personArray[ret].m_Name = name;

        // sex
        cout << "Please enter a modified gender(0->male 1->female):";
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 0 || sex == 2){
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "Incorrect input, please re-enter!";
        }

        // age
        cout << "Please enter a modified age:";
        int age=0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        // phone
        cout << "Please enter a modified phone(four digits):";
        string phone = "";
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        // address
        cout << "Please enter a modified address:";
        string address = "";
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "Modified successfully!" << endl;
    }
    else{
        cout << "This person does not exist!" << endl;
    }
    cout << endl;
}

// 6. Empty contact
void emptyPerson(Addressbooks *abs){
    abs->m_Size = 0;
    cout << "Address book cleared!" << endl;
}


int main(){
    // Create Address Book
    Addressbooks abs;
    abs.m_Size = 0;

    int select = 0;

    while(true){
        showMenu();

        cout << endl;
        cout << "Please enter your choice:";
        cin >> select;

        switch(select){
            case 1: 
                addPerson(&abs);
                break;
            case 2: 
                showPerson(&abs);
                break;
            case 3: 
                deletePerson(&abs);
                break;
            case 4: 
                findPerson(&abs);
                break;
            case 5: 
                modifyperson(&abs);
                break;
            case 6: 
                emptyPerson(&abs);
                break;
            case 0: // exit
                cout << "Welcome to next time!" << endl;
                return 0;
                break;
            default: break;
        }
    }
    return 0;
}