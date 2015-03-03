//
//  Mole.h
//  moleit-x
//
//  Created by Todd Perkins on 6/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef moleit_x_Mole_h
#define moleit_x_Mole_h

#include "cocos2d.h"

using namespace cocos2d;

class Mole : public cocos2d::CCSprite
{
    private:
    
public:
    float upTime;
    bool isUp, didMiss;
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
    void stop();
    void reset();
    void start();
    void wasTapped();
    bool getIsUp();
    void stopEarly();
    void startLoopAnimation();
	// implement the "static node()" method manually
	LAYER_CREATE_FUNC(Mole);
};

#endif // __HELLOWORLD_SCENE_H__
