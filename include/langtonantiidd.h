#ifndef LANGTONANTIIDD_H
#define LANGTONANTIIDD_H

#include "definitions.h"
#include "ant.h"

/**
* @class LangtonAntIIDD
* @brief The LangtonAnt class, our character in this little game, IIDD goes with BLACK WHITE BLUE RED
* @author Fernando González Petit
*/

class LangtonAntIIDD : public Ant
{
public:
    LangtonAntIIDD(unsigned int x = DEF_ANT_X, unsigned int y = DEF_ANT_Y, unsigned int dir = 1,
               unsigned int xlim = DEF_BORDER_X, unsigned int ylim = DEF_BORDER_Y);
    ~LangtonAntIIDD();

    Color move(Color colorDeCuadrado);
    void paint() const;
};

#endif // LANGTONANTIIDD_H
