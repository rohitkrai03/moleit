//
//  Mole.cpp
//  moleit-x
//
//  Created by Todd Perkins on 6/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Mole.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"
#include "Game.h"
#include <sstream>
#include <string>
#include "Utils.h"
#include "HUD.h"

using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

#define TAG_REPEAT_ANIM 6

bool Mole::init()
{
	if ( !CCSprite::init() )
	{
		return false;
	}
	upTime = 2.0f;
	isUp = false;
	this->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("a0001.png"));

	return true;
}

void Mole::start()
{
	this->stopAllActions();
	isUp = true;
	didMiss = true;
	this->runAction(CCSequence::create(
			CCDelayTime::create(upTime),
			CCCallFunc::create(this,callfunc_selector(Mole::stop)),
			NULL));
	this->runAction(CCSequence::create(
				Utils::getAnimationWithFrames(1,10),
				CCCallFunc::create(this,callfunc_selector(Mole::startLoopAnimation)),
				NULL));
}

void Mole::startLoopAnimation()
{
	if(!isUp){
		return;
	}
	CCRepeatForever *repeat = CCRepeatForever::create((CCSequence *)CCSequence::create(
			Utils::getAnimationWithFrames(11,20),
			Utils::getAnimationWithFrames(11,20)->reverse(),
			NULL));
	repeat->setTag(TAG_REPEAT_ANIM);
	this->runAction(repeat);
}


void Mole::stop()
{
	this->stopAllActions();
	this->runAction(CCSequence::create(
					Utils::getAnimationWithFrames(1,10)->reverse(),
					CCCallFunc::create(this,callfunc_selector(Mole::reset)),
					NULL));
}

void Mole::reset()
{
	isUp = false;
	if(didMiss) {
		Utils::hudLayer()->missedMole();
	}
}

void Mole::wasTapped()
{
	this->stopAllActions();
	this->runAction(Utils::getAnimationWithFrames(21,31));
	isUp = false;
}
bool Mole::getIsUp(){
    return isUp;
}

void Mole::stopEarly()
{
	didMiss = false;
	isUp = false;
	this->stopAllActions();
	this->stop();
}
