// Author: Carmine Graniello, Nicola Lorenzon, Daniele Moschetta

#include <cstdlib>
#include <ctime>
#include <opencv2/opencv.hpp>
#include "../include/Tray.h"
#include "../include/Test.h"

/*
    Main class for the system with metrics
*/
int main( int argc, char** argv ) {

    std::vector<Tray> trayVec;

    // If two images are passed as arguments, they are processed as a Tray
    if (argc == 3) {
        std::string before = argv[1];
        std::string after = argv[2];
        Tray my_tray = Tray(before, after);
        trayVec.push_back(my_tray);
    }
    else {
        // Otherwise, all possibile Tray combinations are processed
        for (int left = 1; left <= 3; left++) {
            for (int tray = 1; tray <= 8; tray++) {
                std::cout << "Tray " + std::to_string(tray) << " Leftover " << std::to_string(left) << std::endl;
                std::string str1 = "../input/Food_leftover_dataset/tray" + std::to_string(tray) + "/food_image.jpg";
                std::string str2 = "../input/Food_leftover_dataset/tray" + std::to_string(tray) + "/leftover" + std::to_string(left) + ".jpg";
                Tray my_tray = Tray(str1, str2);
                trayVec.push_back(my_tray);
                std::cout << std::endl;
            }
        }
    }
    
    // The Tray vector is tested evaluating the metrics
    Test myTest = Test(trayVec);
    myTest.testTheSystem("../input/Food_leftover_dataset");

    return 0;
}