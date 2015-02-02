#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Defence_BG_Layer.h"
#include "cocos2d.h"
using namespace cocos2d;

class Controller : public cocos2d::LayerColor
{
public:

	//Controller();
	//~Controller();

	virtual bool init();

	Sprite* spriteCharacter;
	Sprite* sworld; //Test용. Test후 삭제할것.
	Sprite* enemy;
	Sprite* spriteRight;
	Sprite* spriteLeft;
	Sprite* spriteAttack;
	Sprite* spriteSkill_1;
	Sprite* spriteSkill_2;
	Sprite* spriteSkill_3;
	Sprite* spriteSkill_4;

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event);
	
	void rightMoveChar(float f);
	void leftMoveChar(float f);
	void attackChar(float f);
	void skillChar(float f);

	CREATE_FUNC(Controller);
private:
	Defence_BG* pDefence_bg;
};
#endif // __CONTROLLER_H__
