//
//  GameButton.h
//  moleit-x
//
//  Created by Todd Perkins on 6/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef moleit_x_GameButton_h
#define moleit_x_GameButton_h

#include "cocos2d.h"

class GameButton : public cocos2d::CCSprite
{
    
    
    public:
    bool initWithText(const char * text, bool isBig);
    static GameButton* buttonWithText(const char * text, bool isBig);
};

#endif
