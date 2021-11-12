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

bool ToolsLayer::init() {
    auto label = CCLabelBMFont::create("Hello world!", "bigFont.fnt");

    label->setPosition({200, 100});
    label->setRotation(45);

    addChild(label);

    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();
    
    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({100, 100, 100});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(ToolsLayer::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

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