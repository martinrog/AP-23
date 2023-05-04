#include "Game.hpp"
#include <ctime>

Game::Game(std::string title, int releaseDate, float originalPrice) {
    this->title = title;
    this->releaseDate = releaseDate;
    this->originalPrice = originalPrice;
}

std::string Game::getTitle() {
    return title;
}

void Game::setTitle(std::string title) {
    this->title = title;
}

int Game::getReleaseDate() {
    return releaseDate;
}

void Game::setReleaseDate(int releaseDate) {
    this->releaseDate = releaseDate;
}

float Game::getOriginalPrice() {
    return originalPrice;
}

void Game::setOriginalPrice(float originalPrice) {
    this->originalPrice = originalPrice;
}


float Game::calculateCurrentPrice() {
    // Bepaal het aantal jaren dat is verstreken sinds de release van het spel
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    int yearsSinceRelease = currentYear - releaseDate;
    
    // Bereken de huidige prijs van het spel op basis van het aantal jaren sinds de release
    float currentPrice = originalPrice;
    for (int i = 0; i < yearsSinceRelease; i++) {
        currentPrice *= 0.7; // Verminder de prijs met 30% per jaar
    }
    
    return currentPrice;
}