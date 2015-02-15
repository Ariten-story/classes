#include "Pop_Layer.h"


CCScene* PopLayer::createscene()
{

	CCScene *scene = CCScene::create();
	PopLayer *layer = PopLayer::create();


	scene->addChild(layer);

	return scene;
}


bool PopLayer::init()
{
	if (!CCLayerColor::initWithColor(ccc4(0, 0, 0, 0)))  //투명하게
	{
		return false;
	}

	winSize = CCDirector::sharedDirector()->getWinSize();

	//메뉴추가

	CCMenuItemFont* pMenuItem = CCMenuItemFont::create("close", this,menu_selector(PopLayer::doClose));
	pMenuItem->setColor(ccc3(0, 0, 0));
	CCMenu* pMenu2 = CCMenu::create(pMenuItem, NULL);
	pMenu2->setPosition(ccp(240, 100));
	this->addChild(pMenu2, 10);


	//backLayer추가
	backLayer = CCLayerColor::create(ccc4(0, 0, 0, 50), winSize.width, winSize.height);
	backLayer->setAnchorPoint(ccp(0, 0));
	backLayer->setPosition(ccp(0, 0));
	this->addChild(backLayer);

	//popUpLayer추가
	popUpLayer = CCLayerColor::create(ccc4(255, 0, 0, 255), 250, 150);
	popUpLayer->setAnchorPoint(ccp(0, 0));
	popUpLayer->setPosition(ccp((winSize.width - popUpLayer->getContentSize().width) / 2,(winSize.height - popUpLayer->getContentSize().height) / 2 ));
	this->addChild(popUpLayer);


	return true;

}



void PopLayer::doClose(CCObject* pSender)
{

	//팝업창 제거
	this->removeFromParentAndCleanup(true);

	auto pScene = GameIntro::createScene();
	CCTransitionScene* pTran = CCTransitionFade::create(1.0f, pScene);

	CCDirector::sharedDirector()->replaceScene(pTran);

}
