#include <iostream>
#include "image_menu.h"
#include <cmath>


void diagonalQuadPattern( ActionData& action_data ) {
    int height = getInteger( action_data, "Image height? " );
    int width = getInteger( action_data, "Image width? " );
    action_data.getInputImage1().setHeight( height );
    action_data.getInputImage1().setWidth( width );
    //?
    action_data.getInputImage1().setMaxColorValue( 255 );
    //?
    int row, col, red, blue, green;
    (void)row;
    (void)col;
    (void)red;
    (void)blue;
    (void)green;
    for ( row = 0; row < action_data.getInputImage1().getHeight(); row++ ) {
        for ( col = 0; col < action_data.getInputImage1().getWidth(); col++ ) {
            if ( col < (action_data.getInputImage1().getWidth()/2) ) {
                action_data.getInputImage1().setChannel( row, col, 2, 0 );
            }
            if ( col >= (action_data.getInputImage1().getWidth()/2) ) {
                action_data.getInputImage1().setChannel( row, col, 2, 255 );
            }
            if ( row < (action_data.getInputImage1().getHeight()/2) ) {
                action_data.getInputImage1().setChannel( row, col, 0, 0 );
            }
            if ( row >= (action_data.getInputImage1().getHeight()/2) ) {
                action_data.getInputImage1().setChannel( row, col, 0, 255 );
            }
            int green = ( 2*row + 2*col ) % 256;
            action_data.getInputImage1().setChannel( row, col, 1, green );
}}}


void stripedDiagonalPattern( ActionData& action_data ) {
    int height = getInteger( action_data, "Image height? " );
    int width = getInteger(action_data, "Image width? " );
    action_data.getInputImage1().setHeight( height );
    action_data.getInputImage1().setWidth( width );
    if ((action_data.getInputImage1().getHeight() + action_data.getInputImage1().getWidth()) / 3 < 255) {
        action_data.getInputImage1().setMaxColorValue(( action_data.getInputImage1().getHeight() + action_data.getInputImage1().getWidth() ) / 3);
    }
    else {
        action_data.getInputImage1().setMaxColorValue( 255 );
    }
    int row, col, red, blue, green;
    (void)row;
    (void)col;
    (void)red;
    (void)blue;
    (void)green;
    for ( row = 0; row < action_data.getInputImage1().getHeight(); row++ ) {
        for ( col = 0; col < action_data.getInputImage1().getWidth(); col++ ) {
            if ( row < (action_data.getInputImage1().getHeight()/2) ) {
                action_data.getInputImage1().setChannel( row, col, 0, 0 );
            }
            if ( row >= (action_data.getInputImage1().getHeight()/2) && (row % 3 == 0 )) {
                action_data.getInputImage1().setChannel( row, col, 0, 0 );
            }
            if ( row >= (action_data.getInputImage1().getHeight()/2) && !(row % 3 == 0)) {
                action_data.getInputImage1().setChannel( row, col, 0, action_data.getInputImage1().getMaxColorValue());
            }
            int green = (row + action_data.getInputImage1().getWidth() - col - 1) % (action_data.getInputImage1().getMaxColorValue()+1);
            action_data.getInputImage1().setChannel( row, col, 1, green );
            if ( col < row ) {
                action_data.getInputImage1().setChannel( row, col, 2, 0);
            }
            else {
                action_data.getInputImage1().setChannel( row, col, 2, action_data.getInputImage1().getMaxColorValue() );
            }
        }
    }
}

void fourSquarePattern( ActionData& action_data ) {
    int size = getInteger( action_data, "Image size? " );
    action_data.getInputImage1().setWidth( size );
    action_data.getInputImage1().setMaxColorValue( 100 );
    int row, col;
    for ( row = 0; row < action_data.getInputImage1().getHeight(); row++ ) {
        for ( col = 0; col < action_data.getInputImage1().getWidth(); col++ ) {
            if ( row < (action_data.getInputImage1().getHeight()/2) && col < (action_data.getInputImage1().getWidth()/2) ) {
                action_data.getInputImage1().setPixel( row, col, 100, 0, 66 );
            }
            if ( row >= (action_data.getInputImage1().getHeight()/2) && col >= (action_data.getInputImage1().getWidth()/2) ) {
                action_data.getInputImage1().setPixel( row, col, 33, 66, 0 );
            }
            
            if ( row < (action_data.getInputImage1().getHeight()/2) && col >= (action_data.getInputImage1().getWidth()/2) ) {
                action_data.getInputImage1().setPixel( row, col, 0, 100, 33 );
            }
            if ( row >= (action_data.getInputImage1().getHeight()/2) && col < (action_data.getInputImage1().getWidth()/2) ) {
                action_data.getInputImage1().setPixel( row, col, 66, 33, 100 );
            }
        }
    }
}


