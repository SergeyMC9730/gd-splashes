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

void ToolsLayer::errorNotImplemented(CCObject* sender){
	auto alert = FLAlertLayer::create(NULL, "Not implemented", "OK", NULL, "Button functionality is not implemented yet.");
	alert->show();
}
void ToolsLayer::errorPermissionDenied(CCObject* sender){
    auto alert = FLAlertLayer::create(NULL, "Permission Denied", "OK", NULL, "You haven't enough permissons to set execute this tool!");
    alert->show();
}
void ToolsLayer::toiletAction(CCObject* sender) {
    auto FMODSND = FMODAudioEngine::sharedEngine();
    FMODSND->playBackgroundMusic("Resources/Tada.mp3", false, false);
}

bool ToolsLayer::init() {
    auto gdps = CCLabelBMFont::create("GDPS Tools", "goldFont.fnt");

    gdps->setPosition(ccp(120, 296));
    gdps->setScale(0.775f);

    addChild(gdps);

    auto ReuploadSongSprite = CCSprite::create("ReuploadSong.png");
	auto SetAsEModSprite = CCSprite::create("SetAsEMod.png");
	auto SetAsSModSprite = CCSprite::create("SetAsSMod.png");
    auto PasswordSprite = CCSprite::create("Password.png");
	auto EMailSprite = CCSprite::create("EMail.png");
	auto UsernameSprite = CCSprite::create("Username.png");
    auto UnmodSprite = CCSprite::create("Unmod.png");
    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    auto BackSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    auto ToiletSprite = CCSprite::create("Toilet.png");

    SetAsEModSprite->setColor(AccessDenied);
    SetAsSModSprite->setColor(AccessDenied);
    UnmodSprite->setColor(NotImplemented);
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto &size = backgroundSprite->getContentSize();

    gd::CCMenuItemSpriteExtra* Toilet = CCMenuItemSpriteExtra::create(
        ToiletSprite,
        this,
        menu_selector(ToolsLayer::toiletAction)
    );
    gd::CCMenuItemSpriteExtra *ReuploadSong = CCMenuItemSpriteExtra::create(
		ReuploadSongSprite,
		this,
		menu_selector(ToolsLayer::errorNotImplemented)
	);
    gd::CCMenuItemSpriteExtra *SetAsEMod = CCMenuItemSpriteExtra::create(
		SetAsEModSprite,
		this,
		menu_selector(ToolsLayer::errorPermissionDenied)
	);
    gd::CCMenuItemSpriteExtra *SetAsSMod = CCMenuItemSpriteExtra::create(
		SetAsSModSprite,
		this,
		menu_selector(ToolsLayer::errorPermissionDenied)
	);
    gd::CCMenuItemSpriteExtra *Username = CCMenuItemSpriteExtra::create(
		UsernameSprite,
		this,
		menu_selector(ToolsLayer::errorNotImplemented)
	);
    gd::CCMenuItemSpriteExtra *EMail = CCMenuItemSpriteExtra::create(
		EMailSprite,
		this,
		menu_selector(ToolsLayer::errorNotImplemented)
	);
    gd::CCMenuItemSpriteExtra *Password = CCMenuItemSpriteExtra::create(
		PasswordSprite,
		this,
		menu_selector(ToolsLayer::errorNotImplemented)
	);
    gd::CCMenuItemSpriteExtra *Unmod = CCMenuItemSpriteExtra::create(
		UnmodSprite,
		this,
		menu_selector(ToolsLayer::errorPermissionDenied)
	);

    auto ReuploadSongLabel = CCLabelBMFont::create("Reupload Song", "bigFont.fnt");
    auto SetAsEModLabel = CCLabelBMFont::create("Set Elder", "bigFont.fnt");
    auto SetAsSModLabel = CCLabelBMFont::create("Set Mod", "bigFont.fnt");
    auto PasswordLabel = CCLabelBMFont::create("Password", "bigFont.fnt");
    auto EMailLabel = CCLabelBMFont::create("EMail", "bigFont.fnt");
    auto UsernameLabel = CCLabelBMFont::create("Username", "bigFont.fnt");
    auto UnmodLabel = CCLabelBMFont::create("Unmod", "bigFont.fnt");

    ReuploadSongLabel->setPosition(ccp(48, 21));
    SetAsEModLabel->setPosition(ccp(48, 23));
    SetAsSModLabel->setPosition(ccp(48, 24));
    PasswordLabel->setPosition(ccp(48, 23));
    EMailLabel->setPosition(ccp(48, 26));
    UsernameLabel->setPosition(ccp(48, 23));
    UnmodLabel->setPosition(ccp(48, 26));

    ReuploadSongLabel->setScale(.325f);
    SetAsEModLabel->setScale(.45f);
    SetAsSModLabel->setScale(.525f);
    PasswordLabel->setScale(.5f);
    EMailLabel->setScale(.7f);
    UsernameLabel->setScale(.475f);
    UnmodLabel->setScale(.7f);

    SetAsEModLabel->setColor({0x42, 0x41, 0x41});
    SetAsSModLabel->setColor({0x42, 0x41, 0x41});
    UnmodLabel->setColor({0x42, 0x41, 0x41});

    ReuploadSong->addChild(ReuploadSongLabel);
    SetAsEMod->addChild(SetAsEModLabel);
    SetAsSMod->addChild(SetAsSModLabel);
    Username->addChild(UsernameLabel);
    EMail->addChild(EMailLabel);
    Password->addChild(PasswordLabel);
    Unmod->addChild(UnmodLabel);
    
    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({2, 128, 255});
    
    backgroundSprite->setZOrder(-2);
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
    CCMenu* UsernameMenu = CCMenu::create();
    CCMenu* EMailMenu = CCMenu::create();
    CCMenu* PasswordMenu = CCMenu::create();
    CCMenu* UnmodMenu = CCMenu::create();
    CCMenu* ToiletMenu = CCMenu::create();
    CCMenu* TestMenu = CCMenu::create();

    ReuploadSongMenu->addChild(ReuploadSong);
	ReuploadSongMenu->setPosition(ccp(73, 183));
	ReuploadSongMenu->setScale(.8f);

    SetAsEModMenu->addChild(SetAsEMod);
	SetAsEModMenu->setPosition(ccp(167, 183));
	SetAsEModMenu->setScale(.8f);

    SetAsSModMenu->addChild(SetAsSMod);
	SetAsSModMenu->setPosition(ccp(257, 183));
	SetAsSModMenu->setScale(.8f);

    UsernameMenu->addChild(Username);
	UsernameMenu->setPosition(ccp(73, 93));
	UsernameMenu->setScale(.8f);

    EMailMenu->addChild(EMail);
	EMailMenu->setPosition(ccp(167, 93));
	EMailMenu->setScale(.8f);

    UnmodMenu->addChild(Unmod);
	UnmodMenu->setPosition(ccp(257, 93));
	UnmodMenu->setScale(.8f);

    PasswordMenu->addChild(Password);
	PasswordMenu->setPosition(ccp(347, 183));
	PasswordMenu->setScale(.8f);

    ToiletMenu->addChild(Toilet);
    ToiletMenu->setPosition(ccp(444, -5));
    ToiletMenu->setScale(.7f);

    ToolButtonsMenu->setPosition(ccp(0, 0));
    ToolButtonsMenu->addChild(ReuploadSongMenu);
    ToolButtonsMenu->addChild(SetAsEModMenu);
    ToolButtonsMenu->addChild(SetAsSModMenu);
    ToolButtonsMenu->addChild(UsernameMenu);
    ToolButtonsMenu->addChild(EMailMenu);
    ToolButtonsMenu->addChild(PasswordMenu);
    ToolButtonsMenu->addChild(UnmodMenu);
    ToolButtonsMenu->addChild(ToiletMenu);
    ToolButtonsMenu->setZOrder(-1);

    addChild(menu);
    addChild(ToolButtonsMenu);

    setKeypadEnabled(true);

    return true;
}

void ToolsLayer::keyBackClicked() {
    auto FMODSND = FMODAudioEngine::sharedEngine();
    FMODSND->playBackgroundMusic("Resources/menuLoop.mp3", true, false);
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void ToolsLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void ToolsLayer::switchToLayer(CCObject* object) {
    switch (GameManager::sharedState()->getGameVariable("isGDPSopen")) {
        case true: {
            auto FMODSND = FMODAudioEngine::sharedEngine();
            FMODSND->playBackgroundMusic("Resources/menuLoop.mp3", true, false);

            auto layer = ToolsLayer::create();
            auto scene = CCScene::create();
            scene->addChild(layer);

            auto transition = CCTransitionFade::create(0.5f, scene);

            CCDirector::sharedDirector()->pushScene(transition);
            break;
        }
        case false: {
            auto alert = FLAlertLayer::create(NULL, "This is a secret...", "OK", NULL, "You need to enter the <co>Devpassword</c> to open <cg>GDPS Tools</c>");
            alert->show();
        }
    }
}