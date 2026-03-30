// Basketball Player Streaks
// Write a program that analyzes recent game scoring for a basketball team.
//
// Rules and Specifications:
// 1) Ask the user for the number of players they want to analyze. This
//    will control your outer loop.
// 2) For each player, prompt for their points scored in their last 5 games.
//    Use an inner loop to collect these 5 scores.
// 3) Calculate and display the player's average points over those 5 games.
// 4) Count and display how many of those games were "high scoring" games
//    where the player scored 20 or more points.
//
// Example:
//
// Computer: How many players to analyze?
// User: 2
// Computer: Enter scores for Player 1:
// User: 15 22 18 25 30
// Computer: Player 1 Average: 22.0. High scoring games: 3
// Computer: Enter scores for Player 2:
// User: 10 12 15 8 11
// Computer: Player 2 Average: 11.2. High scoring games: 0

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

void ignoreLine();
bool recoverStream();
int getInteger(const std::string& prompt);

const int GAMES{5};
const int HIGH_SCORE_MIN{20};

int main()
{
    int players{getInteger("How many players to analyze? ")};

    while (players == 0)
    {
        std::cout << "Enter at least 1 player.\n";
        players = getInteger("How many players to analyze? ");
    }

    std::cout << std::fixed << std::setprecision(1);

    for (int i{1}; i <= players; ++i)
    {
        double totalPoints{};
        int highScoringGames{};

        std::cout << "Enter scores for Player " << i << '\n';

        for (int j{1}; j <= GAMES; ++j)
        {
            std::string prompt{"score (" + std::to_string(j) + "/" + std::to_string(GAMES) + "): "};

            int score{getInteger(prompt)};

            if (score >= HIGH_SCORE_MIN)
            {
                ++highScoringGames;
            }

            totalPoints += score;
        }

        double average{totalPoints / GAMES};

        std::cout << "Player " << i << " Average: " << average
                  << ". High scoring games: " << highScoringGames << '\n';
    }

    return 0;
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool recoverStream()
{
    if (!std::cin)
    {
        if (std::cin.eof())
        {
            std::exit(1);
        }

        std::cin.clear();
        ignoreLine();
        return true;
    }

    return false;
}

int getInteger(const std::string& prompt)
{
    while (true)
    {
        int x{};
        std::cout << prompt;
        std::cin >> x;

        if (recoverStream() || x < 0)
        {
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        return x;
    }
}
