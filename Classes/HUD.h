//
//  HUD.h
//  moleit-x
//
//  Created by Todd Perkins on 6/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef moleit_x_HUD_h
#define moleit_x_HUD_h

#include "cocos2d.h"

class HUD : public cocos2d::CCLayer
{
    int carrotsLeft, score;
    cocos2d::CCArray *carrots;
    cocos2d::CCLabelTTF *scoreLabel;
public:
	virtual bool init();
    void didScore();
    void missedMole();
    void onExit();
    LAYER_CREATE_FUNC(HUD);
};


#endif
