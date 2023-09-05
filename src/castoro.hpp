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

    // form handle bind
    std::map<std::string,   // slash command
        std::tuple<
            std::string,        // none
            form_event_func    // execute on_form
        >
    > form_events_func;

    public:    
    const static enum logging log = logging::ALL;
    castoro() = default;

    private:
    // bind new command
    // TODO: @MancioLollo: documentation
    /*
    */
    void bind_command(std::string command, std::string description, slash_event_func func, form_event_func form_func){
        // move func and description into slash_commands_func
        std::tuple<std::string, slash_event_func> desc_func{description, std::move(func)};
        slash_commands_func[command] = std::move(desc_func);
        
        // add form func
        std::tuple<std::string, form_event_func> desc_form_func{"", std::move(form_func)};
        form_events_func[command] = std::move(desc_form_func);
    }

    public:
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

    // TODO: @MancioLollo: documentation
    /*
    */
    template<class Class>
    void advanced_bind(){
        bind_command(Class::command, Class::description, Class::on_event, Class::on_form);
    }

    // TODO: @MancioLollo: documentation
    /*
    */
    void on_form_handle(cluster &bot, form_submit& event){
        for(auto &form_handler : form_events_func){
            std::get<1>(form_handler.second)(bot, event);
        }
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