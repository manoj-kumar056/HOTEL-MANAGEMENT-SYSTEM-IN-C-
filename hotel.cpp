#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Room {
    int number;
    bool booked;
};
struct Guest {
    string name;
    int roomNumber;
};

class Hotel {
private:
    vector<Room> rooms;
    vector<Guest> guests;

public:
    Hotel(int numRooms) {
        for (int i = 0; i < numRooms; ++i) {
            Room room;
            room.number = i + 1;
            room.booked = false;
            rooms.push_back(room);
        }
    }
    void displayAvailableRooms() {
        cout << "Available Rooms:" << endl;
        for (const auto& room : rooms) {
            if (!room.booked) {
                cout << "Room " << room.number << endl;
            }
        }
    }
    void bookRoom(const string& guestName, int roomNumber) {
        if (roomNumber <= 0 || roomNumber > rooms.size()) {
            cout << "Invalid room number." << endl;
            return;
        }
        Room& room = rooms[roomNumber - 1];
        if (room.booked) {
            cout << "Room " << roomNumber << " is already booked." << endl;
            return;
        }
        room.booked = true;
        Guest guest;
        guest.name = guestName;
        guest.roomNumber = roomNumber;
        guests.push_back(guest);
        cout << "Room " << roomNumber << " booked for " << guestName << " successfully." << endl;
    }
    void displayGuests() {
        cout << "Guest List:" << endl;
        for (const auto& guest : guests) {
            cout << "Guest Name: " << guest.name << ", Room Number: " << guest.roomNumber << endl;
        }
    }
};
int main() {
    int numRooms;
    cout << "Enter the number of rooms in the hotel: ";
    cin >> numRooms;
    Hotel hotel(numRooms);

    int choice;
    do {
        cout << "\nHotel Management System Menu:" << endl;
        cout << "1. Display Available Rooms" << endl;
        cout << "2. Book a Room" << endl;
        cout << "3. Display Guest List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayAvailableRooms();
                break;
            case 2: {
                string name;
                int roomNum;
                cout << "Enter guest name: ";
                cin >> name;
                cout << "Enter room number to book: ";
                cin >> roomNum;
                hotel.bookRoom(name, roomNum);
                break;
            }
            case 3:
                hotel.displayGuests();
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);
    return 0;
}
