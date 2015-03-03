//
//  Skins.h
//  moleit-x
//
//  Created by Todd Perkins on 6/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef moleit_x_Skins_h
#define moleit_x_Skins_h

#include "cocos2d.h"
#include "Popup.h"

class Skins : public cocos2d::CCLayer
{
    Popup *popup;
public:
    virtual bool init();
    void setAlienSkin();
    void setMoleSkin();
    void show();
    LAYER_CREATE_FUNC(Skins);
};



#endif
