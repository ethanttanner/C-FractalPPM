#include <iostream>
#include <cstdlib>
#include "image_menu.h"
#include "ActionData.h"
#include <ctime>

int main( ) {
    std::srand(std::time(0));
    return imageMenu( std::cin, std::cout );
}
