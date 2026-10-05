#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <span>
#include <sstream>

struct Transaction{
    std::string type;
    float amount = 0.0f;
    std::string description;
    std::string category;
    std::string date;


    void transactionCreator(const int,std::vector<Transaction>&);
    void printTransactionLog(std::span<Transaction>) const;
    void printAccountSummary(std::span<Transaction>) const;
    void printExpenseLog(std::span<Transaction>) const;
};

#endif