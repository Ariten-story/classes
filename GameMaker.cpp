#include "GameMaker.h"
#include "Player.h"
#include "GameIntroScene.h"
#include <random>

/*
GameMaker::GameMaker(){}
GameMaker::~GameMaker(){}
*/

bool GameMaker::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	// ���� ��������ʴ� texture ���� ����.
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	isRight = false;
	winSize = Director::getInstance()->getWinSize();

	backgroundLayer = Layer::create();
	controllerLayer = Layer::create();
	this->addChild(backgroundLayer);
	this->addChild(controllerLayer);

	this->createButtons();
	this->setKeypadEnabled(true);

	this->createBackgroundParallax();
	this->setPositionPlayer();
	backgroundLayer->addChild(characterSprite);
	backgroundLayer->runAction(Follow::create(characterSprite, Rect(0, 0, 1280 * 2, 720)));
	this->schedule(schedule_selector(GameMaker::createMonster), 3.0f);
	this->schedule(schedule_selector(GameMaker::checkCollision));

	return true;
}


// ��ư ����
void GameMaker::createButtons()
{
	characterSprite = Player::getInstance()->getCharacter();
	rightSprite = Sprite::create("right.png");
	leftSprite = Sprite::create("left.png");
	attackSprite = Sprite::create("Attack.png");
	skillSprite[0] = Sprite::create("Skill_1.png");
	skillSprite[1] = Sprite::create("Skill_2.png");
	skillSprite[2] = Sprite::create("Skill_3.png");
	skillSprite[3] = Sprite::create("Skill_3.png");

	rightSprite->setPosition(Point(winSize.width*0.28, 0));
	rightSprite->setAnchorPoint(Point(0.5, 0.0));
	leftSprite->setPosition(Point(winSize.width*0.14, 0));
	leftSprite->setAnchorPoint(Point(0.5, 0.0));
	attackSprite->setPosition(Point(winSize.width*0.42, 0));
	attackSprite->setAnchorPoint(Point(0.5, 0.0));
	attackSprite->setTag(0);
	skillSprite[0]->setPosition(Point(winSize.width*0.56, 0));
	skillSprite[0]->setAnchorPoint(Point(0.5, 0.0));
	skillSprite[0]->setTag(1);
	skillSprite[1]->setPosition(Point(winSize.width*0.7, 0));
	skillSprite[1]->setAnchorPoint(Point(0.5, 0.0));
	skillSprite[1]->setTag(2);
	skillSprite[2]->setPosition(Point(winSize.width*0.84, 0));
	skillSprite[2]->setAnchorPoint(Point(0.5, 0.0));
	skillSprite[2]->setTag(3);
	skillSprite[3]->setPosition(Point(winSize.width*0.95, 0));
	skillSprite[3]->setAnchorPoint(Point(0.5, 0.0));
	skillSprite[3]->setTag(4);

	controllerLayer->addChild(rightSprite);
	controllerLayer->addChild(leftSprite);
	controllerLayer->addChild(attackSprite);
	for (int i = 0; i < 4; i++)
	{
		controllerLayer->addChild(skillSprite[i]);
	}
}

// �ȵ���̵� Back��ư Ȱ��ȭ
void GameMaker::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	if (keycode == EventKeyboard::KeyCode::KEY_BACK)
	{
		auto pScene = GameIntro::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
	}
}

// ��ġ �̺�Ʈ ���
void GameMaker::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(GameMaker::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameMaker::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameMaker::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

// ��ġ ����
void GameMaker::onExit()
{
	_eventDispatcher->removeEventListenersForTarget(this);

	Layer::onExit();
}

// ��ġ ����
bool GameMaker::onTouchBegan(Touch* touch, Event* event) // ��ġ ���۽�
{
	isLeftPressed = false;
	isRightPressed = false;
	isAttackPressed = false;
	isSkillPressed = false;

	// ��ġ�� ��� ��ư�ȿ� ������ üũ
	if (this->isTouchInside(leftSprite, touch) == true)
	{
		isLeftPressed = true;
		isRight = false;
	}
	else if (this->isTouchInside(rightSprite, touch) == true)
	{
		isRightPressed = true;
		isRight = true;
	}
	else if (this->isTouchInside(attackSprite, touch) == true)
	{
		isAttackPressed = true;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->isTouchInside(skillSprite[i], touch) == true)
				isSkillPressed = true;
		}
	}

	// ��ư�� ���������� ����.
	if (isLeftPressed == true || isRightPressed == true)
	{
		this->startMovingCharacter();
	}
	if (isAttackPressed == true || isSkillPressed == true)
	{
		this->startAttackCharacter();
	}

	return true;
}

