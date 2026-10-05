#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "../include/transaction.h"
#include "../include/fileHandler.h"

void fileCreator(std::vector<Transaction>& transactionLog){
    std::fstream budgetLog;
    std::string answer,n,fileName;
    
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    while(true){
        //no check for right answer here because I made it in line 26
        std::cout << "Would you like to name your budget tracker log?(yes - no)" <<std::endl;
        std::getline(std::cin,answer);

        if(toupper(answer.at(0)) == 'Y' &&toupper(answer.at(1)) == 'E' &&toupper(answer.at(2)) == 'S'){
            std::cout << "What is the name you want to give it?(No spaces)" << std::endl;
            std::getline(std::cin,fileName); 
            budgetLog.open(fileName+".csv",std::ios::out);
        }
        else if(toupper(answer.at(0))== 'N' && toupper(answer.at(1))== 'O'){
            budgetLog.open("file.csv",std::ios::out);
        }
        else{
            std::cout << "Try again!" <<std::endl;
            continue;
        } 
        //at this point I need to start putting the contents of the stransaction log to the CSV file
        if (budgetLog.is_open()){
            budgetLog << "type,amount,description,category,date" << std::endl; 
            for(const Transaction& log : transactionLog){
                budgetLog << log.type << "," 
                          << log.amount << ","
                          << log.description << ","
                          << log.category << "," 
                          << log.date << std::endl;
            }
        }
        break;    
    }   
}

void fileLoader(std::vector<Transaction>& transactionLog){

    for(const auto& entry : std::filesystem::directory_iterator(".")){
        if (entry.path().extension() != ".csv"){
            return;
        }
        std::ifstream f(entry.path());
        if(f.is_open()){
            std::string line;
            while(std::getline(f,line,',')){
                if(strcmp(line,"type") == 0 ||
                    strcmp(line,"amount") == 0 ||
                    strcmp(line,"description") == 0 ||
                    strcmp(line,"category") == 0 ||
                    strcmp(line,"date") == 0 ) 
                   continue;
                for(const Transaction& log : transactionLog){
                    log.type = line;
                    log.amount = line;
                    log.description = line;
                    log.category = line;
                    log.date = line; 
                }
            }
        } else std::cout << "File could not be read." << std::endl;
    }

}