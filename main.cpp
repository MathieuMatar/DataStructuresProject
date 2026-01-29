/*-- CSIS216 Data Structures    Project     Spring 24-25 -----------------
date: 29/4/2025
team:
    Ahmad Abdallah
    Mathieu Matar
    Nadim Sankari

-------------------------------------------------------------------------*/


/*-- Main.cpp ---------------------------------------------------------------
this is a simple tester for the class test that give the option to test almost all given functions
-------------------------------------------------------------------------*/

#include <iostream>
#include <stdexcept>
#include "List.h"

using namespace std;

List<string> lists[5];

void testEverithing();
void adjustList(int l);

int main()
{
    cout << "the following program support up to 5 lists" << endl;

    int choice = -1;
    do
    {
        cout << "\n=== Main Menu ===\n";
        cout << "1. Choose a list to work on\n";
        cout << "2. Multiplication Operator (*): Add 2 lists together (insert at end)\n";
        cout << "3. Test everithing with random data\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int listToEdit = 0;
            cout << "Choose list to edit (1 to 5): ";
            cin >> listToEdit;
            if (listToEdit < 1 || listToEdit > 5)
            {
                cout << "Invalid list number. Please choose between 1 and 5.\n";
                break;
            }
            cout << "You chose list " << listToEdit << ".\n";
            adjustList(listToEdit - 1);

            break;
        }
        case 2:
        {
            cout << "adding 2 lists together\n";
            int l1, l2;
            cout << "Enter the first list number (1 to 5): ";
            cin >> l1;
            cout << "Enter the second list number (1 to 5): ";
            cin >> l2;

            if (l1 < 1 || l1 > 5 || l2 < 1 || l2 > 5)
            {
                cout << "Invalid list number. Please choose between 1 and 5.\n";
                cout << "Try again\n";
                break;
            }

            cout << "You chose list " << l1 << " and list " << l2 << ".\n";
            List<string> temp = lists[l1 - 1] * lists[l2 - 1];
            cout << "Result of multiplication: \n";
            cout << temp;
            cout << "!result list is not saved anywhere\n";
            break;
        }
        case 3:
            cout << "testing everything with random data\n";
            testEverithing();
            cout << "\n\n-------------------------------\ntest finished\n--------------------------------\n--------------------------------\n\n";
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}


void testEverithing()
{
    // Test the List class with random

    // Create a List of integers
    List<int> list1 = List<int>();

    list1.insertFirst(1);
    list1 + 4 + 5 + 4 + 3 + 5 + 3;
    list1.insertAtEnd(8998);
    list1.insertFirst(98765);
    list1.insertAtPosition(3, 1234);

    for (int i = 0; i < 10; i++)
    {
        list1.insertAtEnd(i);
    }

    cout << "List after inserting 1 at the beginning: ";
    cout << list1;

    // test delete
    list1.deleteFirst();
    list1.deleteAt(4);
    list1.deleteLast();
    list1.deleteValue(5);
    list1 - 4;
    cout << "List after deleting first, at position 3, last and value 5: ";
    cout << list1;

    // test isEmpty
    cout << "Is the list empty? " << (list1.isEmpty() ? "Yes" : "No") << endl;
    // test size
    cout << "Size of the list: " << list1.getSize() << endl;

    // search
    int pos = list1.search(3);
    if (pos != -1)
    {
        cout << "Element 3 found at position: " << pos << endl;
    }
    else
    {
        cout << "Element 3 not found in the list." << endl;
    }

    // get data at pos
    try
    {
        cout << "Data at position 2: " << list1.getDataAtPos(2) << endl;
    }
    catch (const std::out_of_range &e)
    {
        cout << e.what() << endl;
    }

    // get data at position that don't exist
    try
    {
        cout << "Data at position 20: " << list1.getDataAtPos(20) << endl;
        cout << "hi";
    }
    catch (const std::out_of_range &e)
    {
        cout << e.what() << endl;
    }

    cout << "hello";

    // add some 4 random sumbers at end, like

    list1 + 4 + 2 + 54 + 2345;

    // test arrange
    cout << "arrange";
    // list1.arrange();
    cout << "List after arranging: ";
    cout << list1;

    // test reverse
    cout << "List after reversing: ";
    list1.reverse();
    cout << list1;

    // make new list add some variable then cout then clear it then add some other variable
    List<int> list2 = List<int>();
    list2.insertAtEnd(1);
    list2.insertAtEnd(2);
    list2.insertAtEnd(3);
    list2.insertAtEnd(4);
    list2.displayList(cout);
    list2.clear();
    cout << "List after clearing: ";
    cout << list2;
    list2.insertAtEnd(1);
    list2.insertAtEnd(6);
    list2.insertAtEnd(8);

    // test oprators
    cout << "List2 after adding 1,6,8: ";
    cout << list2;
    cout << "List1 * List2: ";
    List<int> list3 = list1 * list2;
    cout << list3;
    cout << "List1 % List2: ";
    list1 % list2;
    cout << list1;
    cout << "List1 / 2: ";
    List<int> *list4 = list1 / 2;
    for (int i = 0; i < 2; i++)
    {
        cout << "List4[" << i << "]: " << list4[i];
    }
    delete[] list4; // Free the dynamically allocated memory
    cout << "List1 < List2: " << (list1 < list2 ? "True" : "False") << endl;
    cout << "List1 > List2: " << (list1 > list2 ? "True" : "False") << endl;
}

