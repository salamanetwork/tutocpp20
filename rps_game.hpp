#ifndef __RPS_GAME_H
#define __RPS_GAME_H

// Rock-Paper-Scissor Game

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

/* 
    Game Players:
        - 2 Players
    Game Rules:
        - Rock vs Scissor     ->  Rock wins
        - Rock vs Paper       ->  Paper wins
        - Paper vs Scissor    ->  Scissor wins
*/

std::string 
    player_01, 
    player_02; 

auto    
    player_01_choice = 10, 
    player_02_choice = 10;
    
bool 
    bad_choice = false;

enum Chois {
    Rock    = 10,
    Paper   = 20,
    Scissor = 30,
    None    = 0
};

std::string rps_game_get_input()
{
    std::string input;
    
    std::getline(cin, input);
    
    return input;
}

Chois rps_game_check(int uc)
{
    // int choice_randomize {1 + rand() % 3};
    
    // srand(time(NULL));
    
    int user_choice = uc;
    // clog << uc << endl;
    
    switch(user_choice)
    {
        case 10:
            user_choice = 10;
            
            return Rock;
            break;
        
        case 20:
            user_choice = 20;
            
            return Paper;
            break;
        
        case 30:
            user_choice = 30;
            
            return Scissor;
            break;
        
        default:
            return None;
            break;
        
    }
    
    return None;
}

void rps_game_check_message(Chois ch)
{
    if (ch == Rock)
        std::cout << "Your Choice is: Rock" << std::endl;
    else if (ch == Paper)
        std::cout << "Your Choice is: Paper" << std::endl;
    else if (ch == Scissor)
        std::cout << "Your Choice is: Scissor" << std::endl;
    else
    {
        bad_choice = true;
        std::cerr << "Bad Choice" << std::endl;
    }
    
}

void rps_game_apply_the_rules_and_get_the_winner
(
    int player_01_choice, 
    int player_02_choice, 
    std::string player_01, 
    std::string player_02
)
{
    /*
    Game Rules:
        - Rock vs Scissor     ->  Rock wins
        - Rock vs Paper       ->  Paper wins
        - Paper vs Scissor    ->  Scissor wins
    */
    // std::clog << "Log: " << player_01_choice << std::endl;
    // std::clog << "Log: " << player_02_choice << std::endl;
    
    
    if(player_01_choice == Rock) 
    {
        // std::clog << "Log: " << player_01_choice << std::endl;
        // std::clog << "Log: " << player_02_choice << std::endl;
    
        if(player_02_choice == Scissor)
            std::cout << player_01 << " is the WINNER!!!!!" << std::endl;
        else if(player_02_choice == Paper)
            std::cout << player_02 << " is the WINNER!!!!!" << std::endl;
        else
            bad_choice = true;
    }
    
    if(player_01_choice == Paper) 
    {
        // std::clog << "Log: " << player_01_choice << std::endl;
        // std::clog << "Log: " << player_02_choice << std::endl;
    
        if(player_02_choice == Scissor)
            std::cout << player_02 << " is the WINNER!!!!!" << std::endl;
        else if(player_02_choice == Rock)
            std::cout << player_01 << " is the WINNER!!!!!" << std::endl;
        else
            bad_choice = true;
    }
    
    if(player_01_choice == Scissor) 
    {
        // std::clog << "Log: " << player_01_choice << std::endl;
        // std::clog << "Log: " << player_02_choice << std::endl;
    
        if(player_02_choice == Rock)
            std::cout << player_02 << " is the WINNER!!!!!" << std::endl;
        else if(player_02_choice == Paper)
            std::cout << player_01 << " is the WINNER!!!!!" << std::endl;
        else
            bad_choice = true;
    }
    
    if(bad_choice)
    {
        std::cout << std::endl;
        std::cout << "!!!!!!BAD CHOICE!!!!!!" << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "!!!!!!*( Game Over )*!!!!!!" << std::endl;
    std::cout << std::endl;
    
}

void rps_game_play()
{
    std::cout << "Welcome to Rock-Paper-Scissor Game!!! / by: salamanetwork" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Please, Fill the information below." << std::endl;
    
    std::cout << "Player 1 name: ";
    player_01 = rps_game_get_input();
    
    std::cout << "Player 2 name: ";
    player_02 = rps_game_get_input();
    
    std::cout << std::endl;
    
    std::cout << "Welcome, " << player_01 << " && " << player_02 << std::endl;
    
    std::cout << std::endl;
    
    std::cout << player_01 << " choose your shape by number?" << "[ 10 = Rock, 20 = Paper, 30 = Scissor ] >> ";
    std::cin >> player_01_choice;
    rps_game_check_message((rps_game_check(player_01_choice)));
    // std::clog << "Log: " << player_01_choice << std::endl;
    
    std::cout << player_02 << " choose your shape by number?" << "[ 10 = Rock, 20 = Paper, 30 = Scissor ] >> ";
    std::cin >> player_02_choice;
    rps_game_check_message((rps_game_check(player_02_choice)));
    // std::clog << "Log: " << player_02_choice << std::endl;
    
    rps_game_apply_the_rules_and_get_the_winner
    (
        player_01_choice, 
        player_02_choice, 
        player_01, 
        player_02
    );
}


#endif














