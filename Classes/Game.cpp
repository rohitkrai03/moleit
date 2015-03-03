#include "Game.h"
#include "SimpleAudioEngine.h"
#include "Mole.h"
#include "Constants.h"
#include "HUD.h"
#include "Utils.h"
#include "Pause.h"
#include "MainMenu.h"
#include "GameOver.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* Game::scene()
{
    CCScene *sc = CCScene::create();
    sc->setTag(TAG_GAME_SCENE);
    Game *g = Game::create();
    sc->addChild(g, 0, TAG_GAME_LAYER);
    HUD *h = HUD::create();
    sc->addChild(h,1,TAG_HUD);
    Pause *p = Pause::create();
    sc->addChild(p,1,TAG_PAUSE);
    GameOver *go = GameOver::create();
    sc->addChild(go,1,TAG_GAMEOVER);
    return sc;
}

bool Game::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
	
	molesAtOnce = 3;
	timeBetweenMoles = 0.5f;
	increaseMolesAtTime = 10.0f;

	return true;
}

void Game::initializeGame()
{
	moles = CCArray::create();
	moles->retain();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Utils::getFullName("_bg.mp3"));
	Mole *mole = (Mole *)Mole::create();
	float hPad = Utils::s().width/2 - (mole->getContentSize().width * Utils::getScale()) * 3.5f;
	float vPad = Utils::s().height/2 - (mole->getContentSize().height * Utils::getScale()) * 2.1;
	delete mole;

	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 6; j++){
			Mole *mole = (Mole *)Mole::create();
			mole->setScale(Utils::getScale());
			mole->setPosition(ccp(j * mole->getContentSize().width * Utils::getScale() + hPad, i * mole->getContentSize().height * Utils::getScale() + vPad));
			moles->addObject(mole);
			this->addChild(mole,1);
		}
	}

	CCString *file = (Utils::getArtScaleFactor() > 1) ? ccs(Utils::getFullName("_bg-hd.png")) : ccs(Utils::getFullName("_bg.png"));
	CCSprite *bg = CCSprite::create(file->getCString());
	bg->setPosition(ccp(Utils::s().width/2,Utils::s().height/2));
	Utils::scaleSprite(bg);
	this->addChild(bg,0);

	this->schedule(schedule_selector(Game::tick));
}

void Game::tick(float dt)
{
	timeElapsed += dt;
	increaseElapsed += dt;
	totalTime += dt;
	if(timeElapsed >= timeBetweenMoles && this->getMoles(true)->count() < molesAtOnce)
	{
		this->showMole();
		timeElapsed = 0;
	}

	if(increaseElapsed >= increaseMolesAtTime) {
		int maxMolesAtOnce = 18;
		if(molesAtOnce < maxMolesAtOnce) {
			molesAtOnce++;
			float minMoleTime = .1f;
			timeBetweenMoles -= (timeBetweenMoles > minMoleTime) ? .05 : 0;
			increaseMolesAtTime += 10.0f;
		}
		increaseElapsed = 0;
	}
}

void Game::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCTouch *touch = (CCTouch *)pTouches->anyObject();
    CCPoint location = touch->locationInView();
    location = CCDirector::sharedDirector()->convertToGL(location);
    
    for(int i = 0; i < moles->count(); i++) {
    		Mole *mole = (Mole *)moles->objectAtIndex(i);
    		if(!mole->getIsUp()) {
    			continue;
    		}
    		if(CCRect::CCRectContainsPoint(mole->boundingBox(), location)) {
    			mole->wasTapped();
    			SimpleAudioEngine::sharedEngine()->playEffect(SOUND_SPLAT);
    			Utils::hudLayer()->didScore();
    			break;
    		}
    }
}

void Game::showMole()
{
	Mole *mole = (Mole *)this->getMoles(false)->randomObject();
	mole->start();
}

CCArray* Game::getMoles(bool isUp)
{
    CCArray *ary = CCArray::create();
    for(int i = 0; i < moles->count();i++) {
    		Mole *mole = (Mole *)moles->objectAtIndex(i);
    		if(mole->getIsUp() == isUp)
    		{
    			ary->addObject(mole);
    		}
    }
	return ary;
}

void Game::onExit()
{
	moles->release();
	CCLayer::onExit();
}

void Game::onEnterTransitionDidFinish()
{
	this->setTouchEnabled(true);
	this->initializeGame();
}
