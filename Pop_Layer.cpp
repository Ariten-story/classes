#include "Pop_Layer.h"


bool PopLayer::init()
{
	if (!CCLayerColor::initWithColor(ccc4(0, 0, 0, 0)))  //�����ϰ�
	{
		return false;
	}

	winSize = CCDirector::sharedDirector()->getWinSize();

	//�޴��߰�

	CCMenuItemFont* pMenuItem = CCMenuItemFont::create("close", this,menu_selector(PopLayer::doClose));
	pMenuItem->setColor(ccc3(0, 0, 0));
	CCMenu* pMenu2 = CCMenu::create(pMenuItem, NULL);
	pMenu2->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(pMenu2, 10);


	//backLayer�߰�
	backLayer = CCLayerColor::create(ccc4(0, 0, 0, 50), winSize.width, winSize.height);
	backLayer->setAnchorPoint(ccp(0, 0));
	backLayer->setPosition(ccp(0, 0));
	this->addChild(backLayer);


	return true;

}



void PopLayer::doClose(CCObject* pSender)
{
	CCDirector::sharedDirector()->resume();
	//�˾�â ����
	this->removeFromParentAndCleanup(true);
	auto kScene = GameIntro::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, kScene));
}