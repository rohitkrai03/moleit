//
//  Pause.cpp
//  moleit-x
//
//  Created by Todd Perkins on 6/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Skins.h"
#include "Utils.h"
#include "Game.h"
#include "Constants.h"
#include "GameButton.h"
#include "MainMenu.h"
//#include "JniIAP.h"

using namespace cocos2d;

bool Skins::init()
{
    if (!CCLayer::init()) {
        return false;
    }

    popup = Popup::popupWithTitle("-SKINS-");
    popup->addButtonWithText("MOLES", this, menu_selector(Skins::setMoleSkin));
    popup->addButtonWithText("ALIENS", this, menu_selector(Skins::setAlienSkin));
    this->addChild(popup,1);

    return true;
}

void Skins::show()
{
	popup->setVisible(true);
}

void Skins::setMoleSkin()
{
	Utils::setSkin(SKIN_MOLES);
	MainMenu::mainMenu();
}

void Skins::setAlienSkin()
{
	//if(CCUserDefault::sharedUserDefault()->getBoolForKey(IAP_JHSKIN)) {
		Utils::setSkin(SKIN_JETPACK);
		MainMenu::mainMenu();
	//}
	//else
	//{
	//	buyItem(IAP_JHSKIN);
	//}
}




