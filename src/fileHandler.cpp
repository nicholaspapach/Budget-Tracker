#include <iostream>
#include <fstream>

#include "../include/transaction.h"
#include "../include/fileHandler.h"

void fileCreator(std::vector<Transaction>& transactionLog){
    std::fstream budgetLog;
    std::string answer,n,fileName;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Would you like to name your budget tracker log?(y - n)" <<std::endl;
    std::getline(std::cin,answer);

    if(toupper(answer.at(0)) == 'Y'){
        std::cout << "What is the name you want to give it?(No spaces)" << std::endl;
        std::getline(std::cin,fileName); 
        budgetLog.open(fileName,std::ios::out);
    }
    else if(toupper(answer.at(0))== 'N'){
        budgetLog.open("file.txt",std::ios::out);
    }
    else 
        std::cout << "Try again!" <<std::endl;

    //at this point I need to start putting the contents of the stransaction log to the CSV file
}

void fileLoader(std::vector<Transaction>& transactionLog){


}