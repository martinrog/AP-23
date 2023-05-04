#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <list>
#include "Game.hpp"

class Person {
private:
    float budget;
    std::string name;
    std::list<Game> games;

public:
    Person( std::string name,float budget);
    bool buy(Game game);
    bool sell(Game game, Person& buyer);
    float getBudget();
    void setBudget(float budget);
    std::list<Game> getGames();
    void setGames(std::list<Game> games);
    void addGame(Game game);
    void removeGame(Game game);
    std::string getName();
    void setName(std::string name);
};

#endif /* PERSON_H */