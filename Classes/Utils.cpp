//
//  Utils.cpp
//  moleit-x
//
//  Created by Todd Perkins on 6/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include "Utils.h"
#include "Constants.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace cocos2d;

static float scale = 1.0f;
static int artScaleFactor = 1;
static char const* currentSkin = SKIN_MOLES;

Game* Utils::gameLayer()
{
    return (Game *)Utils::layerWithTag(TAG_GAME_LAYER);
}
HUD* Utils::hudLayer()
{
    return (HUD *)Utils::layerWithTag(TAG_HUD);
}
CCLayer* Utils::layerWithTag(int tag)
{
    CCScene *sc = CCDirector::sharedDirector()->getRunningScene();
    if (sc->getTag() == TAG_GAME_SCENE) {
        CCLayer *layer = (CCLayer *)sc->getChildByTag(tag);
        return layer;
    }
    return NULL;
}

CCSize Utils::s()
{
    return CCDirector::sharedDirector()->getWinSize();
}



cocos2d::CCAnimate* Utils::getAnimationWithFrames(int from, int to)
{
	CCArray* frames = CCArray::create();
	for (int i = from; i <= to; i++) {
	     CCString *str = CCString::createWithFormat("a%04d.png", i);
	     frames->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str->getCString()));
	}
	CCAnimation *animation = CCAnimation::create(frames, 1.0f/24.0f);
	CCAnimate *a = CCAnimate::create(animation);
	return a;
}

void Utils::scaleSprite(CCSprite* sprite)
{
    float rX = Utils::s().width / sprite->getContentSize().width;
	float rY = Utils::s().height / sprite->getContentSize().height;
	sprite->setScaleX(rX);
	sprite->setScaleY(rY);
}

float Utils::getScale()
{
    return scale;
}

void Utils::setScale(float s)
{
    scale = s;
}

float Utils::getArtScaleFactor()
{
    return artScaleFactor;
}

void Utils::setArtScaleFactor(int s)
{
    artScaleFactor = s;
}

void Utils::setSkin(char const *skin)
{
	currentSkin = skin;
}

char const* Utils::getSkin()
{
	return currentSkin;
}

char const* Utils::getFullName(char const* suffix)
{
	return CCString::createWithFormat("%s%s",currentSkin,suffix)->getCString();
}
