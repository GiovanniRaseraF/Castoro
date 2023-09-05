/*
Authors: 
+ Giovanni Rasera : c++ code
+ Lorenzo Mancini : database and specifications

Links:
+ https://github.com/GiovanniRaseraF
+ https://github.com/MancioLollo
*/

#pragma once

#include <dpp/dpp.h>
#include <boost/algorithm/string.hpp>

#include <vector>
#include <string>
#include <functional>
#include <map>
#include <tuple>
#include <set>

// typedefs
typedef const dpp::slashcommand_t slash_command;
typedef dpp::cluster cluster;
typedef std::function<void(cluster&, slash_command&)> slash_event_func;

enum logging{
    ALL,
    NONE,
    DEBUG
};

class castoro {
    // slash commands 
    std::map<std::string,   // slash command
        std::tuple<
            std::string,        // command description 
            slash_event_func    // the function to execute
        >
    > slash_commands_func;

    public:    
    const static enum logging log = logging::ALL;
    castoro() = default;

    // bind new command
    // TODO: @MancioLollo: documentation
    /*
    */
    void bind_command(std::string command, std::string description, slash_event_func func){
        // move func and description into slash_commands_func
        std::tuple<std::string, slash_event_func> desc_func{description, std::move(func)};
        slash_commands_func[command] = std::move(desc_func);
    }

    // TODO: @MancioLollo: documentation
    /*
    */
    void handle(cluster& bot, slash_command& event){
        std::string command_string = event.command.get_command_name();
        bool last_reply = true;
        // check command available
        auto command_func = slash_commands_func.find(command_string);
        if(command_func != slash_commands_func.end()){
            try{
                // execute function binding 
                std::get<1>(command_func->second)(bot, event);
                last_reply = false;
            }catch(dpp::exception &ex){
                std::cerr << ex.what() << std::endl;

                if(castoro::log == ALL){
                    event.reply("@cetriolinogio @manciolollo / errore : " + std::string(ex.what()));
                    last_reply = false;
                }
            }
        }else{
            std::string response = "Il comando che hai inserito non esiste.";
            last_reply = false;
            event.reply(response);
        }

        if(last_reply) 
            event.reply("No handle per il comando");
    }

    // advertise commands
    // TODO: @MancioLollo: documentation
    /*
    */
    void advertise(cluster& bot){
        //if (dpp::run_once<struct register_bot_commands>()) {
            for(auto &slash_command : slash_commands_func){
                std::string command = slash_command.first;
                std::string description = std::get<0>(slash_command.second);

                bot.global_command_create(dpp::slashcommand(command, description, bot.me.id));
            }
        //}
    }
};