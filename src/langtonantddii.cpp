#include "../include/langtonantddii.h"

LangtonAntDDII::LangtonAntDDII(unsigned int x, unsigned int y, unsigned int dir, unsigned int xlim, unsigned int ylim):
                Ant(x, y, dir, xlim, ylim) {}

LangtonAntDDII::~LangtonAntDDII(){}

Color LangtonAntDDII::move(Color colorDeCuadrado){
    if(colorDeCuadrado == Blanco){
       //Blanco ' ', mueve 90º a la derecha           R
        switch (direction_) {
        case 0: //Up goes right
            direction_ = 3;
            if((yPos_ + 1) > yLimit_){
                yPos_ = 1;
            }
            else yPos_++;
            break;
        case 1: //Down goes left
            direction_ = 2;
            if((yPos_ - 1) < 1){
                yPos_ = yLimit_;
            }
            else yPos_--;
            break;
        case 2: //Left goes up
            direction_ = 0;
            if((xPos_ - 1) < 1){
                xPos_ = xLimit_;
            }
            else xPos_--;
            break;
        case 3: //Right goes down
            direction_ = 1;
            if((xPos_ + 1) > xLimit_){
                xPos_ = 1;
            }
            else xPos_++;
            break;
        default:
            throw oobantexception();
            break;
        }
        return Azul;
    }
    else if(colorDeCuadrado == Negro){
       //Negro 'x', mueve 90º a la derecha                   R
        switch (direction_) {
        case 0: //Up goes right
            direction_ = 3;
            if((yPos_ + 1) > yLimit_){
                yPos_ = 1;
            }
            else yPos_++;
            break;
        case 1: //Down goes left
            direction_ = 2;
            if((yPos_ - 1) < 1){
                yPos_ = yLimit_;
            }
            else yPos_--;
            break;
        case 2: //Left goes up
            direction_ = 0;
            if((xPos_ - 1) < 1){
                xPos_ = xLimit_;
            }
            else xPos_--;
            break;
        case 3: //Right goes down
            direction_ = 1;
            if((xPos_ + 1) > xLimit_){
                xPos_ = 1;
            }
            else xPos_++;
            break;
        default:
            throw oobantexception();
            break;
        }
        return Blanco;
    }
    else if(colorDeCuadrado == Azul){
        //Azul 'A', mueve 90º a la izquierda               L
        switch (direction_) {
        case 0: //Up goes left
            direction_ = 2;
            if((yPos_ - 1) < 1){
                yPos_ = yLimit_;
            }
            else yPos_--;
            break;
        case 1: //Down goes right
            direction_ = 3;
            if((yPos_ + 1) > yLimit_){
                yPos_ = 1;
            }
            else yPos_++;
            break;
        case 2: //Left goes down
            direction_ = 1;
            if((xPos_ + 1) > xLimit_){
                xPos_ = 1;
            }
            else xPos_++;
            break;
        case 3: //Right goes up
            direction_ = 0;
            if((xPos_ - 1) < 1){
                xPos_ = xLimit_;
            }
            else xPos_--;
            break;
        default:
            throw oobantexception();
            break;
        }
        return Rojo;
    }
    else if(colorDeCuadrado == Rojo){
        //Rojo ' ', mueve 90º a la izquierda           L
         switch (direction_) {
         case 0: //Up goes left
             direction_ = 2;
             if((yPos_ - 1) < 1){
                 yPos_ = yLimit_;
             }
             else yPos_--;
             break;
         case 1: //Down goes right
             direction_ = 3;
             if((yPos_ + 1) > yLimit_){
                 yPos_ = 1;
             }
             else yPos_++;
             break;
         case 2: //Left goes down
             direction_ = 1;
             if((xPos_ + 1) > xLimit_){
                 xPos_ = 1;
             }
             else xPos_++;
             break;
         case 3: //Right goes up
             direction_ = 0;
             if((xPos_ - 1) < 1){
                 xPos_ = xLimit_;
             }
             else xPos_--;
             break;
         default:
             throw oobantexception();
             break;
         }
        return Negro;
    }
    else{
        throw oobantexception();
    }
}

void LangtonAntDDII::paint() const {
    switch (direction_) {
    case 0:     //UP
        std::cout << " w " ;
        break;
    case 1:     //DOWN
        std::cout << " a " ;
        break;
    case 2:     //LEFT
        std::cout << " s " ;
        break;
    case 3:     //RIGHT
        std::cout << " d " ;
        break;
    default:
        throw oobantexception();
        break;
    }
}
