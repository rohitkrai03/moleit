//
//  Pause.h
//  moleit-x
//
//  Created by Todd Perkins on 6/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef moleit_x_GameOver_h
#define moleit_x_GameOver_h

#include "cocos2d.h"
#include "Popup.h"

class GameOver : public cocos2d::CCLayer
{
    Popup *popup;
public:
    bool init();
    void replay();
    void mainMenu();
    void gameover();
    LAYER_CREATE_FUNC(GameOver);
};



#endif
