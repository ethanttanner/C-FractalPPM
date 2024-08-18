#include "PPM.h"
#include "Image.h"
#include <iostream>
#include <string>

using byte = unsigned char;

PPM::PPM( ) : Image::Image(), mMaxColorValue(1) {}

PPM::PPM( const int& height, const int& width ) : Image( height, width ), mMaxColorValue(1) {}

int PPM::getMaxColorValue( ) const {
    return mMaxColorValue;
}

bool PPM::valueValid( const int& value ) const {
    return value <= mMaxColorValue && value >= 0;
}

void PPM::setMaxColorValue( const int& max_color_value ) {
    if ( max_color_value > 0 && max_color_value <= 255 )
        this->mMaxColorValue = max_color_value;
}

void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value ) {
    if ( valueValid(value) )
        Image::setChannel( row, column, channel, value );
}

void PPM::setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue ) {
    setChannel( row, column, 0, red );
    setChannel( row, column, 1, green );
    setChannel( row, column, 2, blue );
}

// P6 WIDTH HEIGHT MAX_COLOR_VALUE\n
void PPM::writeStream(std::ostream& os) const {
    os << "P6 " << PPM::getWidth() << " " << PPM::getHeight() << " " << PPM::getMaxColorValue() << std::endl;
    for (int i=0; i < PPM::getHeight(); i++)
        for (int j=0; j < PPM::getWidth(); j++)
            for (int k=0; k < 3; k++)
                os << (byte) PPM::getChannel( i, j, k );
    
}

void PPM::readStream(std::istream& is) {
    std::string P6;
    int width, height, max_color_value;
    is >> P6 >> width >> height >> max_color_value;
    //os << "P6 " << mWidth << " " << mHeight << " " << mMaxColorValue << std::endl;
    Image::setWidth( width );
    Image::setHeight( height );
    PPM::setMaxColorValue(max_color_value);
    unsigned char c;
    is.read((char*) &c, sizeof(c));
    for (int i=0; i < height; i++) {
        for (int j=0; j < width; j++) {
            for (int k=0; k < 3; k++) {
                is.read((char*) &c, sizeof(c));
                Image::setChannel( i, j, k, c );
}}}}


bool PPM::operator==( const PPM& rhs ) const {
    if ( ( this->getHeight() * this->getWidth() * 3 ) == ( rhs.getHeight() * rhs.getWidth() * 3 ) ) {
        return true;
      }
      else {
        return false;
}
}

bool PPM::operator!=( const PPM& rhs ) const {
    if ( ( this->getHeight() * this->getWidth() * 3 ) != ( rhs.getHeight() * rhs.getWidth() * 3 ) ) {
        return true;
      }
      else {
        return false;
}
}
bool PPM::operator<( const PPM& rhs ) const {
    if ( ( this->getHeight() * this->getWidth() * 3 ) < ( rhs.getHeight() * rhs.getWidth() * 3 ) ) {
        return true;
      }
      else {
        return false;
      }
}
bool PPM::operator<=( const PPM& rhs ) const {
    if ( ( this->getHeight() * this->getWidth() * 3 ) <= ( rhs.getHeight() * rhs.getWidth() * 3 ) ) {
        return true;
      }
      else {
        return false;
      }
}
bool PPM::operator>( const PPM& rhs ) const {
    if ( ( this->getHeight() * this->getWidth() * 3 ) > ( rhs.getHeight() * rhs.getWidth() * 3 ) ) {
        return true;
      }
      else {
        return false;
      }
}
bool PPM::operator>=( const PPM& rhs ) const {
    if ( ( this->getHeight() * this->getWidth() * 3 ) >= ( rhs.getHeight() * rhs.getWidth() * 3 ) ) {
        return true;
      }
      else {
        return false;
      }
}
PPM& PPM::operator+=( const PPM& rhs ) {
    int value;
      for ( int row = 0; row < this->getHeight(); row++ ) {
        for ( int col = 0; col < this->getWidth(); col++ ) {
          for ( int channel = 0; channel < 3; channel++ ) {
              value = this->getChannel( row, col, channel ) + rhs.getChannel( row, col, channel );
            if ( value > this->getMaxColorValue() ) {
                value = this->getMaxColorValue();
            }
            this->setChannel(row, col, channel, value);
          }
        }
      }
      return *this;
}

