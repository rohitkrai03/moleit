#ifndef __Game_H__
#define __Game_H__

#include "cocos2d.h"
#include "Mole.h"
#include "AppDelegate.h"

using namespace cocos2d;

class Game : public cocos2d::CCLayer
{
    cocos2d::CCArray *moles;
    float timeBetweenMoles,timeElapsed, increaseMolesAtTime, increaseElapsed, lastMoleHitTime,totalTime;
    
    int molesAtOnce;
    cocos2d::CCSize s;
    bool isPaused;
    
public:
    CCString *missSound, *hitSound;
	static cocos2d::CCScene* scene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
    void showMole();
    void initializeGame();
    void onEnterTransitionDidFinish();
    void onExit();
    void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void tick(float dt);
    cocos2d::CCArray* getMoles(bool isUp);
	// implement the "static node()" method manually
    LAYER_CREATE_FUNC(Game);
};

#endif // __HELLOWORLD_SCENE_H__
