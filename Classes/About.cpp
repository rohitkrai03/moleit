#include "About.h"
#include "Popup.h"
#include "Utils.h"
#include "Game.h"
#include "Constants.h"
#include "GameButton.h"
#include "MainMenu.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

CCScene* About::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    About *layer = About::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool About::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCSize size = CCDirector::sharedDirector()->getWinSize();

    CCSprite* bg = CCSprite::createWithSpriteFrameName("menu.png");
    bg->setPosition( ccp(size.width/2, size.height/2) );
    Utils::scaleSprite(bg);
    this->addChild(bg, -1);

    CCLabelTTF *howLabel = CCLabelTTF::create("--How To Play--", CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    howLabel->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (bg->getContentSize().height/2*1.2) - howLabel->getContentSize().height * 2));
    this->addChild(howLabel,1);

    CCLabelTTF *how = CCLabelTTF::create("%Just Tap On The Moles To Kill Them%", CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    how->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (bg->getContentSize().height/2) - how->getContentSize().height * 2));
    this->addChild(how,1);

    CCLabelTTF *titleLabel = CCLabelTTF::create("--DEVELOPED BY TEAM ITERATORS--", CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    titleLabel->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (bg->getContentSize().height/2*0.6) - titleLabel->getContentSize().height * 2));
    this->addChild(titleLabel,1);

    CCLabelTTF *name1 = CCLabelTTF::create("#Rohit Kumar Rai#", CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    name1->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (bg->getContentSize().height/2*0.4) - name1->getContentSize().height * 2));
    this->addChild(name1,1);

    CCLabelTTF *name2 = CCLabelTTF::create("#Rima Roy#", CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    name2->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (bg->getContentSize().height/2*0.2) - name2->getContentSize().height * 2));
    this->addChild(name2,1);


    CCLabelTTF *name3 = CCLabelTTF::create("#Akshat Kumar#", CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    name3->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (bg->getContentSize().height/2*0) - name3->getContentSize().height * 2));
    this->addChild(name3,1);

    CCLabelTTF *name4 = CCLabelTTF::create("#Satrajit Das#", CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    name4->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (bg->getContentSize().height/2*-0.2) - name4->getContentSize().height * 2));
    this->addChild(name4,1);


    CCMenuItemSprite *backButton = CCMenuItemSprite::create(GameButton::buttonWithText("BACK!",false), NULL, this, menu_selector(About::back));
    CCMenu *menu = CCMenu::create(backButton,NULL);
    menu->setPosition(ccp(size.width/2,size.height/3 - size.height/4.0f));
    menu->alignItemsHorizontally();
    this->addChild(menu,2);

    return true;
}

void About::back()
{
	CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}