PPM& PPM::operator-=( const PPM& rhs ) {
    int value;
    for ( int row = 0; row < this->getHeight(); row++ ) {
        for ( int col = 0; col < this->getWidth(); col++ ) {
            for ( int channel = 0; channel < 3; channel++ ) {
                value = this->getChannel( row, col, channel ) - rhs.getChannel( row, col, channel );
                if ( value < 0 ) {
                value = 0;  }
                this->setChannel(row, col, channel, value);
            }
        }
    }
    return *this;
}
PPM& PPM::operator*=( const double& rhs ) {
    int value;
    for ( int row = 0; row < this->getHeight(); row++ ) {
        for ( int col = 0; col < this->getWidth(); col++ ) {
            for ( int channel = 0; channel < 3; channel++ ) {
                value = this->getChannel( row, col, channel ) * rhs;
                if ( value > this->getMaxColorValue() ) {
                    value = this->getMaxColorValue();  }
                else if ( value < 0 ) {
                    value = 0; }
                this->setChannel(row, col, channel, value);
            }
        }
    }
    return *this;
}
PPM& PPM::operator/=( const double& rhs ) {
    int value;
    for ( int row = 0; row < this->getHeight(); row++ ) {
        for ( int col = 0; col < this->getWidth(); col++ ) {
            for ( int channel = 0; channel < 3; channel++ ) {
                value = this->getChannel( row, col, channel ) / rhs;
                if ( value > this->getMaxColorValue() ) {
                    value = this->getMaxColorValue();  }
                else if ( value < 0 ) {
                    value = 0; }
                this->setChannel(row, col, channel, value);
            }
        }
    }
    return *this;
}
PPM PPM::operator+( const PPM& rhs ) const {
    PPM ppm = *this;
    ppm += rhs;
    return ppm;
}
PPM PPM::operator-( const PPM& rhs ) const {
    PPM ppm = *this;
    ppm -= rhs;
    return ppm;
}
PPM PPM::operator*( const double& rhs ) const {
    PPM ppm = *this;
    ppm *= rhs;
    return ppm;
}
PPM PPM::operator/( const double& rhs ) const {
    PPM ppm = *this;
    ppm /= rhs;
    return ppm;
}

void PPM::grayFromChannel( PPM& dst, const int& src_channel ) const {
    int v = 0;
    dst.setHeight( this->getHeight() );
    dst.setWidth( this->getWidth() );
    dst.setMaxColorValue( this->getMaxColorValue() );
    for ( int row = 0; row < this->getHeight(); row++ ) {
        for ( int col = 0; col < this->getWidth(); col++ ) {
            v = this->getChannel( row, col, src_channel );
            for ( int channel = 0; channel < 3; channel++ ) {
                dst.setPixel( row, col, v, v, v );
            }
        }
    }
}

void PPM::grayFromRed( PPM& dst ) const {
    grayFromChannel( dst, 0 );
}
void PPM::grayFromGreen( PPM& dst ) const {
    grayFromChannel( dst, 1 );
}
void PPM::grayFromBlue( PPM& dst ) const {
    grayFromChannel( dst, 2 );
}
double PPM::linearColorimetricPixelValue( const int& row, const int& column ) const {
    int red = this->getChannel( row, column, 0 );
    int green = this->getChannel( row, column, 1 );
    int blue = this->getChannel( row, column, 2 );
    return 0.2126 * red + 0.7152 * green + 0.0722 * blue;
}
void PPM::grayFromLinearColorimetric( PPM& dst ) const {
    dst.setHeight( this->getHeight() );
    dst.setWidth( this->getWidth() );
    dst.setMaxColorValue( this->getMaxColorValue() );
    double v;
    for ( int row = 0; row < this->getHeight(); row++ ) {
        for ( int col = 0; col < this->getWidth(); col++ ) {
            v = linearColorimetricPixelValue( row, col );
            for( int channel = 0; channel < 3; channel++ ) {
                dst.setChannel( row, col, channel, v );
            }
        }
    }
}

void PPM::orangeFilter(PPM& dst) const {
    dst.setHeight( this->getHeight() );
    dst.setWidth( this->getWidth() );
    dst.setMaxColorValue( this->getMaxColorValue() );
    for ( int row = 0; row < this->getHeight(); row++ ) {
        for ( int col = 0; col < this->getWidth(); col++ ) {
            int new_red = 2 * (2 * this->getChannel( row, col, 0 ) + this->getChannel( row, col, 1 )) / 3;
            int new_green = 2 * (2 * this->getChannel( row, col, 0 ) + this->getChannel( row, col, 2 )) / 6;
            int new_blue = this->getChannel( row, col, 2 )/2;
            dst.setPixel( row, col, new_red, new_blue, new_green );
            }
        }
    }