// ��ġ ��
void GameMaker::onTouchMoved(Touch* touch, Event* event)
{
	// ���� ��ġ üũ
	if (isLeftPressed == true && this->isTouchInside(leftSprite, touch) == false)
	{
		isLeftPressed = false;
		isRight = false;
		this->stopMovingCharacter();
	}
	else if (isLeftPressed == false && this->isTouchInside(leftSprite, touch) == true)
	{
		isLeftPressed = true;
		isRight = false;
		this->startMovingCharacter();
	}
	// ������ ��ġ üũ
	if (isRightPressed == true && this->isTouchInside(rightSprite, touch) == false)
	{
		isRightPressed = false;
		isRight = true;
		this->stopMovingCharacter();
	}
	else if (isRightPressed == false && this->isTouchInside(rightSprite, touch) == true)
	{
		isRightPressed = true;
		isRight = true;
		this->startMovingCharacter();
	}
	// ���� ��ġ üũ
	if (isAttackPressed == true && this->isTouchInside(attackSprite, touch) == false)
	{
		isAttackPressed = false;
		this->stopAttackCharacter();
	}
	// ��ų ��ġ üũ
	if (isSkillPressed == true)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->isTouchInside(skillSprite[i], touch) == false)
			{
				isSkillPressed = false;
				this->stopAttackCharacter();
			}
		}
	}
}

// ��ġ ����
void GameMaker::onTouchEnded(Touch* touch, Event* event)
{
	//������ & ���� ����.
	if (isLeftPressed == true || isRightPressed == true)
	{
		isLeftPressed = false;
		isRightPressed = false;
		this->stopMovingCharacter();
	}
	else if (isAttackPressed == true || isSkillPressed == true)
	{
		isAttackPressed = false;
		isSkillPressed = false;
		this->stopAttackCharacter();
	}
}

// ��ġ Ȯ��.
bool GameMaker::isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch)
{
	auto touchPoint = touch->getLocation();
	bool bTouch = sprite->getBoundingBox().containsPoint(touchPoint);
	return bTouch;
}

// ĳ���� �̵�����.
void GameMaker::startMovingCharacter()
{
	log("Start moving");
	this->schedule(schedule_selector(GameMaker::moveCharacter));
}

// ĳ���� �̵�����.
void GameMaker::stopMovingCharacter()
{
	log("Stop moving");
	this->unschedule(schedule_selector(GameMaker::moveCharacter));
}

// ĳ���� �̵�����
void GameMaker::moveCharacter(float t)
{
	auto moveStep = 5;
	if (isLeftPressed == true)
	{
		moveStep = -5;
		characterSprite->setFlippedX(false);
	}
	else
	{
		moveStep = 5;
		characterSprite->setFlippedX(true);
	}

	auto newPos = Point(characterSprite->getPosition().x + moveStep, characterSprite->getPosition().y);

	if (newPos.x < 0)
	{
		newPos.x = 0;
	}
	else if (newPos.x > 1280 * 2)
	{
		newPos.x = 1280 * 2;
	}

	characterSprite->setPosition(newPos);
}

// ĳ���� ���ݽ���.
void GameMaker::startAttackCharacter()
{
	log("Start Attack");
	this->schedule(schedule_selector(GameMaker::attackCharacter), 0.6f);
}

// ĳ���� ��������.
void GameMaker::stopAttackCharacter()
{
	log("Stop Attack");
	this->unschedule(schedule_selector(GameMaker::attackCharacter));
}

// ĳ���� ���ݱ���
void GameMaker::attackCharacter(float t)
{
	log("Attack");
	this->createWeapon();
}


// ���� ������ġ ����.
void GameMaker::setFirstPositionWeapon(Sprite* sprite)
{
	auto newPos = convertToNodeSpace(characterSprite->getPosition());
	log("%f", newPos.x);
	sprite->setPosition(newPos);
}

// ���� ����.
void GameMaker::createWeapon()
{
	//���� ���� ����->player�� ���� �����̿�.
	Weapon* weapon = Weapon::createWithType(0);
	Point* newPos;

	//������ �ʱ� ��ġ ����.
	this->setFirstPositionWeapon(weapon->getweaponBody());

	//�ɸ��Ͱ� �ٶ󺸴� ���� üũ.
	if (isRight == false)
	{
		weapon->setRange(-(weapon->xPos), weapon->yPos);
		newPos = weapon->getRange();
		weapon->getweaponBody()->setRotation(-90);
	}
	else if (isRight == true)
	{
		newPos = weapon->getRange();
		weapon->getweaponBody()->setRotation(90);
	}

	//���Ⱑ �ٰŸ����� ���Ÿ����� üũ.
	if (false == weapon->getIsShortDistance())
	{

		MoveBy* moveby = MoveBy::create(weapon->getSpeedOfAttack(), *newPos);
		CallFuncN* callfunc = CallFuncN::create(CC_CALLBACK_1(GameMaker::WeaponRemover, this));
		Sequence* sequence = Sequence::create(moveby, callfunc, NULL);
		weapon->getweaponBody()->runAction(sequence);
		this->addWeaponList(weapon);

		backgroundLayer->addChild(weapon->getweaponBody());
	}
	else if (true == weapon->getIsShortDistance())
	{

	}
}

// ���� vector�� �߰�.
void GameMaker::addWeaponList(Weapon* weapon)
{
	arrWeapon.push_back(weapon);
}

