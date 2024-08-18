#include "ActionData.h"
#include <iostream>


ActionData::ActionData(std::istream& is, std::ostream& os) : mIS( is ), mOS( os ), done( false ), mNumberGrid( 0 ), mColorTable( 16 ) {
    Color color1(0, 255, 0);
    Color color2( 255, 0, 255 );
    mColorTable.insertGradient( color1, color2, 0, 15 );
}

ActionData::~ActionData() {
    if ( mNumberGrid != 0 )  {
        delete mNumberGrid;
        mNumberGrid = 0;
    }
}

std::istream& ActionData::getIS() {
    return mIS;
}

std::ostream& ActionData::getOS() {
    return mOS;
}


PPM& ActionData::getInputImage1() {
    return input_image1;
}
    
PPM& ActionData::getInputImage2(){
    return input_image2;
}
    
PPM& ActionData::getOutputImage() {
    return output_image;
}

bool ActionData::getDone() const {
    return done;
}

void ActionData::setDone() {
    done = true;
}


NumberGrid& ActionData::getGrid() {
    return *mNumberGrid;
}

void ActionData::setGrid(NumberGrid *grid) {
    if ( mNumberGrid != 0 ) {
        delete mNumberGrid;
        mNumberGrid = grid;
    }
    else {
        mNumberGrid = grid;
    }
}

ColorTable& ActionData::getTable() {
    return mColorTable;
}
