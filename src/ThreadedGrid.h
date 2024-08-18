#ifndef _THREADEDGRID_H_
#define _THREADEDGRID_H_
#include "NumberGrid.h"
#include "ThreadedVector.h"

class GridTask {
public:
  GridTask( unsigned int row );
  unsigned int mRow;
};

class ThreadedGrid : public NumberGrid    {
public:
    ThreadedGrid();
    ThreadedGrid(const int& height, const int& width);
    virtual ~ThreadedGrid();
    virtual void calculateAllNumbers();
    virtual void worker();
    
protected:
    ThreadedVector<GridTask> queue;
};

#endif // _THREADEDGRID_H_
