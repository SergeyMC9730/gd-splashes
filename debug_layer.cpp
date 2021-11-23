#include "debug_layer.hpp"
#include "hash.hpp"

CCTextInputNode *t1prt;
CCLabelBMFont *t2ptr;

DebugLayer* DebugLayer::create() {
    auto ret = new DebugLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

void DebugLayer::errorNotImplemented(CCObject* sender){
	auto alert = FLAlertLayer::create(NULL, "Not implemented", "OK", NULL, "Button functionality is not implemented yet.");
	alert->show();
}
void DebugLayer::test(CCObject* sender) {
    signed int hash = Hash::get(t1prt->getString());

    switch(hash){
    case 1738280: {
        auto alert1 = FLAlertLayer::create(NULL, "Success!", "OK", NULL, "<co>GDPS Tools</c> is <cg>opened!</c>");
        alert1->show();
        GameManager::sharedState()->setGameVariable("isGDPSopen", true);
        break;
    }
    case -1411843697: {
        auto alert1 = FLAlertLayer::create(NULL, "Success!", "OK", NULL, "<co>GDPS Tools</c> is <cg>disabled!</c>");
        alert1->show();
        GameManager::sharedState()->setGameVariable("isGDPSopen", false);
        break;
    }
    default: {
        auto alert1 = FLAlertLayer::create(NULL, "Error", "OK", NULL, "<cx>Incorrect password</c>");
        alert1->show();
        break;
    }
    }
    //NetworkGD::debug_write("https://google.com", "debug.txt");
}

bool DebugLayer::init() {
    t1prt = CCTextInputNode::create("Enter a password...", nullptr, "goldFont.fnt", 128, 64);
    t2ptr = CCLabelBMFont::create(" ", "bigFont.fnt");

    t1prt->setPosition(ccp(103, 228));
    t2ptr->setPosition(ccp(192, 201));
    t2ptr->setScale(.55f);

    CCLabelBMFont* gdps = CCLabelBMFont::create("Debug Menu", "goldFont.fnt");

    gdps->setPosition(ccp(120, 296));
    gdps->setScale(0.775f);

    addChild(gdps);

    auto TestSprite = CCSprite::create("Unmod.png");
    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    auto BackSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto &size = backgroundSprite->getContentSize();

    gd::CCMenuItemSpriteExtra* TestA = CCMenuItemSpriteExtra::create(
        TestSprite,
        this,
        menu_selector(DebugLayer::test)
    );

    addChild(t2ptr);
    
    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({2, 128, 255});
    
    backgroundSprite->setZOrder(-2);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(
        BackSprite,
        this,
        menu_selector(DebugLayer::backButtonCallback)
    );

    CCMenu* menu = CCMenu::create();
    menu->addChild(button);
    menu->setPosition({25, winSize.height - 25});

    CCMenu* TestMenu = CCMenu::create();
    CCMenu* ToolButtonsMenu = CCMenu::create();

    TestMenu->addChild(TestA);
    TestMenu->setPosition(ccp(435, 223));
    TestMenu->setScale(.7f);

    ToolButtonsMenu->setPosition(ccp(0, 0));
    ToolButtonsMenu->addChild(TestMenu);
    ToolButtonsMenu->setZOrder(-1);

    addChild(menu);
    addChild(ToolButtonsMenu);

    t1prt->setPosition(ccp(146, 38));
    addChild(t1prt);

    setKeypadEnabled(true);

    return true;
}

void DebugLayer::keyBackClicked() {
    auto FMODSND = FMODAudioEngine::sharedEngine();
    FMODSND->playBackgroundMusic("Resources/menuLoop.mp3", true, false);
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void DebugLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void DebugLayer::switchToLayer(CCObject* object) {
    auto FMODSND = FMODAudioEngine::sharedEngine();
    FMODSND->playBackgroundMusic("Resources/menuLoop.mp3", true, false);

    auto layer = DebugLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);

    auto transition = CCTransitionFade::create(0.5f, scene);

    CCDirector::sharedDirector()->pushScene(transition);
}