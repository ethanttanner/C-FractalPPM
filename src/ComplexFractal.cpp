#include "ComplexFractal.h"
#include <cstdlib>
#include "image_menu.h"
#include <ctime>
#include <cmath>

ComplexFractal::ComplexFractal( ) : ThreadedGrid( 200, 300 ), minX(-1.5), maxX(1.5), minY(-1), maxY(1), delta_X(0.01), delta_Y(0.01) {
    //setGridSize( 200, 300 );
    NumberGrid::setMaxNumber(255);
}
ComplexFractal::ComplexFractal( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y ) : ThreadedGrid(height, width), minX(min_x), maxX(max_x), minY(min_y), maxY(max_y), delta_X(0.01), delta_Y(0.01) {
    //setDeltas( calculateDeltaX(), calculateDeltaY() );
    //setGridSize( height, width );
    NumberGrid::setMaxNumber(255);
}
ComplexFractal::~ComplexFractal( ) {}
double ComplexFractal::getMinX( ) const {
    return this->minX;
}
double ComplexFractal::getMaxX( ) const {
    return this->maxX;
}
double ComplexFractal::getMinY( ) const {
    return this->minY;
}
double ComplexFractal::getMaxY( ) const {
    return this->maxY;
}
void ComplexFractal::setGridSize( const int& height, const int& width ) {
    if ( height >= 2 && width >= 2 ) {
        NumberGrid::setGridSize( height, width );
        double dx = calculateDeltaX();
        double dy = calculateDeltaY();
        setDeltas( dx, dy );
    }
}
void ComplexFractal::setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y ) {
    /*if ( min_x <= 2 && min_x >= -2 && max_x <=2 && max_x >= -2 && max_x != min_x && min_y <= 2 && min_y >= -2 && max_y <= 2 && max_y >= -2 && max_y != min_y ) {
        if ( min_x > max_x ) {
            minX = max_x;
            maxX = min_x;
            delta_X = calculateDeltaX();
        }
        else {
            minX = min_x;
            maxX = max_x;
            delta_X = calculateDeltaX();
        }
        if ( min_y > max_y ) {
            minY = max_y;
            maxY = min_y;
            delta_Y = calculateDeltaY();
        }
        else {
            minY = min_y;
            maxY = max_y;
            delta_Y = calculateDeltaY();
        }
      }*/
    
    
    if ( min_x >= -2 && min_x <= 2 && max_x >= -2 && max_x <= 2 && min_y >= -2 && min_y <= 2 && max_y >= -2 && max_y <= 2  && min_x != max_x && min_y != max_y) {
        if ( min_x < max_x ) {
            minX = min_x;
            maxX = max_x;
        }
        else {
            minX = max_x;
            maxX = min_x;
        }
        if (min_y < max_y) {
            minY = min_y;
            maxY = max_y;
        }
        else {
            minY = max_y;
            maxY = min_y;
        }
        double x = calculateDeltaX();
        double y = calculateDeltaY();
        this->setDeltas( x, y );
    }
    }
double ComplexFractal::getDeltaX( ) const {
    return delta_X;
}
double ComplexFractal::getDeltaY( ) const {
    return delta_Y;
}
void ComplexFractal::setDeltas( const double& delta_x, const double& delta_y ) {
    if ( delta_x >= 0 && delta_y >= 0 ) {
        this->delta_X = delta_x;
        this->delta_Y = delta_y;
    }
}
double ComplexFractal::calculateDeltaY( ) const {
    return ( maxY - minY ) / ( mHeight - 1 );
}
double ComplexFractal::calculateDeltaX( ) const {
    return ( maxX - minX ) / ( mWidth - 1 );
}
double ComplexFractal::calculatePlaneXFromPixelColumn( const int& column ) const {
    if ( column >= 0 && column < mWidth )   {
        return minX + column * delta_X;
    }
    else {
        return 0.0;
    }
}
double ComplexFractal::calculatePlaneYFromPixelRow( const int& row ) const {
    if ( row >= 0 && row < mHeight )   {
        return maxY - row * delta_Y;
    }
    else {
        return 0.0;
    }
}
void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y ) const {
    if ( row >= 0 && row < mHeight && column >= 0 && column < mWidth ) {
        x = calculatePlaneXFromPixelColumn(column);
        y = calculatePlaneYFromPixelRow(row);
    }
    else {
        x = y = 0.0;
    }
}
int ComplexFractal::calculateNumber( const int& row, const int& column ) const {
    if (row >= 0 && row < mHeight && column >= 0 && column < mWidth) {
        return std::abs(getMaxNumber() * std::sin(10*calculatePlaneXFromPixelColumn( column )) * std::cos(10*calculatePlaneYFromPixelRow( row )));
    }
    else {
        return -1;
    }
}

