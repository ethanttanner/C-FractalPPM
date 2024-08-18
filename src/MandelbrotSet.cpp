#include "MandelbrotSet.h"
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <limits>

MandelbrotSet::MandelbrotSet( ) : ComplexFractal() {}

MandelbrotSet::MandelbrotSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y ) : ComplexFractal( height, width, min_x, max_x, min_y, max_y ) {}
MandelbrotSet::~MandelbrotSet( ) {}

void MandelbrotSet::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const {
    x1 = (x0 * x0) - (y0 * y0) + a;
    y1 = 2 * x0 * y0 + b;
}

int MandelbrotSet::calculatePlaneEscapeCount( const double& a, const double& b ) const {
    int count = 0;
    double x0 = a;
    double y0 = b;
    double x1, y1;
    double distance = sqrt((x0*x0) + (y0*y0));
    if ( distance > 2 ) {
        return 0;
    }
    else {
        count++;
    }
    while ( count < NumberGrid::getMaxNumber() ) {
        this->calculateNextPoint(x0, y0, a, b, x1, y1 );
        double d = sqrt((x1*x1) + (y1*y1));
        if (d > 2) {
            return count;
        }
        else {
            x0 = x1;
            y0 = y1;
            count++;
            
        }
    }
    return count;
}
int MandelbrotSet::calculateNumber( const int& row, const int& column ) const {
    if (row < 0 || row >= mHeight || column < 0 || column >= mWidth) {
        return -1;
    }
    return this->calculatePlaneEscapeCount(calculatePlaneXFromPixelColumn( column ), calculatePlaneYFromPixelRow( row ));
}
/*
MandelbrotPower::MandelbrotPower( ) : MandelbrotSet(), power( 2.0 ) {}
MandelbrotPower::~MandelbrotPower( ) {}

double MandelbrotPower::getPower( ) const {
    return power;
}
void MandelbrotPower::setPower( const double& power ) {
    power = power;
}

void MandelbrotPower::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const {
    double r = sqrt( x*x + y*y )
    double theta = std::atan2( y, x )
    x1 = pow( r, d ) * std::cos( d * theta ) + a
    y1 = pow( r, d ) * std::sin( d * theta ) + b
    (void)x1;
    (void)y1;
}
*/
