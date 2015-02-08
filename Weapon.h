#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"
using namespace cocos2d;

class Weapon : public cocos2d::CCSprite
{
private:
	Sprite* weaponBody; //���� �̹���
	bool isshortdistance; //�ٰŸ�,���Ÿ� üũ
	bool isEnermy; //�Ǿ� �ĺ�
	float damage; //���� ������
	float speedOfAttack; //���� ����
	Point* range; //���� �����Ÿ�

public:
	float xPos, yPos;

	Weapon();
	virtual ~Weapon();

	//Ÿ�Ժ� ���� ���� �Լ�.
	static Weapon* createWithType(int type);
	//���� Sprite ���� �Լ�.
	void setweaponBody(Sprite* sprite);
	//���� Sprite ��ȯ �Լ�.
	Sprite* getweaponBody();
	//������ ���� �Լ�.
	void setDamage(float damage);
	//������ ��ȯ �Լ�.
	float getDamage();
	//�Ǿƽĺ� ���� �Լ�.
	void setIsEnermy(bool check);
	//�Ǿƽĺ� ��ȯ �Լ�.
	bool getIsEnermy();
	//���ݼӵ� ���� �Լ�.
	void setSpeedOfAttack(float speed);
	//���ݼӵ� ��ȯ �Լ�.
	float getSpeedOfAttack();
	//�����Ÿ� ���� �Լ�.
	void setRange(float xPos, float yPos);
	//�����Ÿ� ��ȯ �Լ�.
	Point* getRange();
	//��/�ٰŸ� ���� �Լ�.
	void setIsShortDistance(bool check);
	//��/�ٰŸ� ��ȯ �Լ�.
	bool getIsShortDistance();
	//���� ���� �Լ�.
	void release();
};
#endif // __WEAPON_H__