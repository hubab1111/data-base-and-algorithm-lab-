#include <iostream>
using namespace std;

struct SongNode {
    int id;
    int duration;
    string title;
    string artist;
    SongNode* prev;
    SongNode* next;
};

class Playlist {
private:
    SongNode* head;
    SongNode* current;

public:
    Playlist() {
        head = NULL;
        current = NULL;
    }

    void addSong() {
        SongNode* newSong = new SongNode;

        cout << "Enter Song ID: ";
        cin >> newSong->id;
        cout << "Enter Duration: ";
        cin >> newSong->duration;
        cout << "Enter Title: ";
        cin >> newSong->title;
        cout << "Enter Artist: ";
        cin >> newSong->artist;

        newSong->next = NULL;
        newSong->prev = NULL;

        if (head == NULL) {
            head = newSong;
        } else {
            SongNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->prev = temp;
        }

        cout << "Song Added Successfully!\n";
    }

    void displayAll() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        SongNode* temp = head;
        cout << "\n--- Playlist ---\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id << endl;
            cout << "Duration: " << temp->duration << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Artist: " << temp->artist << endl;
            cout << "-----------------\n";
            temp = temp->next;
        }
    }

    void searchSong() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        int option;
        cout << "Search By:\n1. Title\n2. Artist\nChoose option: ";
        cin >> option;

        bool found = false;
        SongNode* temp = head;

        if (option == 1) {
            string t;
            cout << "Enter Title: ";
            cin >> t;

            while (temp != NULL) {
                if (temp->title == t) {
                    cout << "Song Found:\n";
                    cout << temp->id << " "
                         << temp->duration << " "
                         << temp->title << " "
                         << temp->artist << endl;
                    found = true;
                }
                temp = temp->next;
            }
        } 
        else if (option == 2) {
            string a;
            cout << "Enter Artist: ";
            cin >> a;

            while (temp != NULL) {
                if (temp->artist == a) {
                    cout << "Song Found:\n";
                    cout << temp->id << " "
                         << temp->duration << " "
                         << temp->title << " "
                         << temp->artist << endl;
                    found = true;
                }
                temp = temp->next;
            }
        }

        if (!found) {
            cout << "Song not found.\n";
        }
    }

    void updateSong() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        int searchID;
        bool found = false;

        cout << "Enter Song ID to update: ";
        cin >> searchID;

        SongNode* temp = head;

        while (temp != NULL) {
            if (temp->id == searchID) {
                cout << "Enter New Title: ";
                cin >> temp->title;
                cout << "Enter New Artist: ";
                cin >> temp->artist;
                cout << "Enter New Duration: ";
                cin >> temp->duration;

                cout << "Song Updated Successfully!\n";
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Song not found.\n";
        }
    }

    void playNext() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current == NULL)
            current = head;
        else if (current->next != NULL)
            current = current->next;

        cout << "Now Playing: " 
             << current->title << " by " 
             << current->artist << endl;
    }

    void playPrevious() {
        if (current != NULL && current->prev != NULL) {
            current = current->prev;
            cout << "Now Playing: " 
                 << current->title << " by " 
                 << current->artist << endl;
        } else {
            cout << "No previous song available.\n";
        }
    }
};

int main() {
    Playlist pl;
    int choice;

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Search Song\n";
        cout << "4. Update Song\n";
        cout << "5. Play Next\n";
        cout << "6. Play Previous\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            pl.addSong();
            break;
        case 2:
            pl.displayAll();
            break;
        case 3:
            pl.searchSong();
            break;
        case 4:
            pl.updateSong();
            break;
        case 5:
            pl.playNext();
            break;
        case 6:
            pl.playPrevious();
            break;
        case 7:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
