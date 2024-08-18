#include <iostream>
#include <vector>
#include "Image.h"

Image::Image( ) : mHeight(0), mWidth(0) {
    image.resize(mHeight * mWidth);
}

Image::Image( const int& height, const int& width ) : mHeight(height), mWidth(width) {
    image.resize(height * width * 3);
}

int Image::getHeight( ) const {
    return mHeight;
}

int Image::getWidth( ) const {
    return mWidth;
}

bool Image::indexValid( const int& row, const int& column, const int& channel ) const {
    return row >= 0 && row <= mHeight && column >= 0 && column <= mWidth && channel >= 0 && channel <= 2;
}

int Image::index( const int& row, const int& column, const int& channel ) const {
    return (row * mWidth * 3 + column * 3) + channel;
}

int Image::getChannel( const int& row, const int& column, const int& channel ) const {
    if (indexValid(row, column, channel))
        return (int) image[index(row, column, channel)];
    else
        return -1;
}

void Image::setHeight( const int& height ) {
    if (height >= 0)
    {
        this->mHeight = height;
        image.resize( mHeight * mWidth * 3 );
    }}

void Image::setWidth( const int& width ) {
    if (width >= 0) {
        this->mWidth = width;
        image.resize( mHeight * mWidth * 3 );
    }}

void Image::setChannel( const int& row, const int& column, const int& channel, const int& value ) {
    if (indexValid(row, column, channel))
        image[index( row, column, channel )] = value;
}
