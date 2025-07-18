
# 🚆 Train Ticket Booking System (C++)

This is a simple console-based Train Ticket Booking System implemented in C++. It demonstrates the use of standard data structures such as vectors and queues to manage ticket bookings, cancellations, and waitlisting.

---

## 📌 Features

- Book tickets with passenger details (name, source, destination)
- Maintain a fixed number of train seats (default: 5)
- Automatically manage a waitlist when seats are full
- Cancel booked tickets
- Move waitlisted passengers to booked list when a seat becomes free
- View all current bookings and waitlisted passengers
- Menu-driven user interface

---

## 🛠️ Technologies Used

- C++ (Standard Library)
- Data Structures: std::vector, std::queue
- Basic input/output using std::cin and std::cout

---

## 🚀 How It Works

- The system allows a maximum of 5 active bookings.
- If a user tries to book after all seats are filled, they are added to a waitlist.
- On cancellation of a booked ticket, the first passenger from the waitlist (if any) is automatically moved to the booked list.

---

## 💻 How to Run

1. Copy the source code into a file named main.cpp.
2. Compile using a C++ compiler (g++, clang++, etc.):

   ```bash
   g++ main.cpp -o booking
   ```

3. Run the program:

   ```bash
   ./booking
   ```

---

## 📋 Menu Options

When the program runs, it displays the following menu:

1. Book Ticket  
2. View Booked Tickets  
3. Cancel Ticket  
4. View Waitlist  
5. Exit  

Simply enter the number of your choice to perform the corresponding operation.

---

## 📦 Sample Input & Output

Example:
```
Enter choice: 1
Enter passenger name: Raj
Enter source station: Delhi
Enter destination station: Mumbai
Ticket booked successfully! Ticket ID: 1
```

---

## 🧠 Concepts Demonstrated

- Object-Oriented Programming (struct Ticket)
- Dynamic arrays (std::vector)
- Queues for FIFO waitlisting (std::queue)
- Loop and switch-case for menu-driven UI
- Real-world logic simulation

---

## 🔧 Customization

- To change the number of available seats, modify:
  ```cpp
  const int MAX_SEATS = 5;
  ```

---

## 📝 Author

Developed by: [Your Name]  
Project Type: DSA File Handling / Mini Project  
Language: C++
