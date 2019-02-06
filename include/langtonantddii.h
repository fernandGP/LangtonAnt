#ifndef LANGTONANTDDII_H
#define LANGTONANTDDII_H

#include "definitions.h"
#include "ant.h"

/**
* @class LangtonAntDDII
* @brief The LangtonAnt class, our character in this little game, DDII goes with BLACK WHITE BLUE RED
* @author Fernando González Petit
*/

class LangtonAntDDII : public Ant
{
public:
    LangtonAntDDII(unsigned int x = DEF_ANT_X, unsigned int y = DEF_ANT_Y, unsigned int dir = 1,
               unsigned int xlim = DEF_BORDER_X, unsigned int ylim = DEF_BORDER_Y);
    ~LangtonAntDDII();

    Color move(Color colorDeCuadrado);
    void paint() const;
};

#endif // LANGTONANTDDII_H
