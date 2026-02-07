#include <iostream>
using namespace std;

struct BookNode {
    int isbn;
    int year;
    string title;
    string author;
    BookNode* prev;
    BookNode* next;
};

class BookList {
private:
    BookNode* head;

public:
    BookList() {
        head = NULL;
    }

    void addBook() {
        BookNode* newNode = new BookNode;

        cout << "Enter ISBN: ";
        cin >> newNode->isbn;
        cout << "Enter Year: ";
        cin >> newNode->year;
        cout << "Enter Title: ";
        cin >> newNode->title;
        cout << "Enter Author: ";
        cin >> newNode->author;

        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } 
        else {
            BookNode* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr;
        }

        cout << "Book Added Successfully!\n";
    }

    void findBook() {
        int searchIsbn;
        bool found = false;

        cout << "Enter ISBN to search: ";
        cin >> searchIsbn;

        BookNode* ptr = head;

        while (ptr != NULL) {
            if (ptr->isbn == searchIsbn) {
                cout << "\nBook Found:\n";
                cout << "ISBN: " << ptr->isbn << endl;
                cout << "Year: " << ptr->year << endl;
                cout << "Title: " << ptr->title << endl;
                cout << "Author: " << ptr->author << endl;
                found = true;
                break;
            }
            ptr = ptr->next;
        }

        if (!found) {
            cout << "Book not found!\n";
        }
    }

    void updateBook() {
        int updateIsbn;
        bool found = false;

        cout << "Enter ISBN to update: ";
        cin >> updateIsbn;

        BookNode* ptr = head;

        while (ptr != NULL) {
            if (ptr->isbn == updateIsbn) {
                cout << "Enter New Title: ";
                cin >> ptr->title;
                cout << "Enter New Year: ";
                cin >> ptr->year;
                cout << "Enter New Author: ";
                cin >> ptr->author;

                cout << "Record Updated Successfully!\n";
                found = true;
                break;
            }
            ptr = ptr->next;
        }

        if (!found) {
            cout << "Book not found!\n";
        }
    }

    void showBooks() {
        if (head == NULL) {
            cout << "No books available.\n";
            return;
        }

        BookNode* ptr = head;

        cout << "\n--- Book Records ---\n";
        while (ptr != NULL) {
            cout << "ISBN: " << ptr->isbn << endl;
            cout << "Year: " << ptr->year << endl;
            cout << "Title: " << ptr->title << endl;
            cout << "Author: " << ptr->author << endl;
            cout << "--------------------\n";
            ptr = ptr->next;
        }
    }
};

int main() {
    BookList bl;
    int option;

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Update Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Select Option: ";
        cin >> option;

        switch (option) {
        case 1:
            bl.addBook();
            break;
        case 2:
            bl.findBook();
            break;
        case 3:
            bl.updateBook();
            break;
        case 4:
            bl.showBooks();
            break;
        case 5:
            cout << "Program Terminated.\n";
            break;
        default:
            cout << "Invalid Option!\n";
        }

    } while (option != 5);

    return 0;
}