void adjustList(int l)
{
    int choice = -1;
    do
    {
        cout << "\n=== List " << (l + 1) << " Menu ===\n";
        cout << "1. Insert at first\n";
        cout << "2. Insert at position\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete first\n";
        cout << "5. Delete at position\n";
        cout << "6. Delete last\n";
        cout << "7. Delete value\n";
        cout << "8. Search\n";
        cout << "9. Get data at position\n";
        cout << "10. Arrange\n";
        cout << "11. Clear\n";
        cout << "12. Reverse\n";
        cout << "13. Display list\n";
        cout << "0. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string data;
            cout << "Enter data to insert at first: ";
            cin >> data;
            lists[l].insertFirst(data);
            break;
        }
        case 2:
        {
            string data;
            int pos;
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter position to insert at: ";
            cin >> pos;
            try
            {
                lists[l].insertAtPosition(pos, data);
            }
            catch (const out_of_range &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 3:
        {
            string data;
            cout << "Enter data to insert at end: ";
            cin >> data;
            lists[l].insertAtEnd(data);
            break;
        }
        case 4:
        {
            lists[l].deleteFirst();
            break;
        }
        case 5:
        {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;
            try
            {
                lists[l].deleteAt(pos);
            }
            catch (const out_of_range &e)
            {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 6:
        {
            lists[l].deleteLast();
            break;
        }
        case 7:
        {
            string data;
            cout << "Enter value to delete: ";
            cin >> data;
            lists[l].deleteValue(data);
            break;
        }
        case 8:
        {
            string data;
            cout << "Enter value to search for: ";
            cin >> data;
            int pos = lists[l].search(data);
            if (pos != -1)
            {
                cout << "Element " << data << " found at position: " << pos << endl;
            }
            else
            {
                cout << "Element " << data << " not found in the list." << endl;
            }
            break;
        }
        case 9:
        {
            int pos;
            cout << "Enter position to get data from: ";
            cin >> pos;
            try
            {
                string data = lists[l].getDataAtPos(pos);
                cout << "Data at position " << pos << ": " << data << endl;
            }
            catch (const std::out_of_range &e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 10:
        {
            lists[l].arrange();
            cout << "List arranged.\n";
            break;
        }
        case 11:
        {
            lists[l].clear();
            cout << "List cleared.\n";
            break;
        }
        case 12:
        {
            lists[l].reverse();
            cout << "List reversed.\n";
            break;
        }
        case 13:
        {
            cout << "List contents:\n";
            cout << lists[l];
            break;
        }
        case 0:
            cout << "Returning to main menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);
}

// g++ (Get-ChildItem -Filter *.cpp).Name -o temp_program.exe; .\temp_program.exe; Remove-Item temp_program.exe