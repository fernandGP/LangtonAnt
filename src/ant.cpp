#include "../include/ant.h"

Ant::Ant(unsigned int x, unsigned int y, unsigned int dir, unsigned int xlim, unsigned int ylim){

    xPos_ = x;
    yPos_ = y;
    direction_ = dir;
    xLimit_ = xlim;
    yLimit_ = ylim;

}

Ant::~Ant(){}

unsigned int Ant::getX() const { return xPos_; }

unsigned int Ant::getY() const { return yPos_; }

unsigned int Ant::getDir() const { return direction_; }

bool Ant::operator<(const Ant* &hormigaDer){

    return ((this -> xPos_ > hormigaDer -> xPos_) ||
            (hormigaDer -> xPos_ == this -> xPos_ && this -> yPos_ > hormigaDer -> yPos_)) ? true : false;

}
