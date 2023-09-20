/*
Authors: 
+ Giovanni Rasera : c++ code
+ Lorenzo Mancini : database and specifications

Links:
+ https://github.com/GiovanniRaseraF
+ https://github.com/MancioLollo
*/

#pragma once

#include "commands/command.hpp"

#include <pqxx/pqxx>

class castorodb {
    private:
    static std::string dbname;
    static std::string hostaddr;
    static std::string user;
    static std::string password;

    public:
    // TODO: @MancioLollo: documentation
    /*
    */
    static std::vector<std::string> list_bros(){
        std::string con_string = 
        " user="        + user +
        " password="    + password +
        " host="        + hostaddr +
        " port=5432 "   + 
        " dbname="      + dbname;

        std::vector<std::string> ret{};

        pqxx::connection c{con_string};
        pqxx::work txn{c};

        for(auto row : txn.exec("select * from castorodb.bro;")){
            std::string nome = (row["nome"].as<std::string>());

            ret.push_back(nome);
        }

        return ret;
    }
};

std::string castorodb::dbname   {"postgres"};
std::string castorodb::hostaddr {"localhost"};
std::string castorodb::user     {"postgres"};
std::string castorodb::password {"fdsa"};