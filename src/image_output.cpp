#include <iostream>
#include <fstream>
#include "image_menu.h"


void drawAsciiImage(ActionData& action_data) {
    int row, col;
    for ( row = 0; row < action_data.getOutputImage().getHeight(); row++ ) {
        for ( col = 0; col < action_data.getOutputImage().getWidth(); col++ ) {
            double sum = (action_data.getOutputImage().getChannel(row, col, 0) + action_data.getOutputImage().getChannel(row, col, 1) + action_data.getOutputImage().getChannel(row, col, 2)) / 765.0;
            char c;
            if ( sum >= 1.0 ) {
                c = '@';
            }
            else if ( sum >= 0.9 ) {
                c = '#';
            }
            else if ( sum >= 0.8 ) {
                c = '%';
            }
            else if ( sum >= 0.7 ) {
                c = '*';
            }
            else if ( sum >= 0.6 ) {
                c = '|';
            }
            else if ( sum >= 0.5 ) {
                c = '+';
            }
            else if ( sum >= 0.4 ) {
                c = ';';
            }
            else if ( sum >= 0.3 ) {
                c = '~';
            }
            else if ( sum >= 0.2 ) {
                c = '-';
            }
            else if ( sum >= 0.1 ) {
                c = '.';
            }
            else {
                c = ' ';
            }
            action_data.getOS() << c;
        }
        action_data.getOS() << std::endl;
    }
}

void writeUserImage( ActionData& action_data ) {
    std::string filename = getString( action_data, "Output filename? " );
    std::ofstream fout( filename, std::ios::binary);
    action_data.getOutputImage().writeStream(fout);
    fout.close();
}

void copyImage(ActionData& action_data) {
    action_data.getOutputImage() = action_data.getInputImage1();
}

void readUserImage1( ActionData& action_data ) {
    std::string file = getString( action_data, "Input filename? " );
    std::ifstream fin( file, std::ios::binary );
    action_data.getInputImage1().readStream( fin );
    fin.close();
}

void readUserImage2( ActionData& action_data ) {
    std::string file = getString( action_data, "Input filename? " );
    std::ifstream fin( file, std::ios::binary );
    action_data.getInputImage2().readStream( fin );
    fin.close();
}
