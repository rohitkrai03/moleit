//
//  MainMenu.cpp
//  moleit-x
//
//  Created by Todd Perkins on 6/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "MainMenu.h"
#include "SimpleAudioEngine.h"
#include "GameButton.h"
#include "Game.h"
#include "Utils.h"
#include "Constants.h"
#include "Skins.h"
#include "About.h"
#include "Exit.h"


using namespace cocos2d;
using namespace CocosDenshion;

//USING_NS_CC;

CCScene* MainMenu::scene()
{
    CCScene *sc = CCScene::create();
    MainMenu *m = MainMenu::create();
    sc->addChild(m, 0);
    Skins *sk = (Skins *) Skins::create();
    sc->addChild(sk,1, TAG_SKINS);
    return sc;
}

bool MainMenu::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

    s = CCDirector::sharedDirector()->getWinSize();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(Utils::getFullName("_bg.mp3"));
    SimpleAudioEngine::sharedEngine()->preloadEffect(SOUND_SPLAT);
    SimpleAudioEngine::sharedEngine()->preloadEffect(Utils::getFullName("_miss.wav"));
    char const* file = (Utils::getArtScaleFactor() > 1) ? Utils::getFullName("-hd.plist") : Utils::getFullName(".plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->purgeSharedSpriteFrameCache();
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(file);
    
    file = (Utils::getArtScaleFactor() > 1) ? "title-hd.png" : "title.png";
    CCSprite *bg = CCSprite::create(file);
    bg->setPosition(ccp(s.width/2,s.height/2));
    Utils::scaleSprite(bg);
    this->addChild(bg,-1);

    CCLabelTTF *scoreLabel = CCLabelTTF::create(CCString::createWithFormat("BEST: %d", CCUserDefault::sharedUserDefault()->getIntegerForKey(HIGH_SCORE))->getCString(), CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(),24 * Utils::getArtScaleFactor());
    scoreLabel->setAnchorPoint(ccp(0,1));
    scoreLabel->setScale(Utils::getScale());
    scoreLabel->setPosition(ccp(10,Utils::s().height - 10));
    this->addChild(scoreLabel,10);

    CCMenuItemSprite *playButton = CCMenuItemSprite::create(GameButton::buttonWithText("PLAY!",false), NULL, this, menu_selector(MainMenu::playGame));
    CCMenuItemSprite *skinsButton = CCMenuItemSprite::create(GameButton::buttonWithText("SKINS!",false), NULL, this, menu_selector(MainMenu::showSkins));
    CCMenuItemSprite *aboutButton = CCMenuItemSprite::create(GameButton::buttonWithText("ABOUT!",false), NULL, this, menu_selector(MainMenu::showAbout));
    CCMenuItemSprite *exitButton = CCMenuItemSprite::create(GameButton::buttonWithText("EXIT!",false), NULL, this, menu_selector(MainMenu::exit));
    CCMenu *menu = CCMenu::create(playButton,skinsButton,aboutButton,exitButton,NULL);
    menu->setPosition(ccp(s.width/2,s.height/2 - s.height/4.0f));
    menu->alignItemsHorizontally();

    this->addChild(menu,2);


	return true;
}

void MainMenu::playGame()
{
    CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void MainMenu::mainMenu()
{
    CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}

void MainMenu::showSkins()
{
	Skins *sk = (Skins *)CCDirector::sharedDirector()->getRunningScene()->getChildByTag(TAG_SKINS);
	sk->show();
}


void MainMenu::showAbout(){

	CCDirector::sharedDirector()->replaceScene(About::scene());
}

void MainMenu::exit(){
	CCDirector::sharedDirector()->replaceScene(Exit::scene());
}


