//
// Created by YINING on 2023/10/21.
//

#ifndef BLINKE_LED_H
#define BLINKE_LED_H

#include "Mymain.h"
class led {
private:
    char name[10] = {};
public:
    explicit led(const char *str);
    void LED_Flash();
};


#endif //BLINKE_LED_H
