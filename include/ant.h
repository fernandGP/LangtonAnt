#ifndef ANT_H
#define ANT_H

#include "definitions.h"

/**
 * @class Ant
 * @brief The Ant class, mother of all ants.
 * @author Fernando González Petit
 */

class Ant{

protected:
    unsigned int yPos_;
    unsigned int xPos_;
    unsigned int direction_;

    unsigned int xLimit_;
    unsigned int yLimit_;

public:

    Ant(unsigned int x = DEF_ANT_X, unsigned int y = DEF_ANT_Y, unsigned int dir = 1,
        unsigned int xlim = DEF_BORDER_X, unsigned int ylim = DEF_BORDER_Y);
    virtual ~Ant();

    unsigned int getX() const;
    unsigned int getY() const;
    unsigned int getDir() const;

    virtual void paint() const = 0;
    virtual Color move(Color colorDeCuadrado) = 0;

    bool operator<(const Ant* &hormigaDer);

};

#endif // ANT_H