void setSize( ActionData& action_data ) {
    int height = getInteger( action_data, "Height? " );
    int width = getInteger( action_data, "Width? " );
    action_data.getInputImage1().setHeight( height );
    action_data.getInputImage1().setWidth( width );
}
void setMaxColorValue( ActionData& action_data ) {
    int maxcolorvalue = getInteger( action_data, "Max color value? " );
    action_data.getInputImage1().setMaxColorValue( maxcolorvalue );
}
void setChannel( ActionData& action_data ) {
    int row = getInteger( action_data, "Row? " );
    int col = getInteger( action_data, "Column? " );
    int channel = getInteger( action_data, "Channel? " );
    int value = getInteger( action_data, "Value? " );
    action_data.getInputImage1().setChannel( row, col, channel, value );
    
}
void setPixel( ActionData& action_data ) {
    int row = getInteger( action_data, "Row? " );
    int col = getInteger( action_data, "Column? " );
    int red = getInteger( action_data, "Red? " );
    int green = getInteger( action_data, "Green? " );
    int blue = getInteger( action_data, "Blue? " );
    action_data.getInputImage1().setPixel( row, col, red, green, blue );
}
void clearAll( ActionData& action_data ) {
    for (int row = 0; row < action_data.getInputImage1().getHeight(); row++ ) {
        for ( int col = 0; col < action_data.getInputImage1().getWidth(); col++ ) {
            action_data.getInputImage1().setPixel( row, col, 0, 0, 0 );
        }
    }
}

void drawCircle(ActionData& action_data) {
    double d;
    int center_row = getInteger( action_data, "Center Row? " );
    int center_column = getInteger( action_data, "Center Column? " );
    int radius = getInteger( action_data, "Radius? " );
    int red = getInteger( action_data, "Red? " );
    int green = getInteger( action_data, "Green? " );
    int blue = getInteger( action_data, "Blue? " );
    
    for ( int i = 0; i < action_data.getInputImage1().getHeight(); i++ ) {
        for ( int j = 0; j < action_data.getInputImage1().getWidth(); j++ ) {
            d = std::sqrt((i - center_row) * (i - center_row) + (j - center_column) * (j - center_column));
            if( d <= radius ) {
                action_data.getInputImage1().setPixel( i, j, red, green, blue );
            }
        }
    }
}
void drawBox(ActionData& action_data) {
    int top_row = getInteger( action_data, "Top Row? " );
    int left_column = getInteger( action_data, "Left Column? " );
    int bottom_row = getInteger( action_data, "Bottom Row? " );
    int right_column = getInteger( action_data, "Right Column? " );
    int red = getInteger( action_data, "Red? " );
    int green = getInteger( action_data, "Green? " );
    int blue = getInteger( action_data, "Blue? " );
    
    for ( int i = top_row; i <= bottom_row; i++ ) {
        for ( int j = left_column; j <= right_column; j++ ) {
            action_data.getInputImage1().setPixel( i, j, red, green, blue );
        }
    }
}

void drawSquare(ActionData& action_data) {
    int row = getInteger( action_data, "Row? " );
    int column = getInteger( action_data, "Column? " );
    int size = getInteger( action_data, "Size? " );
    int red = getInteger( action_data, "Red? " );
    int green = getInteger( action_data, "Green? " );
    int blue = getInteger( action_data, "Blue? " );
    (void)size;
    
    for ( int i = row - (size/2); i <= row + (size/2); i++ ) {
        for ( int j = column - (size/2); j <= column + (size/2); j++ ) {
            action_data.getInputImage1().setPixel( i, j, red, green, blue );
        }
    }
}


void configureGrid(ActionData& action_data) {
    int height = getInteger( action_data, "Grid Height? " );
    int width = getInteger( action_data, "Grid Width? " );
    int max_number = getInteger( action_data, "Grid Max Value? " );
    action_data.getGrid().setGridSize( height, width );
    action_data.getGrid().setMaxNumber( max_number );
}

void setGrid(ActionData& action_data) {
    int row = getInteger( action_data, "Grid Row? " );
    int column = getInteger( action_data, "Grid Column? " );
    int value = getInteger( action_data, "Grid Value? " );
    action_data.getGrid().setNumber( row, column, value );
}

