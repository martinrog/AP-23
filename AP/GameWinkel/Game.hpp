#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
private:
    std::string title;
    int releaseDate;
    float originalPrice;

public:
    Game(std::string title, int releaseDate, float originalPrice);
    std::string getTitle();
    void setTitle(std::string title);
    int getReleaseDate();
    void setReleaseDate(int releaseDate);
    float getOriginalPrice();
    void setOriginalPrice(float originalPrice);
    float calculateCurrentPrice();
};

#endif /* GAME_H */