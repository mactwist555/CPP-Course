#include <iostream>
using namespace std;

#include "Menu.hpp"
#include "ToDo.hpp"
#include "Exporter.hpp"

int main()
{
    bool done = false;
    string menuList[] = {
            "Add to To-Do List",
            "Save list as .txt",
            "Save list as .csv",
            "Exit"
            };

    ToDo myList;

    while ( !done )
    {
        cout << endl << "TO DO LIST" << endl;
        myList.DisplayList();

        cout << endl;

        int choice = Menu::ShowMenu( menuList, 4 );

        if ( choice == 0 )
        {
            cout << "Add item: ";
            string item;
            cin.ignore();
            getline( cin, item );
            myList.AddItem( item );
        }
        else if ( choice == 1 )
        {
            cout << "Name: ";
            string name;
            cin >> name;
            name += ".txt";

            TextExporter exp( name );
            int listSize = myList.GetSize();
            string* exportList = new string[ listSize ];
            myList.GetList( exportList, listSize );
            exp.Save( exportList, listSize );
            delete [] exportList;

            cout << "Saved to " << name << endl;
        }
        else if ( choice == 2 )
        {
            cout << "Name: ";
            string name;
            cin >> name;
            name += ".csv";

            CsvExporter exp( name );
            int listSize = myList.GetSize();
            string* exportList = new string[ listSize ];
            myList.GetList( exportList, listSize );
            exp.Save( exportList, listSize );
            delete [] exportList;

            cout << "Saved to " << name << endl;
        }
        else
        {
            done = true;
        }
    }

    return 0;
}
