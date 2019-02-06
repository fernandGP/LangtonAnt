#ifndef LANGTONANT_H
#define LANGTONANT_H

#include "definitions.h"
#include "ant.h"

    /**
    * @class LangtonAntDIDI
    * @brief The LangtonAnt class, our character in this little game, DIDI goes with BLACK WHITE BLUE RED
    * @author Fernando González Petit
    */

class LangtonAntDIDI : public Ant
{

public:
    LangtonAntDIDI(unsigned int x = DEF_ANT_X, unsigned int y = DEF_ANT_Y, unsigned int dir = 1,
               unsigned int xlim = DEF_BORDER_X, unsigned int ylim = DEF_BORDER_Y);
    ~LangtonAntDIDI();

    Color move(Color colorDeCuadrado);
    void paint() const;
};



#endif // LANGTONANT_H
