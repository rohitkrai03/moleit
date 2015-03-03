/*
 * Exit.h
 *
 *  Created on: 27-Apr-2014
 *      Author: Rohit
 */

#ifndef EXIT_H_
#define EXIT_H_


#include "cocos2d.h"

class Exit : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();

    // a selector callback
    void yes();
    void no();

    // implement the "static node()" method manually
    LAYER_CREATE_FUNC(Exit);
};


#endif /* EXIT_H_ */
