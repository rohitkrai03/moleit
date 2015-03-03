//
//  Pause.h
//  moleit-x
//
//  Created by Todd Perkins on 6/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef moleit_x_Pause_h
#define moleit_x_Pause_h

#include "cocos2d.h"
#include "Popup.h"

class Pause : public cocos2d::CCLayer
{
    Popup *popup;
    cocos2d::CCMenuItemSprite *pauseButton;
public:
    bool init();
    void pause();
    void resume();
    void mainMenu();
    void togglePause(bool paused);
    LAYER_CREATE_FUNC(Pause);
};



#endif
