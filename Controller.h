#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Controller : public cocos2d::LayerColor
{
private:
	Sprite* characterSprite;
	Sprite* rightSprite;
	Sprite* leftSprite;
	Sprite* attackSprite;
	Sprite* skillSprite[4];

	Sprite* sworld; //Test용. Test후 삭제할것.

	Size winSize;
	bool isLeftPressed;
	bool isRightPressed;
	bool isAttackPressed;
	bool isSkillPressed;
	
public:

	//Controller();
	//~Controller();

	virtual bool init();
	
	void createButtons();
	
	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event);
	
	bool isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch);

	void startMovingCharacter();
	void stopMovingCharacter();
	void moveCharacter(float t);
	
	void startAttackCharacter();
	void stopAttackCharacter();
	void attackCharacter(float t);

	CREATE_FUNC(Controller);
};
#endif // __CONTROLLER_H__