// ���� �׼� �Ϸ�� ����.
void GameMaker::WeaponRemover(Node* sender)
{
	Weapon* weapon = NULL;
	for (std::vector<Weapon*>::iterator iter = arrWeapon.begin(); iter != arrWeapon.end(); iter++)
	{
		weapon = (Weapon*)*iter;
		if (weapon->getweaponBody() == sender)
		{
			arrWeapon.erase(iter);
			log("weapon delete");
			break;
		}
		weapon = NULL;
	}
	if (NULL != weapon)
	{
		weapon->release();
		delete weapon;
	}
}

//����� ����� �Լ�.
void GameMaker::createBackgroundParallax()
{
	//�������� ��� ����. ->player�� stage�����̿�.
	background = Background::creaeteWithType(0);
	//ParallaxNode �ޱ�.
	auto voidNode = background->getParallaxNode();
	//ParallaxNode �߰�.
	backgroundLayer->addChild(voidNode, 0);
}

// �÷��̾� ��ġ ���� �Լ�.
void GameMaker::setPositionPlayer()
{
	characterSprite = Player::getInstance()->getCharacter();
	characterSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
}

// ���� ������ġ ����.
void GameMaker::setFirstPositionMonster(Sprite* sprite)
{
	std::random_device rd;
	std::mt19937 rEngine(rd());
	std::uniform_int_distribution<> dist(0, 2500);
	auto result = dist(rEngine);
	float xPos = result;//rand() % (1280 * 2);
	float yPos = (winSize.height / 2) - 20;
	sprite->setPosition(Point(xPos, yPos));
	sprite->setAnchorPoint(Point(0.5, 0.5));
}

// ���� ����.
void GameMaker::createMonster(float t)
{
	Monster* monster = Monster::createWithType(0);

	this->setFirstPositionMonster(monster->getMonsterBody());
	float distance = monster->getMonsterBody()->getPositionX();
	float movetime = distance / monster->getSpeedOfMove();
	this->moveToCastle(monster->getMonsterBody(), movetime);
	this->addMonsterList(monster);
	backgroundLayer->addChild(monster->getMonsterBody());
}

//���� vector�� �߰�.
void GameMaker::addMonsterList(Monster* monster)
{
	if (true == monster->getIsEnermy())
		arrMonster.push_back(monster);
}

//���� �׼� �Ϸ�� ����.
void GameMaker::monsterRemover(Node* sender)
{
	Monster* monster = NULL;
	for (std::vector<Monster*>::iterator iter = arrMonster.begin(); iter != arrMonster.end(); iter++)
	{
		monster = (Monster*)*iter;
		if (monster->getMonsterBody() == sender)
		{
			arrMonster.erase(iter);
			log("Monster delete");
			break;
		}
		monster = NULL;
	}
	if (NULL != monster)
	{
		monster->release();
		delete monster;
	}
}

//���� ������ �̵�.
void GameMaker::moveToCastle(Sprite* sprite, float movetime)
{
	auto newPos = Point(0, sprite->getPositionY());
	MoveTo* moveTo = MoveTo::create(movetime, newPos);
	CallFuncN* callfunc = CallFuncN::create(CC_CALLBACK_1(GameMaker::monsterRemover, this));
	Sequence* sequence = Sequence::create(moveTo, callfunc, NULL);
	sprite->runAction(sequence);
}

//���� player������ �̵�
void GameMaker::moveToPlayer(Sprite* sprite, float movetime)
{
	auto playerCharacter = Player::getInstance()->getCharacter();
	auto newPos = Point(playerCharacter->getPosition().x, playerCharacter->getPosition().y);

	MoveTo* moveTo = MoveTo::create(movetime, newPos);
	CallFuncN* callfunc = CallFuncN::create(CC_CALLBACK_1(GameMaker::monsterRemover, this));
	Sequence* sequence = Sequence::create(moveTo, callfunc, NULL);
	sprite->runAction(sequence);
}

//����� ���� �浹 �˻�
void GameMaker::checkCollision(float t)
{
	Weapon* weapon = NULL;
	Monster* monster = NULL;
	
	for (std::vector<Weapon*>::iterator iterWeapon = arrWeapon.begin(); iterWeapon != arrWeapon.end(); iterWeapon++)
	{
		weapon = (Weapon*)*iterWeapon;

		bool bHit = false;
		for (std::vector<Monster*>::iterator iterMonster = arrMonster.begin(); iterMonster != arrMonster.end(); iterMonster++)
		{
			monster = (Monster*)*iterMonster;

			Rect boundingBox = monster->getMonsterBody()->getBoundingBox();
			if (boundingBox.containsPoint(weapon->getweaponBody()->getPosition()))
			{
				bHit = true;
				if (0 >= monster->subEnergy(weapon->getDamage()))
				{
					monster->release();
					delete monster;
					iterMonster = arrMonster.erase(iterMonster);
					if (iterMonster == arrMonster.end())
						break;
				}
				else
				{

				}
				break;
			}
		}
		if (true == bHit)
		{
			weapon->release();
			delete weapon;
			iterWeapon = arrWeapon.erase(iterWeapon);
			if (iterWeapon == arrWeapon.end())
				break;
		}
	}
}