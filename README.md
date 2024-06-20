# Banking-System
 Bank Transactions Management System with Doubly Linked List Implementation This program manages bank transactions using a doubly linked list (DLL) to represent and compute transactions in a bank. It supports various operations such as processing transactions, moving the cursor, inserting transactions, deleting transactions, and retrieving account information.

 Data Structures Used: 
Doubly Linked List (DLL):
Each node in the DLL represents a transaction. The cursor denotes the most recent transaction processed.

Singly Linked List (SLL):
Stores the list of bank accounts. Each element stores the account number and current balance.

And following functions:

• F X // Process the next X transactions after the cursor; if last transaction is processed before completing X transactions, then the cursor stays in the last node.

• R Y // Undo Y transactions starting from the cursor; if first transaction is processed before completing Y transactions, then the cursor stays in the first node.

• I T K // Insert a new Transaction T immediately after the Kth transaction in the list. Insert only
if K is a valid value. If inserting before cursor position, then process this new transaction as well.
The cursor position does not change.

• D A M // Delete (up to) M (̸= 0) number of transactions of account A after/before (but excluding)
the cursor’s transaction; delete in the forward direction if M > 0 and reverse direction if M < 0.
Update the balance of account A accordingly. The cursor stays in its original location.

• C // Process ALL transactions after the cursor.

• S Y // Print all the processed transactions (until the cursor) of Account Number Y, one transaction
per line. If Y is invalid, no output is generated.

• G X // Print the count of the accounts whose balance is greater than or equal to X, with respect to
the current cursor position.

• M // Print the Account Number with the highest balance, with respect to the current cursor position. If there is more than one account number with the same highest balance, print all numbers on one line separated by a single space, in increasing order.

• V X // Print the balance of Account Number X, with respect to the current cursor position.
