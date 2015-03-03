#include "Exit.h"
#include "Popup.h"
#include "Utils.h"
#include "Game.h"
#include "Constants.h"
#include "GameButton.h"
#include "MainMenu.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

CCScene* Exit::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    Exit *layer = Exit::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Exit::init()
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

    CCLabelTTF *titleLabel = CCLabelTTF::create("--EXIT--", CCString::createWithFormat("%s.ttf", FONT_MAIN)->getCString(), 24 * Utils::getArtScaleFactor());
    titleLabel->setPosition(ccp(Utils::s().width/2,Utils::s().height/2 + (bg->getContentSize().height/2*1.2) - titleLabel->getContentSize().height * 2));
    this->addChild(titleLabel,1);



    CCMenuItemSprite *yesButton = CCMenuItemSprite::create(GameButton::buttonWithText("YES!",false), NULL, this, menu_selector(Exit::yes));
    CCMenuItemSprite *noButton = CCMenuItemSprite::create(GameButton::buttonWithText("NO!",false), NULL, this, menu_selector(Exit::no));
    CCMenu *menu = CCMenu::create(yesButton,noButton,NULL);
    menu->setPosition(ccp(size.width/2,size.height/2));
    menu->alignItemsHorizontally();
    this->addChild(menu,2);

    return true;
}
void Exit::yes()
{
	CCDirector::sharedDirector()->end();
}
void Exit::no()
{
	CCDirector::sharedDirector()->replaceScene(MainMenu::scene());
}