void applyGrid(ActionData& action_data) {
    action_data.getGrid().setPPM( action_data.getOutputImage() );
}

void setColorTableSize(ActionData& action_data) {
    int size = getInteger( action_data, "Size? " );
    action_data.getTable().setNumberOfColors( size );
}

void setColor(ActionData& action_data) {
    int position = getInteger( action_data, "Position? " );
    int red = getInteger( action_data, "Red? " );
    int green = getInteger( action_data, "Green? " );
    int blue = getInteger( action_data, "Blue? " );
    action_data.getTable()[position].setRed( red );
      action_data.getTable()[position].setGreen( green );
      action_data.getTable()[position].setBlue( blue );
}

void setRandomColor(ActionData& action_data) {
    int position = getInteger( action_data, "Position? " );
    action_data.getTable().setRandomColor( 255, position );
}
void setColorGradient(ActionData& action_data) {
    int position1 = getInteger( action_data, "First position? " );
    int red1 = getInteger( action_data, "First red? " );
    int green1 = getInteger( action_data, "First green? " );
    int blue1 = getInteger( action_data, "First blue? " );
    int position2 = getInteger( action_data, "Second position? " );
    int red2 = getInteger( action_data, "Second red? " );
    int green2 = getInteger( action_data, "Second green? " );
    int blue2 = getInteger( action_data, "Second blue? " );
    Color color1(red1, green1, blue1);
    Color color2(red2, green2, blue2);
    action_data.getTable().insertGradient( color1, color2, position1, position2 );
}

void applyGridColorTable(ActionData& action_data) {
    action_data.getGrid().setPPM(action_data.getOutputImage(), action_data.getTable());
}

void setFractalPlaneSize(ActionData& action_data) {
    double min_x = getDouble( action_data, "Min X? " );
    double max_x = getDouble( action_data, "Max X? " );
    double min_y = getDouble( action_data, "Min Y? " );
    double max_y = getDouble( action_data, "Max Y? " );
    ComplexFractal *cf = dynamic_cast<ComplexFractal*>(&action_data.getGrid());

    if ( cf != 0 )
        cf->setPlaneSize( min_x, max_x, min_y, max_y );
    else
        action_data.getOS() << "Not a ComplexFractal object. Can’t set plane size.";
    
}

void calculateFractal(ActionData& action_data) {
    action_data.getGrid().calculateAllNumbers();
}

void setJuliaParameters(ActionData& action_data) {
    double a = getDouble( action_data, "Parameter a? " );
    double b = getDouble( action_data, "Parameter b? " );
    JuliaSet *js = dynamic_cast<JuliaSet*>(&action_data.getGrid());

    if ( js != 0 )
        js->setParameters( a, b );
    else
        action_data.getOS() << "Not a JuliaSet object. Can’t set parameters.";
}
/*
void setInvertedColorGradient(ActionData& action_data) {
    int pos1 = getInteger( action_data, "First position? " );
    double red1 = getDouble( action_data, "First red? " );
    double green1 = getDouble( action_data, "First green? " );
    double blue1 = getDouble( action_data, "First blue? " );
    int pos2 = getInteger( action_data, "Second position? " );
    Color gradient(red1, green1, blue1);
    action_data.getTable().insertInvertedGradient( gradient, pos1, pos2 );
}

void setMandelbrotPower( ActionData& action_data ) {
    double power = getDouble( action_data, "Power? " );
    MandelbrotPower *mp = dynamic_cast<MandelbrotPower*>(&action_data.getGrid());
    
    if ( mp != 0 )
        mp->setPower( power );
    else
        action_data.getOS() << "Not a MandelbrotPower object. Can’t set power.";
}*/

void calculateFractalSingleThread(ActionData& action_data) {
    action_data.getGrid().NumberGrid::calculateAllNumbers();
}

void setHueSaturationValueGradient(ActionData& action_data) {
    int pos1 = getInteger( action_data, "First position? ");
    double hue1 = getDouble( action_data, "First hue? ");
    double sat1 = getDouble( action_data, "First saturation? ");
    double val1 = getDouble( action_data, "First value? ");
    int pos2 = getInteger( action_data, "Second position? ");
    double hue2 = getDouble( action_data, "Second hue? ");
    double sat2 = getDouble( action_data, "Second saturation? ");
    double val2 = getDouble( action_data, "Second value? ");
    Color color1(hue1, sat1, val1);
    Color color2(hue2, sat2, val2);
    action_data.getTable().insertGradient( color1, color2, pos1, pos2 );
}
