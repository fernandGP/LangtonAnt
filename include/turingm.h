#ifndef TURINGM_H
#define TURINGM_H

#include "langtonant.h"
#include "langtonantddii.h"
#include "langtonantiidd.h"
#include "langtonantiddi.h"
#include "grid.h"

/**
 * @class TuringM
 * @brief The TuringM class, ruler of all ants living in grids
 * @author Fernando González Petit
 */

class TuringM
{
private:
    grid Malla_;
    std::vector<Ant*> Hormigas_;

public:
    TuringM(unsigned int i = DEF_BORDER_X, unsigned int j = DEF_BORDER_Y, unsigned int mod = DEFAULT_GRID);
    ~TuringM();

    std::vector<Ant*> getAnts() const;

    void showGrid();
    void reset();
    void swapSquare(unsigned int i, unsigned int j, Color color);       //Recibe color, por el que cambia dicha posicion

    void NextStatus();
    void Actualize();

    static unsigned int Pasos_;

private:
    void quicksortAnts();
};

#endif // TURINGM_H
