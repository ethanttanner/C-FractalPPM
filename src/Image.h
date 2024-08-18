#ifndef _IMAGE_H_
#define _IMAGE_H_
#include <vector>
#include <iostream>

class Image {
public:
    Image( );
    Image( const int& height, const int& width );
    int getHeight( ) const;
    int getWidth( ) const;
    bool indexValid( const int& row, const int& column, const int& channel ) const;
    int index( const int& row, const int& column, const int& channel ) const;
    int getChannel( const int& row, const int& column, const int& channel ) const;
    void setHeight( const int& height );
    void setWidth( const int& width );
    void setChannel( const int& row, const int& column, const int& channel, const int& value );
    
private:
    int mHeight, mWidth;
    std::vector<int> image;
};

#endif // _IMAGE_H_

