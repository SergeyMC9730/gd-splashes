#define CAC_PROJ_NAME "GDSplashes"

#if __APPLE__
	#include <CacKit>
	using namespace cocos2d;
#else
	#include "win32cac.h"
#endif

class $implement(MenuLayer, MainLayer) {
 public:
	static inline bool (__thiscall* _init)(MenuLayer* self);

	void buttonCallback(CCObject* sender) {
		auto alert = FLAlertLayer::create(NULL, "Mod", "Ok", NULL, "<cg>custom button!</c>");
		alert->show();
	}

	bool inithook() {
		if (!_init(this)) return false;

		auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_gkBtn_001.png");

		auto button = CCMenuItemSpriteExtra::create(
		    buttonSprite,
		    this,
		    menu_selector(MainLayer::buttonCallback)
		);

		auto test = CCLabelBMFont::create("Splash", "bigFont.fnt");

    	test->setPosition({200, 100});
    	test->setRotation(45);
		test->setZOrder(2);

		addChild(test);

		auto menu = CCMenu::create();
		menu->addChild(button);
		menu->setPosition(ccp(135, 44));

		addChild(menu);
		return true;
	}

	#if __APPLE__
	bool init() {return inithook();}
	#endif
};

void inject() {
	#if _WIN32
	auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));

	MH_CreateHook(
	    reinterpret_cast<void*>(base + 0x1907b0),
		reinterpret_cast<void*>(extract(&MainLayer::inithook)),
	    reinterpret_cast<void**>(&MainLayer::_init));

	MH_EnableHook(MH_ALL_HOOKS);
	#endif
}

#if _WIN32
	WIN32CAC_ENTRY(inject)
#endif
