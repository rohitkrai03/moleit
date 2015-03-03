#ifndef __MAINMENU_H__
#define __MAINMENU_H__

#include "cocos2d.h"
#include "Popup.h"
using namespace cocos2d;

class MainMenu : public cocos2d::CCLayer {
    cocos2d::CCSize s;
    Popup *popup;

public:
    virtual bool init();
    virtual void playGame();
    void showSkins();
    static void mainMenu();
    static CCScene* scene();

    void showAbout();
    void exit();
    LAYER_CREATE_FUNC(MainMenu);
}; // __MAINMENU_H__


#endif
