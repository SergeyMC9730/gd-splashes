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

		auto splashOptionsSprite  = CCSprite::createWithSpriteFrameName("GJ_gkBtn_001.png");
		auto YouTubeTrailerSprite = CCSprite::createWithSpriteFrameName("GJ_trailerBtn_001.png");

		auto splashOptions = CCMenuItemSpriteExtra::create(
		    splashOptionsSprite,
		    this,
		    menu_selector(MainLayer::buttonCallback)
		);

		auto YouTubeTrailer = CCMenuItemSpriteExtra::create(
		    YouTubeTrailerSprite,
		    this,
		    menu_selector(MainLayer::buttonCallback)
		);

		auto test = CCLabelBMFont::create("Splash", "bigFont.fnt");

    	test->setPosition({436, 253});
    	test->setRotation(11);
		test->setZOrder(2);

		addChild(test);

		auto splashMenu = CCMenu::create();
		menu->addChild(splashOptions);
		menu->setPosition(ccp(145, 45));

		auto youtubeTrailerMenu = CCMenu::create();
		menu->addChild(YouTubeTrailer);
		menu->setPosition(ccp(427, 45));

		addChild(splashMenu);
		addChild(youtubeTrailerMenu);

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
