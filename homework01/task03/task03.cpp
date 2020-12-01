#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

std::string position_memory[8];
int points = 0;
bool continue_app = false;
int counter;

//Difficulty easy = 0, 4; medium = 1, 6, hard = 2, 8
void position(int diff, int options)
{
    srand(time(NULL)); //initialize the random seed
    int random_num = rand() % options;
    const std::string pos[3][8] =
    {
        { "up", "left", "down", "right" },
        { "up", "left", "down", "right", "right-up", "left-up" },
        { "up", "left", "down", "right", "right-up", "left-up","right-down","left-down"}
    };
    position_memory[counter] = pos[diff][random_num];
    std::cout <<"Simon says " << pos[diff][random_num];
    counter++;
}

void sleep(int milliseconds)
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end);
    system("CLS");
}

//int repeat(int options)
//{
//    switch (options)
//    {
//    case 4: easy();
//        break;
//    case 6:medium();
//        break;
//    case 8:hard();
//        break;
//    }
//    return 0;
//}

void guess()
{
    std::string again;
    bool success = true;
    std::string temp[64];
    for (int i = 0; i < 3 + points; i++)
    {
        std::cin >> temp[i];
    }
    for (int i = 0; i < 3 + points; i++)
    {
        if (position_memory[i] != temp[i])
        {
            success = false;
            break;
        }
    }
    if (success)
    {
        std::cout << "Congrats! That's correct! You have " << ++points << " up to now. Continue? (Yes/No) ";
        std::cin >> again;
        again == "Yes" ? continue_app = true : NULL;
    }
    else
    {
        std::cout << "Sorry, you lost! You had " << points << " point before you lost.";
    }
}

void easy()
{
    for (int j = 0; j < 3 + points; j++)
    {
        position(0, 4);
        sleep(1000);
    } 
    std::cout << "Now it's your turn!" << std::endl;
    guess();
}
void medium()
{
    for (int j = 0; j <= 3 + points; j++)
    {
        position(1, 6);
        sleep(500);
    }
    std::cout << "Now it's your turn!" << std::endl;
    guess();
}
void hard()
{
    for (int j = 0; j <= 3 + points; j++)
    {
        position(2, 8);
        sleep(250);
    }
    std::cout << "Now it's your turn!" << std::endl;
    guess();
}

int main()
{   
    std::string difficulty;
    std::cin >> difficulty;

    if (difficulty == "easy")
    {
        std::cout << "Starting \"easy\" mode.You will have 4 states(up, left, down, right) and a period of 1 sec to look at the answers." << std::endl;
        easy();
        while (continue_app)
        {
            counter = 0;
            continue_app = false;
            easy();
        }
    }
    else if (difficulty == "medium")
    {
        std::cout << "Starting \"medium\" mode.You will have 4 states(up, left, down, right, right-up, left-up) and a period of 0.5 sec to look at the answers." << std::endl;
        medium();
        while (continue_app)
        {
            counter = 0;
            continue_app = false;
            medium();
        }
    }
    else if (difficulty == "hard")
    {
        std::cout << "Starting \"hard\" mode.You will have 4 states(up, left, down, right, right-up, left-up, right-down, left-down) and a period of 0.25 sec to look at the answers." << std::endl;
        hard();
        while (continue_app)
        {
            counter = 0;
            continue_app = false;
            hard();
        }
    }
    else
    {
        std::cout << "Enter valid difficulty" << std::endl;
    }
    return 0;
}