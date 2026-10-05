#include "../include/fileHandler.h"
#include "../include/transaction.h"

#include <iostream>

#define minOptionNum 1
#define maxOptionNum 8

enum transactionType{
    addIncome = 1      ,
    addExpense         ,
    viewAllTransactions,
    viewAccountSummary ,
    filterByCategory   ,
    saveToFile         ,
    loadFromFile       ,
    exitProgram
};

int main(void){
    int answer{0};
    Transaction t;
    std::vector<Transaction> transactionLog;

    do{ 
        std::cout << "=========================================================================" << std::endl;
        std::cout << "============= Welcome to the Personal Budgeting Tracker! ================" << std::endl;
        std::cout << "================ These are your menu options ============================" << std::endl;
        std::cout << "              > 1. Add Income to the record.    "                          << std::endl;
        std::cout << "              > 2. Add Expense to the record.   "                          << std::endl;
        std::cout << "              > 3. View All Transactions.       "                          << std::endl;
        std::cout << "              > 4. View summary of account.     "                          << std::endl;
        std::cout << "              > 5. Filter Expenses By Category. "                          << std::endl;
        std::cout << "              > 6. Save Record To File.         "                          << std::endl;
        std::cout << "              > 7. Load Record From File.       "                          << std::endl;
        std::cout << "              > 8. Exit the program.            "                          << std::endl;
        std::cout << "================ Please select an option from the menu ==================" << std::endl;
        std::cout << "=========================================================================" << std::endl;

        //typing the option needed(1-8)
        do{
            // while(true){
            //     if(std::cin >> answer) break;    
            //     std::cout << "Invalid input, try again!" << std::endl;
            //     std::cin.clear();
            //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            // }
            std::string line;
            while (std::getline(std::cin,line)){
                std::istringstream iss(line);
                
                char leftover;
                if(iss >> answer && !(iss >>leftover)) break;
                std::cerr << "Invalid input, try again!"<<std::endl;    
                std::cout << "=========================================================================" << std::endl;
                std::cout << "================ Please select an option from the menu ==================" << std::endl;
                std::cout << "=========================================================================" << std::endl;
            }
            if(answer<minOptionNum || answer>maxOptionNum) std::cout << "Wrong answer. Try again!" << std::endl;
            
        }while(answer<minOptionNum || answer>maxOptionNum);
        std::cout <<"You selected the option: ";


        //selecting one of the available options 
        switch(answer){
            case addIncome:
                std::cout << "\"income\"" << std::endl;
                t.transactionCreator(answer,transactionLog);
                break;
            case addExpense:
                std::cout << "\"expense\"" << std::endl;
                t.transactionCreator(answer,transactionLog);
                break;
            case viewAllTransactions:
                std::cout << "\"View Transaction\"" << std::endl;
                t.printTransactionLog(transactionLog);
                break;
            case viewAccountSummary:
                std::cout << "\"View Summary\"" << std::endl;
                t.printAccountSummary(transactionLog);
                break;
            case filterByCategory:
                std::cout << "\"Filter By Category\"" << std::endl;
                t.printExpenseLog(transactionLog);
                break;
            case saveToFile:
                std::cout << "\"Save To File\"" << std::endl;
                fileCreator(transactionLog);
                break;
            case loadFromFile:
                std::cout << "\"Load From File\"" << std::endl;
                fileLoader(transactionLog);
                break;        
            case exitProgram:
                std::cout << "\"Exit The Program\"" <<std::endl;
                return 0;
        }
    }while(true);
    return 0;
}