#include "ColorTable.h"
#include <cstdlib>
#include <cmath>

//___________________Color_Class__________________________

Color::Color( ) : red( 0 ), green( 0 ), blue( 0 ) {}
Color::Color( const int& red, const int& green, const int& blue ) : red( red ), green( green ), blue( blue ) {}
int Color::getRed( ) const {
    return this->red;
}
int Color::getGreen( ) const {
    return this->green;
}
int Color::getBlue( ) const {
    return this->blue;
}
int Color::getChannel( const int& channel ) const {
    switch ( channel ) {
        case 0: return red;
        case 1: return green;
        case 2: return blue;
        default: return -1;
    }}
void Color::setRed( const int& value ) {
    if ( value >= 0 ) {
        this->red = value;
    }}
void Color::setGreen( const int& value ) {
    if ( value >= 0 ) {
        this->green = value;
    }}
void Color::setBlue( const int& value ) {
    if ( value >= 0 ) {
        this->blue = value;
    }}
void Color::setChannel( const int& channel, const int& value ) {
    if ( value >= 0 ) {
        switch ( channel ) {
            case 0: setRed( value );
                break;
            case 1: setGreen( value );
                break;
            case 2: setBlue( value );
                break;
            default: break;
}}}
void Color::invert( const int& max_color_value ) {
    if ( red <= max_color_value && green <= max_color_value && blue <= max_color_value ) {
        this->red = max_color_value - red;
        this->green = max_color_value - green;
        this->blue = max_color_value - blue;
    }
    //(void)max_color_value;
}

bool Color::operator==( const Color& rhs ) const {
    if ( this->getRed() == rhs.getRed() && this->getGreen() == rhs.getGreen() && this->getBlue() == rhs.getBlue() ) {
        return true;
      }
    else {
        return false;
      }
}


void Color::setFromHSV(const double& hue, const double& saturation, const double& value) {
    double r = getRed();
    double g = getGreen();
    double b = getBlue();
    
    HSV_to_RGB(hue, saturation, value, r, g, b);
}

void Color::getHSV(double& hue, double& saturation, double& value) const {
    RGB_to_HSV( red, green, blue, hue, saturation, value);
}



std::ostream& operator<<( std::ostream& os, const Color& color ) {
    os << color.getRed() << ":" << color.getGreen() << ":" << color.getBlue();
    return os;
}

// Displays the color to os in the following format: “red:green:blue”. For example, if the color has red = 13, green = 2 and blue = 45, then the output would be “13:2:45”.

//________________ColorTable_Class________________________

ColorTable::ColorTable( const int& num_color ) : mColors( num_color ) {}

int ColorTable::getNumberOfColors( ) const {
    return mColors.size();
}
    
void ColorTable::setNumberOfColors( const int& num_color ) {
    mColors.resize( num_color );
}

const Color& ColorTable::operator[]( const int& i ) const {
    if ( i < 0 || i >= (int)mColors.size()) {
        static Color ec( -1, -1, -1 );
        static Color c( -1, -1, -1 );
        c = ec;
        return c;
    }
    else
        return mColors[i];
}

Color& ColorTable::operator[]( const int& i ) {
    if ( i < 0 || i >= (int)mColors.size()) {
        static Color ec( -1, -1, -1 );
        static Color c( -1, -1, -1 );
        c = ec;
        return c;
    }
    else
        return mColors[i];
    }

void ColorTable::setRandomColor( const int& max_color_value, const int& position ) {
    int zero = 0;
    if ( position >= zero && position < getNumberOfColors() && max_color_value >= 0 ) {
    mColors[position].setRed( std::rand() % (max_color_value + 1));
    mColors[position].setGreen( std::rand() % (max_color_value + 1));
    mColors[position].setBlue( std::rand() % (max_color_value + 1));
    }
}

double ColorTable::gradientSlope(const double y1, const double y2, const double x1, const double x2) const {
    double slope = (y2-y1) / (x2-x1);
    return slope;
    (void)slope;
}

double ColorTable::gradientValue(const double y1, const double x1, const double slope, const double x) const {
    //double y = y1 + ( slope * x1 ) + x;
    
    double y = slope * ( x - x1 ) + y1;
    //y = m(x - x1) + y1

    return y;
    (void)y;
}

void ColorTable::insertGradient( const Color& color1, const Color& color2, const int& position1, const int& position2 ) {
    unsigned char x = 0;

    if (position2 > position1 && position1 < getNumberOfColors() && position2 < getNumberOfColors() && position1 >= x && position2 >= x )
    {
        int n = position2 - position1;
        double red2 = (double)(color2.getRed() - color1.getRed()) / n;
        double green2  = (double)(color2.getGreen() - color1.getGreen()) / n;
        double blue2 = (double)(color2.getBlue() - color1.getBlue()) / n;
        
        for (int i = 0; i <= n; i++)
        {
            int red = color1.getRed() + red2 * i;
            int green = color1.getGreen() + green2 * i;
            int blue = color1.getBlue() + blue2 * i;
            
            Color& color = mColors[position1 + i];
            color.setRed(red);
            color.setGreen(green);
            color.setBlue(blue);
        }
    }
}

int ColorTable::getMaxChannelValue( ) const {
    int largest_value = 0;
    for ( int i = 0; i < (int)mColors.size(); i++ ) {
        //int current = mColors[i].getChannel( i );
        int current = mColors[i].getRed() > mColors[i].getBlue() ? mColors[i].getRed() : mColors[i].getBlue();
        current = mColors[i].getGreen( ) > current ? mColors[i].getGreen( ) : current;
        if ( current > largest_value )
            largest_value = current;
        
        
    }
    return largest_value;
}
void ColorTable::insertInvertedGradient( const Color& color1, const int& position1, const int& position2 ) {
    Color invertedColor = color1;
    invertedColor.invert(255);
    insertGradient( color1, invertedColor, position1, position2 );
}

