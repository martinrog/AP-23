#include "Person.hpp"
#include <iostream>

Person::Person(std::string name, float budget) {
    this->budget = budget;
    this->name = name;
}

bool Person::buy(Game game) {
    float price = game.calculateCurrentPrice();
    if (price > budget) {
        std::cout << getName() << " buys " << game.getTitle() << ": failed" << std::endl;
        return false;
    }
    
    budget -= price;
    games.push_back(game);
    
    std::cout << getName() << " buys " << game.getTitle() << ": success" << std::endl;
    
    return true;
}

bool Person::sell(Game game, Person& buyer) {
    float price = game.calculateCurrentPrice();
    if (!std::count(games.begin(), games.end(), game)) {
        std::cout << getName() << " sells " << game.getTitle() << " to " << buyer.getName() << ": failed" << std::endl;
        return false;
    }
    if (!buyer.buy(game)) {
        std::cout << getName() << " sells " << game.getTitle() << " to " << buyer.getName() << ": failed" << std::endl;
        return false;
    }
    
    budget += price;
    games.remove(game);
    
    std::cout << getName() << " sells " << game.getTitle() << " to " << buyer.getName() << ": success" << std::endl;
    
    return true;
}

float Person::getBudget() {
    return budget;
}

void Person::setBudget(float budget) {
    this->budget = budget;
}

std::list<Game> Person::getGames() {
    return games;
}

void Person::setGames(std::list<Game> games) {
    this-> games = games;
}