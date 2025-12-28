# ATM-System
ATM Syetm Using C++

ATM System Project using C++ (OOP)
I’ve developed a fully functional ATM System using Object-Oriented Programming (OOP) principles in C++. The project is structured into multiple header files, making the code modular, organized, and easy to maintain.

🔐 Login System:
Users must enter their Account Number and Password.
The system allows 3 attempts only; after that, the program automatically closes for security.
All client data is securely stored and retrieved from a text file.

💻 Main Features:
🏧 Quick Withdraw
💰 Normal Withdraw
📥 Deposit
📊 Check Balance
🔑 Change PIN Code
📝 Transaction History per client
🚪 Logout

🧠 Class Structure & OOP Design:
A base screen class is responsible for displaying the client’s name, phone number, account number, and the current date.
All other screen classes inherit from this base class to ensure consistent UI, improve code reusability, and reduce repetition.
The project is divided into separate header files, keeping responsibilities clear and improving scalability.

🧱 OOP Concepts Implemented:
Encapsulation: Each class manages its own data and behavior, protecting client information and ensuring clean interactions between components.
Inheritance: Screen classes inherit from a base screen class to share common functionality without rewriting code.
Abstraction: Complex operations (e.g., login validation, transactions) are hidden behind clean, easy-to-use class interfaces.
Modularity: Splitting the system into multiple headers and classes improves structure and makes the project easier to extend.
Reusability & Maintainability: Common logic is centralized, making future updates more efficient.

✅ Input Validation:
Prevents negative amounts.
Prevents out-of-range selections.
Ensures numeric input where required (no strings in numeric fields).

⚡ Key Skills Demonstrated:
Advanced C++ Programming.
Strong OOP Design & Architecture.
File Handling & Data Persistence.
Error Handling & Input Validation.
Modular Project Structure with Header Files.
Building Real-World Console Applications.
