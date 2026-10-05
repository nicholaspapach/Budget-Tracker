#include "../include/transaction.h"
#include "../include/fileHandler.h"

#include <iostream>
#include <cstring>

void Transaction::transactionCreator(const int transactionType,std::vector<Transaction>& transactionLog){
    Transaction t;
    if (transactionType == 1) t.type = "Income";
    else if (transactionType == 2) t.type = "Expense";

    std::cout << "Type amount of money for transaction." << std::endl;
    std::string line;
    while (std::getline(std::cin,line)){
        std::istringstream iss(line);
                
        char leftover;
        if(iss >> t.amount && !(iss >>leftover)) break;
        std::cerr << "Invalid input, try again!"<<std::endl;    
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Type description of transaction." << std::endl;
    std::getline(std::cin,t.description);

    if (transactionType == 1)std::cout << "Type category of transaction. It has to be one of the following:\n> Salary\n> Rent\n> Other" << std::endl;
    if (transactionType == 2)std::cout << "Type category of transaction. It has to be one of the following:\n> Food\n> Transport\n> Entertainment\n> Bills\n> Other" << std::endl;
    do{
        std::getline(std::cin,t.category);
    }while(t.category != "Food" && 
           t.category != "Transport" && 
           t.category != "Entertainment" && 
           t.category != "Bills" && 
           t.category != "Other" &&
           t.category != "Salary" &&
           t.category != "Rent"); 
    

    std::cout << "Type the date of the transaction." << std::endl;
    std::getline(std::cin,t.date);

    transactionLog.push_back(t);
}

void Transaction::printTransactionLog(std::span<Transaction> transactionLog) const{
    if(transactionLog.empty()){
        std::cout << "The logs are empty." <<std::endl;
        return;
    }
    int i = 1;
    for(const Transaction& log : transactionLog){
        std::cout << "=========================================================================" << std::endl;
        std::cout << "========= The transaction number " << i << " has the following information ========" << std::endl;
        std::cout << "Type        : " << log.type << std::endl; 
        std::cout << "Amount      : " << log.amount << std::endl;
        std::cout << "Description : " << log.description << std::endl;
        std::cout << "Category    : " << log.category << std::endl;
        std::cout << "Date        : " << log.date << std::endl;
        i++;
    }
}

void Transaction::printAccountSummary(std::span<Transaction> transactionLog) const{
    float totalIncome = 0.0f, totalExpenses = 0.0f,currentBalance = 0.0f;
    if(transactionLog.empty()){
        std::cout << "Your total income is " << totalIncome << "$" << std::endl;
        std::cout << "Your total Expenses are " << totalExpenses << "$" << std::endl;
        std::cout << "Your current balance is " << currentBalance << "$" << std::endl;
        return;
    }

    
    for(const Transaction& log : transactionLog){
        if(log.type == "Income") totalIncome += log.amount;
        else if(log.type == "Expense") totalExpenses += log.amount;
    }
    currentBalance = totalIncome - totalExpenses;

    std::cout << "Your total income is " << totalIncome << "$" << std::endl;
    std::cout << "Your total Expenses are " << totalExpenses << "$" << std::endl;
    std::cout << "Your current balance is " << currentBalance << "$" << std::endl;
    if(currentBalance < 0) std::cout << "You are in trouble mister!!!!" << std::endl;
}

void Transaction::printExpenseLog(std::span<Transaction> transactionLog) const{
    if(transactionLog.empty()){
        std::cout << "The logs are empty." <<std::endl;
        return;
    }
    int i = 0;
    std::string answer;
    std::cout << "Enter what category of expenses you want to filter:\n> Food\n> Transport\n> Entertainment\n> Bills\n> Other" << std::endl;
    std::cin >> answer;
    for(const Transaction& log : transactionLog){
        if(log.type != "Expense") continue;
        if (answer != log.category) continue;
        std::cout << "=========================================================================" << std::endl;
        std::cout << "========= The transaction number " << i+1 << " has the following information ========" << std::endl;
        std::cout << "Type        : " << log.type << std::endl; 
        std::cout << "Amount      : " << log.amount << std::endl;
        std::cout << "Description : " << log.description << std::endl;
        std::cout << "Category    : " << log.category << std::endl;
        std::cout << "Date        : " << log.date << std::endl;
        i++;
    }
    if(i == 0) std::cout << "no expenses with the filter \"" << answer <<"\" have been found." << std::endl;
}