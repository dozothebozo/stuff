/*
    Create a class named BankAccount that models a simple checking account.

    Data members:
    - owner name
    - account number
    - current balance

    Required behavior:
    - Constructor that initializes all three fields.
    - deposit(double amount)
    - withdraw(double amount)
    - getBalance() const
    - printSummary() const

    Rules:
    - A deposit must be greater than 0.
    - A withdrawal must be greater than 0 and cannot exceed the balance.
    - If an invalid deposit or withdrawal is attempted, print a clear error message.
    - The balance should never become negative.

    Example:

        BankAccount account{"Maya Chen", 1001, 250.00};

        account.deposit(75.50);
        account.withdraw(100.00);
        account.printSummary();

    Possible output:

        Account owner: Maya Chen
        Account number: 1001
        Balance: $225.50
*/
