#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Monster
{
private:
	Sprite* monsterBody; //���� Sprite.
	Sprite* hpBar; //�������� Sprite.
	float maxEnergy; //���� �ִ�HP.
	float curEnergy; //���� ����HP.
	float defensivePower; //���� ����.
	float speedOfMove; //���� �̵��ӵ�.
	bool isEnermy; //���� �ĺ�.

	//�Ŀ� ���ݷ�,���ݼӵ�,�����Ÿ� ��� �����ߵ�.

public:

	Monster();
	virtual ~Monster();
	
	//Ÿ�Ժ� ���� ���� �Լ�.
	static Monster* createWithType(int Type);
	//���� sprite ���� �Լ�.
	void setMonsterBody(Sprite* sprite);
	//���� sprite ��ȯ �Լ�.
	Sprite* getMonsterBody();
	//���� max������ ���� �Լ�.
	void setEnergey(float max);
	//���� �޴�����ó�� �Լ�.
	float subEnergy(float damage);
	//���� �ĺ� ���� �Լ�.
	void setIsEnermy(bool check);
	//���� �ĺ� ��ȯ �Լ�.
	bool getIsEnermy();
	//���� ���� ���� �Լ�.
	void setDefensivePower(float defensive);
	//���� ���� ��ȯ �Լ�.
	float getDefensivePower();
	//���� �̵��ӵ� ���� �Լ�.
	void setSpeedOfMove(float speed);
	//���� �̵��ӵ� ��ȯ �Լ�.
	float getSpeedOfMove();
	//���� �������� ���� �Լ�.
	void setHpBar();
	//���� ���� �Լ�.
	void release();

};
#endif // __MONSTER_H__