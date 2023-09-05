/*
Authors: 
+ Giovanni Rasera : c++ code
+ Lorenzo Mancini : database and specifications

Links:
+ https://github.com/GiovanniRaseraF
+ https://github.com/MancioLollo
*/

#pragma once

#include "./command.hpp"

struct new_story {
    // slash command
    static std::string command;

    // description
    static std::string description;

    // custom_modal_id
    static std::string my_custom_modal_id;

    // func
    static void on_event(cluster &bot, slash_command &event){
        dpp::interaction_modal_response modal("my_new_story_modal", "Crea una nuova storia");
 
        modal.add_component(
            dpp::component().
                set_label("Titolo").
                set_id("my_story_title_id").
                set_type(dpp::cot_text).
                set_placeholder("Inserisci un titolo").
                set_min_length(0).
                set_max_length(500). // is in database documentation
                set_text_style(dpp::text_short)
        );
        modal.add_row();
        modal.add_component(
            dpp::component().
                set_label("Anno").
                set_id("my_story_year_id").
                set_type(dpp::cot_text).
                set_placeholder("In quale anno").
                set_min_length(0).
                set_max_length(4).
                set_text_style(dpp::text_short)
        );
        modal.add_row();
        modal.add_component(
            dpp::component().
                set_label("Mese").
                set_id("my_story_month_id").
                set_type(dpp::cot_text).
                set_placeholder("In quale mese").
                set_min_length(0).
                set_max_length(2).
                set_text_style(dpp::text_short)
        );
        modal.add_row();
        modal.add_component(
            dpp::component().
                set_label("Storia").
                set_id("my_story_story_id").
                set_type(dpp::cot_text).
                set_placeholder("Inserisci la storia").
                set_min_length(0).
                set_max_length(MAX_DPP_TEXT_LEN).
                set_text_style(dpp::text_paragraph)
        );
 
        event.dialog(modal);
    }

    static void on_form(cluster &bot, form_submit& event){
        std::string custom_modal_id = event.custom_id;

        // filter by custom modal id
        if(custom_modal_id == my_custom_modal_id){
            // TODO: implemente parser and add to database
            event.reply(custom_modal_id);
        }else{
            // TODO: set flags to notify success to avoid double response
            return;
        }
    }
};

// init
std::string new_story::command{"new"};
std::string new_story::description{"Crea una nuova storia"};
std::string new_story::my_custom_modal_id{"my_new_story_modal"};