/********************************************
*Ken Smith
*CS210 Project 3
*8/15/25
* this file holds main, and a number of other functions.
*****************************/
using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ItemNode.h"

//read file
ItemNode* ReadFile(ItemNode* head) {
    ifstream inFS;
    head = new ItemNode();
    ItemNode* newNode;
    inFS.open("CS210_Project_Three_Input_File.txt");
    if (!inFS.is_open()) {
        cout << "file open failed";
        return nullptr;
    }
    else {
        string name;
        inFS >> name;
        while (!inFS.eof()) {
            head->CountItem(name);
            inFS >> name;
        }
    }
    inFS.close();
    return head;
}

//print file
void PrintFile(ItemNode* head) {
    ofstream fout;
    fout.open("frequency.dat");
    if (!fout.is_open()) {
        cout << "file open failed" << endl;
        return;
    }
        
    ItemNode* currNode;
    currNode = head->GetNextNode();

    while (currNode != nullptr) {
        fout << currNode->GetName() << currNode->GetCount() << endl;
        currNode = currNode->GetNextNode();
    }
    fout.close();
    cout << "writing backup file: success!" << endl;
    return;
    
}

//show menu
void ShowMenu() {
    cout << "Make a selection:" << endl;
    cout << "1. Look up a specific item count by name" << endl;
    cout << "2. See the counts for all items" << endl;
    cout << "3. See a visual chart for item counts" << endl;
    cout << "4. exit program" << endl;
}

//Get/validate input
int GetInput() {
    int in = -1;
    while (!(in > 0 && in < 5)) {
        ShowMenu();
        try {
            cin >> in;
            if (cin.fail()) {
                throw(runtime_error("bad input"));
            }
            if (!(in > 0 && in < 5)) {
                cout << "Invalid input. Please enter the number from 1-4 of your selection" << endl;
            }
        }
        catch (runtime_error) {
            cout << "Error processing input, please try again, Please enter the number from 1-4 of your selection" << endl;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            in = 0;
        }
    }
    return in;

}

//menu loop
void StartMenu(ItemNode* head) {
    int choice;
    string item;
    cout << "Welcome to the Item Tracker!" << endl;

    choice = GetInput();
    while (choice != 4) {
        
        switch (choice) {
        case 1:
            //cout << "case 1: single item" << endl;
            cout << "What item should be counted (case sensitive)? ";
            cin >> item;
            head->CountForItem(item);
            break;
        case 2:
            cout << "Quantities of all items purchased:" << endl;
            
            head->PrintListCount();
            break;
        case 3:
            cout << "Histogram of all items purchased:" << endl;

            head->PrintListHistogram();
            break;
        }
        choice = GetInput();
    }

}

int main()
{
    ItemNode* head = nullptr;
    cout << "Going to read the file" << endl;
    try {
        head = ReadFile(head);
    }
    catch (...) {
        cout << "An error occured in readFile";
        return -1;
    }

    //cout << "Creating backup file UNCOMMENT BEFORE SUBMITTING" << endl;
    try {
        PrintFile(head);
    }
    catch (...) {
        cout << "An error occured in printFile";
        return -1;
    }

    cout << "Beginning Menu Sequence" << endl;
    StartMenu(head);

    delete head;

    return 0;
}