void ColorTable::insertHueSaturationValueGradient(const Color& color1, const Color& color2, const int& position1, const int& position2) {
    int x;
    if (position2 > position1 && position1 < getNumberOfColors() && position2 < getNumberOfColors() && position1 >= x && position2 >= x )
    {
        int n = position2 - position1;
        double hue = (double)(color2.getRed() - color1.getRed()) / n;
        double sat  = (double)(color2.getGreen() - color1.getGreen()) / n;
        double val = (double)(color2.getBlue() - color1.getBlue()) / n;
        for (int i = 0; i <= n; i++)
        {
            int red = color1.getRed() + hue * i;
            int green = color1.getGreen() + sat * i;
            int blue = color1.getBlue() + val * i;
            
            Color& color = mColors[position1 + i];
            color.setRed(red);
            color.setGreen(green);
            color.setBlue(blue);
            //setFromHSV(hue,sat,val);
        }
    }
}

void HSV_to_RGB(const double& hue, const double& saturation, const double& value, double& red, double &green, double& blue) {
    /* Convert Hue, Saturation, Value to Red, Green, Blue
       * Implementation of algorithm from:
       * https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
       *
       * Inputs and ranges:
       * 0.0 <= hue <= 360.0
       * 0.0 <= saturation <= 1.0
       * 0.0 <= value <= 1.0
       *
       * Outputs and ranges:
       * 0.0 <= red <= 255.0
       * 0.0 <= green <= 255.0
       * 0.0 <= blue <= 255.0
       */
      if(hue < 0.0 || hue > 360.0 || saturation < 0.0 || saturation > 1.0 || value < 0.0 || value > 1.0) {
        red = green = blue = 0.0;
        std::cerr << "HSV_to_RGB() input parameters out of range." << std::endl
                  << " hue: " << hue  << std::endl
                  << " saturation: " << saturation << std::endl
                  << " value: " << value << std::endl;
        return;
      }

      // chroma selects the strength of the "primary" color of the current area of the wheel
      double chroma = value * saturation;
      // hue2 selects which 60-degree wedge of the color wheel we are in
      double hue2 = hue / 60.0;
      // x selects the strength of the "secondary" color of the current area of the wheel
      double x = chroma * ( 1 - std::abs( fmod( hue2, 2 ) - 1 ) );
      if( hue2 >= 0 && hue2 < 1 ) {
        red = chroma;
        green = x;
        blue = 0.0;
      } else if( hue2 >= 1 && hue2 < 2 ) {
        red = x;
        green = chroma;
        blue = 0.0;
      } else if( hue2 >= 2 && hue2 < 3 ) {
        red = 0.0;
        green = chroma;
        blue = x;
      } else if( hue2 >= 3 && hue2 < 4 ) {
        red = 0.0;
        green = x;
        blue = chroma;
      } else if( hue2 >= 4 && hue2 < 5 ) {
        red = x;
        green = 0.0;
        blue = chroma;
      } else if( hue2 >= 5 && hue2 <= 6 ) {
        red = chroma;
        green = 0.0;
        blue = x;
      } else {
        red = 0;
        green = 0;
        blue = 0;
      }

      // m scales all color channels to obtain the overall brightness.
      double m = value - chroma;
      red = 255.0*( red + m );
      green = 255.0*( green + m );
      blue = 255.0*( blue + m );
}

void RGB_to_HSV(const double& red0, const double &green0, const double& blue0, double& hue, double& saturation, double& value) {
  /* Red, Green, Blue to Convert Hue, Saturation, Value
   * Implementation of algorithm from:
   * https://en.wikipedia.org/wiki/HSL_and_HSV#From_RGB
   *
   * Inputs and ranges:
   * 0.0 <= red <= 255.0
   * 0.0 <= green <= 255.0
   * 0.0 <= blue <= 255.0
   *
   * Outputs and ranges:
   * 0.0 <= hue <= 360.0
   * 0.0 <= saturation <= 1.0
   * 0.0 <= value <= 1.0
   */
  if(red0 < 0.0 || red0 > 255.0 || green0 < 0.0 || green0 > 255.0 || blue0 < 0.0 || blue0 > 255.0) {
    hue = saturation = value = 0.0;
    std::cerr << "RGB_to_HSV() input parameters out of range." << std::endl
              << " red: " << red0  << std::endl
              << " green: " << green0 << std::endl
              << " blue: " << blue0 << std::endl;
    return;
  }

  double red   = red0 / 255.0;
  double green = green0 / 255.0;
  double blue  = blue0 / 255.0;

  // x_max helps identify the primary hue
  double x_max = red;
  if(green > x_max) { x_max = green; }
  if(blue > x_max) { x_max = blue; }
  value = x_max;

  double x_min = red;
  if(green < x_min) { x_min = green; }
  if(blue < x_min) { x_min = blue; }

  double chroma = x_max - x_min;

  if(chroma == 0) {
    hue = 0;
  } else if(value == red) {
    hue = 60.0 * (0 + (green - blue)/chroma);
  } else if(value == green) {
    hue = 60.0 * (2 + (blue - red)/chroma);
  } else if(value == blue) {
    hue = 60.0 * (4 + (red - green)/chroma);
  } else {
    hue = -720.0;
  }
  if(hue < 0.0) {
    hue += 360.0;
  }

  if(value == 0.0) {
    saturation = 0.0;
  } else {
    saturation = chroma/value;
  }

}
