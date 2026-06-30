#include "project/LibraryManager.h"
#include <iostream>
#include <limits>
#include <string>
#include "project/InputHelper.h"
#include "project/AudioBook.h"
#include "project/Book.h"
#include "project/Comic.h"
#include "project/Magazine.h"
using namespace std;

int main() {
  LibraryManager library;
    int choice;

    do
    {
        cout << endl;
        cout << "========== LIBRARY ==========" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add AudioBook" << endl;
        cout << "3. Add Comic" << endl;
        cout << "4. Add Magazine" << endl;
        cout << "5. Show Library" << endl;
        cout << "6. Borrow Item" << endl;
        cout << "7. Return Item" << endl;
        cout << "8. Read Item" << endl;
        cout << "0. Exit" << endl;

        choice = inputInt("Choice: ");

        if (choice == 1)
        {
            string title = inputString("Title: ");
            string author = inputString("Author: ");
            int year = inputInt("Year: ");

            library.addItem(new Book(title, author, year));
        }

        else if (choice == 2)
        {
            string title = inputString("Title: ");
            string author = inputString("Author: ");
            int year = inputInt("Year: ");
            int duration = inputInt("Duration (minutes): ");

            library.addItem(new AudioBook(title, author, year, duration));
        }

        else if (choice == 3)
        {
            string title = inputString("Title: ");
            string artist = inputString("Artist: ");
            int year = inputInt("Year: ");

            library.addItem(new Comic(title, artist, year));
        }

        else if (choice == 4)
        {
            string title = inputString("Title: ");
            int issue = inputInt("Issue number: ");
            int year = inputInt("Year: ");

            library.addItem(new Magazine(title, issue, year));
        }

        else if (choice == 5)
        {
            library.showItems();
        }

        else if (choice == 6)
        {
            library.showItems();

            int number = inputInt("Enter item number: ");

            library.borrowItem(number - 1);
        }

        else if (choice == 7)
        {
            library.showItems();

            int number = inputInt("Enter item number: ");

            library.returnItem(number - 1);
        }

        else if (choice == 8){
            library.showItems();

            int number = inputInt("Enter item number: ");

            library.readItem(number - 1);
        }

    }
    while (choice != 0);

    return 0;
}
