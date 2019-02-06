#ifndef GRID_H
#define GRID_H
#include "definitions.h"
#include "langtonant.h"

/**
 * @class grid
 * @brief The grid class, meant to be a unidimensional matrix m_ x n_
 * @author Fernando González Petit
 */

class grid
{
private:
    unsigned int m_;                            ///<@brief number of rows
    unsigned int n_;                            ///<@brief number of columns
    std::vector<unsigned int> slots_;           ///<@brief our matrix, beautifully implemented

public:
    grid(const unsigned int m = DEF_BORDER_X, const unsigned int n = DEF_BORDER_X, const unsigned int opt = DEFAULT_GRID);
    ~grid();

    unsigned int getM() const;
    unsigned int getN() const;

    void repaint(const std::vector<Ant*>& hormigas);
    void reset();

//protected:
    unsigned int rpos(unsigned int i, unsigned int j) const;
    Color pos(unsigned int i, unsigned int j) const;
    void setPos(unsigned int i, unsigned int j, Color val);
};

#endif // GRID_H
