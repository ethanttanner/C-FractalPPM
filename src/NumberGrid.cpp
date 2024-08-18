#include "NumberGrid.h"

NumberGrid::NumberGrid( ) : mHeight(300), mWidth(400), mMaxValue(255), grid( 300* 400, 0 ) {}
NumberGrid::NumberGrid( const int& height, const int& width ) : mHeight( height ), mWidth( width ), mMaxValue(255), grid( mHeight * mWidth, 0 ) {}
int NumberGrid::getHeight( ) const {
    return mHeight;
}
int NumberGrid::getWidth( ) const {
    return mWidth;
}
int NumberGrid::getMaxNumber( ) const {
    return mMaxValue;
}
void NumberGrid::setGridSize( const int& height, const int& width ) {
    if ( height >= 2 && width >= 2 ) {
        mHeight = height;
        mWidth = width;
        grid.resize( height * width, 0 );
    }
}
void NumberGrid::setMaxNumber( const int& number ) {
    if ( number >= 0 ) {
        mMaxValue = number;
    }
}
const std::vector< int >& NumberGrid::getNumbers( ) const {
    return grid;
}
int NumberGrid::index( const int& row, const int& column ) const {
    return (row * mWidth) + column;
}
bool NumberGrid::indexValid( const int& row, const int& column ) const {
    return row >= 0 && row < mHeight && column >= 0 && column < mWidth;
}
bool NumberGrid::numberValid( const int& number ) const {
    return number >= 0 && number <= mMaxValue;
}
int NumberGrid::getNumber( const int& row, const int& column ) const {
    if (indexValid( row, column ))
        return grid[index( row, column )];
    else
        return -1;
}
void NumberGrid::setNumber( const int& row, const int& column, const int& number ) {
    if (numberValid(number) && indexValid(row, column))
        grid[index(row, column)] = number;
}
void NumberGrid::setPPM( PPM& ppm ) const {
    ppm.setHeight( mHeight );
    ppm.setWidth( mWidth );
    ppm.setMaxColorValue( 63 );
    for ( int row = 0; row < mHeight; row++ ) {
        for ( int col = 0; col < mWidth; col++ ) {
            if ( grid[index(row, col)] == 0 )
                ppm.setPixel( row, col, 0, 0, 0 );
            else if ( grid[index(row, col)] == mMaxValue )
                ppm.setPixel( row, col, 63, 31, 31 );
            else if ( grid[index(row, col)] % 8 == 0 )
                ppm.setPixel( row, col, 63, 63, 63 );
            else if ( grid[index(row, col)] % 8 == 1 )
                ppm.setPixel( row, col, 63, 31, 31 );
            else if ( grid[index(row, col)] % 8 == 2 )
                ppm.setPixel( row, col, 63, 63, 31 );
            else if ( grid[index(row, col)] % 8 == 3 )
                ppm.setPixel( row, col, 31, 63, 31 );
            else if ( grid[index(row, col)] % 8 == 4 )
                ppm.setPixel( row, col, 0, 0, 0 );
            else if ( grid[index(row, col)] % 8 == 5 )
                ppm.setPixel( row, col, 31, 63, 63 );
            else if ( grid[index(row, col)] % 8 == 6 )
                ppm.setPixel( row, col, 31, 31, 63 );
            else if ( grid[index(row, col)] % 8 == 7 )
                ppm.setPixel( row, col, 63, 31, 63 );
        }
    }
}

void NumberGrid::setPPM( PPM& ppm, const ColorTable& colors ) const {
    if ( colors.getNumberOfColors() >= 2 ) {
        ppm.setHeight( mHeight );
        ppm.setWidth( mWidth );
        ppm.setMaxColorValue( colors.getMaxChannelValue());
        for ( int row = 0; row < mHeight; row++ ) {
              for ( int col = 0; col < mWidth; col++ ) {
                if ( getNumber( row, col ) == getMaxNumber() ) {
                  ppm.setPixel( row, col, colors[colors.getNumberOfColors() - 1].getRed(), colors[colors.getNumberOfColors() - 1].getGreen(), colors[colors.getNumberOfColors() - 1].getBlue() );
                }
                else if ( getNumber( row, col ) == 0 ) {
                  ppm.setPixel( row, col, colors[0].getRed(), colors[0].getGreen(), colors[0].getBlue() );
                }
                else {
                  ppm.setPixel( row, col, colors[getNumber( row, col ) % colors.getNumberOfColors()].getRed(), colors[getNumber( row, col ) % colors.getNumberOfColors()].getGreen(), colors[getNumber( row, col ) % colors.getNumberOfColors()].getBlue() );
                }
              }
            }
    }
}


NumberGrid::~NumberGrid() {}

void NumberGrid::calculateAllNumbers() {
    for ( int i = 0; i < mHeight; i++ ) {
        for ( int j = 0; j < mWidth; j++ ) {
            int number = calculateNumber( i, j );
            setNumber( i, j, number );
            }
        }
    }
