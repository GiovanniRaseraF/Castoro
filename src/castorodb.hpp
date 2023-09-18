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
        std::vector<std::string> ret{};

        // pqxx::connection c{""};
        // pqxx::work txn{c};

        // for(auto row : txn.exec("SELECT nome FROM bro")){
        //     std::string nome = (row["nome"].as<std::string>());

        //     ret.push_back(nome);
        //     std::cout << nome << std::endl;
        // }

        return ret;
    }
};