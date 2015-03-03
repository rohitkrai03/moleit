//
//  Pause.cpp
//  moleit-x
//
//  Created by Todd Perkins on 6/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Popup.h"
#include "Utils.h"
#include "Game.h"
#include "Constants.h"
#include "GameButton.h"
#include "MainMenu.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

bool Popup::initWithTitle(const char *title)
{
    if (!CCSprite::init()) {
        return false;
    }   
    
    CCSprite *m = CCSprite::createWithSpriteFrameName("menu.png");
    m->setPosition(ccp(Utils::s().width/2,Utils::s().height/2));
    m->setScale(Utils::getScale());
    this->addChild(m,1);
    
    CCLabelTTF *titleLabel = CCLabelTTF::create(title, CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    titleLabel->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (m->getContentSize().height/2 * m->getScale()) - titleLabel->getContentSize().height * 2));
    this->addChild(titleLabel,1);
    this->setVisible(false);
    return true;
}

Popup* Popup::popupWithTitle(const char *title)
{
    Popup *pop = new Popup();
    pop->initWithTitle(title);
    pop->autorelease();
    return pop;
}

void Popup::show(bool shouldShow)
{
    Game *g = Utils::gameLayer();
    if (shouldShow) {
        g->pauseSchedulerAndActions();
    }
    else {
        g->resumeSchedulerAndActions();
    }
    
    for (int i = 0; i < g->getChildrenCount(); i++) {
        CCNode *n = (CCNode *)g->getChildren()->objectAtIndex(i);
        if (shouldShow) {
            n->pauseSchedulerAndActions();
        }
        else {
            n->resumeSchedulerAndActions();
        }
    }
    
    this->setVisible(shouldShow);
    if(shouldShow)
    {
    		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    }
    else
    {
        	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    }

}

void Popup::addButtonWithText(const char* text, CCObject*target, SEL_MenuHandler selector)
{
    CCMenuItemSprite *btn = CCMenuItemSprite::create(GameButton::buttonWithText(text, false), NULL, target, selector);
    if (menu == NULL) {
        menu = CCMenu::create(btn,NULL);
        this->addChild(menu,1);
    }
    else {
        menu->addChild(btn, 1);
    }
    menu->alignItemsHorizontallyWithPadding(btn->getContentSize().width/4);
}




