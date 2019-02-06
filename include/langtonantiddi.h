#ifndef LANGTONANTIDDI_H
#define LANGTONANTIDDI_H

#include "definitions.h"
#include "ant.h"

/**
* @class LangtonAntIDDI
* @brief The LangtonAnt class, our character in this little game, IDDI goes with BLACK WHITE BLUE RED
* @author Fernando González Petit
*/

class LangtonAntIDDI : public Ant
{
public:
    LangtonAntIDDI(unsigned int x = DEF_ANT_X, unsigned int y = DEF_ANT_Y, unsigned int dir = 1,
               unsigned int xlim = DEF_BORDER_X, unsigned int ylim = DEF_BORDER_Y);
    ~LangtonAntIDDI();

    Color move(Color colorDeCuadrado);
    void paint() const;
};

#endif // LANGTONANTIDDI_H
