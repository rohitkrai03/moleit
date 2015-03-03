//
//  Pause.cpp
//  moleit-x
//
//  Created by Todd Perkins on 6/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Pause.h"
#include "Utils.h"
#include "Game.h"
#include "Constants.h"
#include "GameButton.h"
#include "MainMenu.h"
//#include "JniIAP.h"

using namespace cocos2d;

bool Pause::init()
{
    if (!CCLayer::init()) {
        return false;
    }

    pauseButton = CCMenuItemSprite::create(CCSprite::createWithSpriteFrameName("pause_button.png"), NULL,this,menu_selector(Pause::pause));
    CCMenu *menu = CCMenu::create(pauseButton,NULL);
    menu->setPosition(ccp(Utils::s().width - pauseButton->getContentSize().width/2,pauseButton->getContentSize().height/2));
    this->addChild(menu,1);

    popup = Popup::popupWithTitle("-PAUSED-");
    popup->addButtonWithText("RESUME", this, menu_selector(Pause::resume));
    popup->addButtonWithText("MAIN", this, menu_selector(Pause::mainMenu));
    this->addChild(popup,1);

    return true;
}

void Pause::pause()
{
	this->togglePause(true);
}

void Pause::resume()
{
	this->togglePause(false);
}

void Pause::mainMenu()
{
	MainMenu::mainMenu();
}

void Pause::togglePause(bool paused)
{
	popup->show(paused);
	Utils::gameLayer()->setTouchEnabled(!paused);
	pauseButton->setVisible(!paused);
}




