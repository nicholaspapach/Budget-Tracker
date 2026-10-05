# Project 1: Personal Budget Tracker

### Description
A console-based application that helps users track their income and expenses. Users can add transactions, categorize them, view summaries, and save/load data from a file.

### Features to Implement
1. **Add Income** - Record money received with description, amount, and date
2. **Add Expense** - Record spending with description, amount, category, and date
3. **View All Transactions** - Display a formatted list of all transactions
4. **View Summary** - Show total income, total expenses, and current balance
5. **Filter by Category** - View expenses by category (Food, Transport, Entertainment, Bills, Other)
6. **Save to File** - Persist data to a text/CSV file
7. **Load from File** - Read saved data when program starts

### C++ Concepts You'll Learn
| Concept | How It's Used |
|---------|---------------|
| Variables & Data Types | Store amounts (double), descriptions (string), dates (string) |
| Structs/Classes | Create a `Transaction` structure to hold transaction data |
| Vectors | Store multiple transactions in `std::vector<Transaction>` |
| Loops | Iterate through transactions for display and calculations |
| Conditionals | Filter transactions, validate user input |
| Functions | Separate logic into reusable functions |
| File I/O | Use `fstream` to read/write transaction data |
| Enums | Define transaction categories |
| Input Validation | Handle invalid user input gracefully |

### Suggested File Structure
```
budget_tracker/
├── main.cpp           # Entry point, main menu loop
├── transaction.h      # Transaction struct/class definition
├── transaction.cpp    # Transaction implementation
├── file_handler.h     # File save/load function declarations
├── file_handler.cpp   # File save/load implementations
└── data.csv           # Saved transaction data
```

### Implementation Steps
1. Start with a simple menu system using `switch` or `if-else`
2. Create a `Transaction` struct with fields: `type`, `amount`, `description`, `category`, `date`
3. Use a `std::vector<Transaction>` to store all transactions in memory
4. Implement add functions first, then display, then file I/O last

### Sample Data Format (CSV)
```
type,amount,description,category,date
income,2500.00,Salary,,2026-03-01
expense,45.50,Groceries,Food,2026-03-02
expense,30.00,Bus pass,Transport,2026-03-03
```

### Difficulty Level
Beginner | Estimated Time: 4-6 hours