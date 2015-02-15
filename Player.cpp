#include "Player.h"

Player::Player()
{
	characterBody = NULL;

	//hp라벨
	labelHP = Label::createWithSystemFont("", "", 100);
	//hp라벨
	
	maxEnergy = 0; //Player 최대HP.
	curEnergy = 0; //Player 현재HP.
	defensivePower = 0; //Player 방어력.
	speedOfMove = 0; //Player 이동속도.
	weaponType = 0; //Player가 가진 무기 type.
}
Player::~Player(){}

Player* Player::player = NULL;

Player* Player::getInstance()
{
	if (player == NULL)
		player = new Player();
	return player;
}

//캐릭터 생성 함수.
void Player::createWithType(int type)
{
	const char* fileName;
	if (type == 1)
	{
		fileName = "KnightChar.png";
		player->setEnergey(500);
		player->setDefensivePower(0);
		player->setSpeedOfMove(5);
	}
	else if (type == 2)
	{
		fileName = "KnightChar.png";
		player->setEnergey(500);
		player->setDefensivePower(0);
		player->setSpeedOfMove(5);
	}
	else if (type == 3)
	{
		fileName = "KnightChar.png";
		player->setEnergey(500);
		player->setDefensivePower(0);
		player->setSpeedOfMove(5);
	}
	
	auto characterBody = Sprite::create(fileName);
	player->setCharacter(characterBody);
	player->setHpBar();

	characterBody->retain();
}

//캐릭터 Sprite 생성&설정 함수.
void Player::setCharacter(Sprite* character)
{
	characterBody = character;
	characterBody->retain();
}

//캐릭터 Sprite 반환 함수.
Sprite* Player::getCharacter()
{
	return characterBody;
}

//플레이어 max에너지 설정 함수.
void Player::setEnergey(float max)
{
	maxEnergy = curEnergy = max;
}

//플레이어 받는피해처리 함수.
float Player::subEnergy(float damage)
{
	curEnergy -= damage;
	log("%f", curEnergy);
	if (curEnergy < 0)
	{

		labelHP->setString(StringUtils::format("%d", curEnergy));
	}
	else
	{

		labelHP->setString(StringUtils::format("%d", curEnergy));
	}
	return curEnergy;
}
//플레이어 에너지회복처리 함수.
float Player::plusEnergy(float heal)
{
	auto temp = curEnergy;
	
	if (curEnergy >= maxEnergy)
	{
		curEnergy = maxEnergy;
		log("heal %f", curEnergy);
		auto newWidth = characterBody->getContentSize().width;
	}
	else
	{
		curEnergy += heal;
		
	}
	return curEnergy;
}

//플레이어 현재 에너지 반환 함수.
float Player::getEnergey()
{
	return curEnergy;
}

//플레이어 방어력 설정 함수.
void Player::setDefensivePower(float defensive)
{
	defensivePower = defensive;
}

//플레이어 방어력 반환 함수.
float Player::getDefensivePower()
{
	return defensivePower;
}

//플레이어 이동속도 설정 함수.
void Player::setSpeedOfMove(float speed)
{
	speedOfMove = speed;
}

//플레이어 이동속도 반환 함수.
float Player::getSpeedOfMove()
{
	return speedOfMove;
}

//플레이어 에너지바 설정 함수.
void Player::setHpBar()
{
	//라벨초기화
	labelHP->setAnchorPoint(Point(0.5,0));
	labelHP->setPosition(Point(characterBody->getContentSize().width/2, characterBody->getContentSize().height));
	labelHP->setColor(Color3B::BLACK);
	labelHP->setString(StringUtils::format("%d", curEnergy));
	labelHP->setTag(123);
	characterBody->addChild(labelHP); //player캐릭터 재 선택시 오류가 생김 수정 필.
	//라벨초기화
}