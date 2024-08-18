#include "JuliaSet.h"
#include <cstdlib>
#include <cmath>



JuliaSet::JuliaSet( ) : ComplexFractal(), a( -0.650492 ), b( -0.478235 ) {
    NumberGrid::setMaxNumber(255);
}

JuliaSet::JuliaSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y, const double& a, const double& b ) : ComplexFractal( height, width, min_x, max_x, min_y, max_y ), a( a ), b( b ) {
    NumberGrid::setMaxNumber(255);
}
JuliaSet::~JuliaSet( ) {}
double JuliaSet::getA( ) const {
    return a;
}
double JuliaSet::getB( ) const {
    return b;
}
void JuliaSet::setParameters( const double& a, const double& b ) {
    if ( a <= 2 && a >= -2 && b <= 2 && b >= -2 ) {
        this->a = a;
        this->b = b;
    }
}
void JuliaSet::calculateNextPoint( const double x0, const double y0, double& x1, double &y1 ) const {
    x1 = (x0*x0) - (y0*y0) + a;
    y1 = (2 * x0 * y0) + b;
    
}
int JuliaSet::calculatePlaneEscapeCount( const double& x0, const double& y0 ) const {
    int count = 0;
    double x1, y1, x2, y2 = 0.0;
    double distance = sqrt(( x0*x0 ) + ( y0*y0 ));
    if (distance > 2){
        return count;}
    x1 = x0;
    y1 = y0;
    count = 1;
    while (distance <= 2){
        calculateNextPoint( x1,y1,x2,y2 );
        distance = sqrt(( x2*x2 ) + ( y2*y2 ));
        if (distance > 2){
            return count;}
        if (count >= NumberGrid::getMaxNumber()){
            return count;}
        x1 = x2;
        y1 = y2;
        count += 1;
    }
    return -1;
    }

int JuliaSet::calculateNumber( const int& row, const int& column ) const {
    if ( row < 0 || row >= mHeight || column < 0 || column >= mWidth ) {
        return -1;
      }
      else {
        double x = calculatePlaneXFromPixelColumn( column );
        double y = calculatePlaneYFromPixelRow( row );
        calculatePlaneCoordinatesFromPixelCoordinates( row, column, x, y );
        return calculatePlaneEscapeCount( x, y );
      }
}
