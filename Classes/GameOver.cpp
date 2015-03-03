//
//  Pause.cpp
//  moleit-x
//
//  Created by Todd Perkins on 6/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GameOver.h"
#include "Utils.h"
#include "Game.h"
#include "Constants.h"
#include "GameButton.h"
#include "MainMenu.h"

using namespace cocos2d;

bool GameOver::init()
{
    if (!CCLayer::init()) {
        return false;
    }

    popup = Popup::popupWithTitle("-GAME OVER-");
    popup->addButtonWithText("REPLAY", this, menu_selector(GameOver::replay));
    popup->addButtonWithText("MAIN", this, menu_selector(GameOver::mainMenu));
    this->addChild(popup,1);
    
    return true;
}

void GameOver::gameover()
{
	popup->show(true);
}

void GameOver::replay()
{
	CCDirector::sharedDirector()->replaceScene(Game::scene());
}

void GameOver::mainMenu()
{
	MainMenu::mainMenu();
}




