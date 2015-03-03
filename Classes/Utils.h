//
//  Utils.h
//  moleit-x
//
//  Created by Todd Perkins on 6/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef moleit_x_Utils_h
#define moleit_x_Utils_h

#include "cocos2d.h"
#include "Game.h"
#include "HUD.h"

using namespace cocos2d;

class Utils
{
public:
    static Game* gameLayer();
    static HUD* hudLayer();
    static cocos2d::CCLayer* layerWithTag(int tag);
    static cocos2d::CCSize s();
    static cocos2d::CCAnimate* getAnimationWithFrames(int from, int to);
    static void scaleSprite(cocos2d::CCSprite * sprite);
    static float getScale();
    static void setScale(float s);
    static float getArtScaleFactor();
    static void setArtScaleFactor(int s);
    static void setSkin(char const*skin);
    static char const* getSkin();
    static char const* getFullName(char const* suffix);
};

#endif
