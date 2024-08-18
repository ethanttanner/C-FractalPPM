#ifndef _ACTIONDATA_H_
#define _ACTIONDATA_H_
#include <iostream>
#include <map>
#include <string>
#include "PPM.h"
#include "Image.h"
#include "NumberGrid.h"
#include "ColorTable.h"
#include "ComplexFractal.h"
#include "JuliaSet.h"



class ActionData {
public:
    ActionData(std::istream& is, std::ostream& os);
    std::istream& getIS();
    std::ostream& getOS();
    PPM& getInputImage1();
    PPM& getInputImage2();
    PPM& getOutputImage();
    bool getDone() const;
    void setDone();
    ~ActionData();
    NumberGrid& getGrid();
    void setGrid(NumberGrid *grid);
    ColorTable& getTable();
    
private:
    std::istream& mIS;
    std::ostream& mOS;
    PPM input_image1;
    PPM input_image2;
    PPM output_image;
    bool done;
    NumberGrid *mNumberGrid;
    ColorTable mColorTable;
};

#endif // _ACTIONDATA_H_

