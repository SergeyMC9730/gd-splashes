#include "tools_layer.hpp"

ToolsLayer* ToolsLayer::create() {
    auto ret = new ToolsLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

void errorNotImplemented(CCObject* sender){
	auto alert = FLAlertLayer::create(NULL, "Not implemented", "OK", NULL, "Button functionality is not implemented yet.");
	alert->show();
}
void errorPermissionDenied(CCObject* sender){
    auto alert = FLAlertLayer::create(NULL, "Permission Denied", "OK", NULL, "You haven't enough permissons to set execute this tool!");
}

bool ToolsLayer::init() {

    auto gdps = CCLabelBMFont::create("GDPS Tools", "bigFont.fnt");

    gdps->setPosition(ccp(127, 296));
    gdps->setScale(0.625f)

    addChild(gdps);

    CCSprite* ReuploadSongSprite = CCSprite::create("ReuploadSong.png");
	CCSprite* SetAsEModSprite = CCSprite::create("SetAsEMod.png");
	CCSprite* SetAsSModSprite  = CCSprite::create("SetAsSMod.png");
    CCSprite* backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    ССSprite* BackSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");

    SetAsEModSprite->setColor({0x42, 0x41, 0x41});
    SetAsSModSprite->setColor({0x42, 0x41, 0x41});
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    gd::CCMenuItemSpriteExtra *ReuploadSong = CCMenuItemSpriteExtra::create(
		ReuploadSongSprite,
		this,
		menu_selector(errorNotImplemented)
	);
    gd::CCMenuItemSpriteExtra *SetAsEMod = CCMenuItemSpriteExtra::create(
		SetAsEModSprite,
		this,
		menu_selector(errorPermissionDenied)
	);
    gd::CCMenuItemSpriteExtra *SetAsSMod = CCMenuItemSpriteExtra::create(
		SetAsSModSprite,
		this,
		menu_selector(errorPermissionDenied)
	);

    auto ReuploadSongLabel = CCLabelBMFont::create("Reupload Song", "bigFont.fnt");
    auto SetAsEModLabel = CCLabelBMFont::create("Set Elder", "bigFont.fnt");
    auto SetAsSModLabel = CCLabelBMFont::create("Set Mod", "bigFont.fnt");

    ReuploadSongLabel->setPosition(ccp(72, 161));
    SetAsEModLabel->setPosition(ccp(166, 162));
    SetAsSModLabel->setPosition(ccp(256, 163));

    ReuploadSongLabel->setScale(.25f);
    SetAsEModLabel->setScale(.35f);
    SetAsSModLabel->setScale(.425f);

    addChild(ReuploadSongLabel);
    addChild(SetAsEModLabel);
    addChild(SetAsSModLabel);
    
    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({100, 100, 100});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(
        BackSprite,
        this,
        menu_selector(ToolsLayer::backButtonCallback)
    );

    CCMenu* menu = CCMenu::create();
    menu->addChild(button);
    menu->setPosition({25, winSize.height - 25});

    CCMenu* ToolButtonsMenu = CCMenu::create();
    CCMenu* ReuploadSongMenu = CCMenu::create();
    CCMenu* SetAsEModMenu = CCMenu::create();
    CCMenu* SetAsSModMenu = CCMenu::create();

    ReuploadSongMenu->addChild(ReuploadSong);
	ReuploadSongMenu->setPosition(ccp(73, 183));
	ReuploadSongMenu->setScale(.8f);

    SetAsEModMenu->addChild(SetAsEMod);
	SetAsEModMenu->setPosition(ccp(167, 183));
	SetAsEModMenu->setScale(.8f);

    SetAsSModMenu->addChild(SetAsSMod);
	SetAsSModMenu->setPosition(ccp(257, 183));
	SetAsSModMenu->setScale(.8f);

    ToolButtonsMenu->setPosition(ccp(0, 0));
    ToolButtonsMenu->addChild(ReuploadSongMenu);
    ToolButtonsMenu->addChild(SetAsEModMenu);
    ToolButtonsMenu->addChild(SetAsSModMenu);

    addChild(menu);
    addChild(ToolButtonsMenu);

    setKeypadEnabled(true);

    return true;
}

void ToolsLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void ToolsLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void ToolsLayer::switchToCustomLayerButton(CCObject* object) {
    auto layer = ToolsLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);

    auto transition = CCTransitionFade::create(0.5f, scene);

    CCDirector::sharedDirector()->pushScene(transition);
}