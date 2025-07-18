#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAX_SEATS = 5; // Total seats in the train

// Structure to store ticket info
struct Ticket {
    int ticketID;
    string name;
    string source;
    string destination;
};

vector<Ticket> bookedTickets;
queue<Ticket> waitlist;
int ticketCounter = 1;

// Function to book ticket
void bookTicket() {
    Ticket t;
    t.ticketID = ticketCounter++;

    cout << "\nEnter passenger name: ";
    cin.ignore();
    getline(cin, t.name);

    cout << "Enter source station: ";
    getline(cin, t.source);

    cout << "Enter destination station: ";
    getline(cin, t.destination);

    if (bookedTickets.size() < MAX_SEATS) {
        bookedTickets.push_back(t);
        cout << "Ticket booked successfully! Ticket ID: " << t.ticketID << "\n";
    } else {
        waitlist.push(t);
        cout << "Seats full. Added to waitlist. Waitlist position: " << waitlist.size() << "\n";
    }
}

// Function to view all booked tickets
void viewBookings() {
    cout << "\n--- Booked Tickets ---\n";
    if (bookedTickets.empty()) {
        cout << "No tickets booked.\n";
        return;
    }

    for (const Ticket& t : bookedTickets) {
        cout << "ID: " << t.ticketID << ", Name: " << t.name
             << ", From: " << t.source << ", To: " << t.destination << "\n";
    }
}

// Function to cancel a ticket
void cancelTicket() {
    int id;
    cout << "\nEnter Ticket ID to cancel: ";
    cin >> id;

    bool found = false;

    for (auto it = bookedTickets.begin(); it != bookedTickets.end(); ++it) {
        if (it->ticketID == id) {
            cout << "Ticket cancelled for " << it->name << "\n";
            bookedTickets.erase(it);
            found = true;

            // If someone is in waitlist, move to bookings
            if (!waitlist.empty()) {
                Ticket next = waitlist.front();
                waitlist.pop();
                bookedTickets.push_back(next);
                cout << "Waitlisted ticket booked for " << next.name
                     << ", Ticket ID: " << next.ticketID << "\n";
            }

            break;
        }
    }

    if (!found)
        cout << "Ticket ID not found.\n";
}

// Function to show waitlist
void viewWaitlist() {
    cout << "\n--- Waitlisted Passengers ---\n";
    if (waitlist.empty()) {
        cout << "No one in waitlist.\n";
        return;
    }

    queue<Ticket> temp = waitlist;
    while (!temp.empty()) {
        Ticket t = temp.front();
        temp.pop();
        cout << "ID: " << t.ticketID << ", Name: " << t.name << "\n";
    }
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n--- Train Ticket Booking Platform ---\n";
        cout << "1. Book Ticket\n";
        cout << "2. View Booked Tickets\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. View Waitlist\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: viewBookings(); break;
            case 3: cancelTicket(); break;
            case 4: viewWaitlist(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
