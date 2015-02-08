#ifndef __GAMEMAKER_H__
#define __GANENAKER_H__

#include "cocos2d.h"
#include "Monster.h"
#include "Weapon.h"
#include "Background.h"
using namespace cocos2d;

class GameMaker : public cocos2d::LayerColor
{
private:
	Layer* backgroundLayer;
	Layer* controllerLayer;
	Size winSize;

	Sprite* characterSprite;
	Sprite* rightSprite;
	Sprite* leftSprite;
	Sprite* attackSprite;
	Sprite* skillSprite[4];

	bool isLeftPressed;
	bool isRightPressed;
	bool isAttackPressed;
	bool isSkillPressed;
	bool isRight;

	Background* background;

	std::vector<Monster*> arrMonster;
	std::vector<Weapon*> arrWeapon;
	
public:

	//GameMaker();
	//~GameMaker();

	virtual bool init();

	void createButtons(); //��ư ���� �Լ�.
	void createBackgroundParallax(); //����� ����� �Լ�.
	void setPositionPlayer(); // �÷��̾� ��ġ ���� �Լ�.

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

	void setFirstPositionWeapon(Sprite* sprite); //���� ������ġ ����.
	void createWeapon(); // ���� ����.
	void addWeaponList(Weapon* weapon); //���� vector�� �߰�.
	void WeaponRemover(Node* sender); //���� �׼� �Ϸ�� ����.

	void moveToCastle(Sprite* sprite, float movetime); //���� ������ �̵�.
	void moveToPlayer(Sprite* sprite, float movetime); //���� player������ �̵�
	void setFirstPositionMonster(Sprite* sprite); //���� ������ġ ����.
	void createMonster(float t); // ���� ����.
	void addMonsterList(Monster* monster); //���� vector�� �߰�.
	void monsterRemover(Node* sender); //���� �׼� �Ϸ�� ����.
	
	void checkCollision(float t); //�浹 �˻�

	CREATE_FUNC(GameMaker);
};
#endif // __GANENAKER_H__