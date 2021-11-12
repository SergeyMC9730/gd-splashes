#define CAC_PROJ_NAME "GDSplashes"

#if __APPLE__
	#include <CacKit>
	using namespace cocos2d;
#else
	#include "win32cac.h"
#endif
#include "main.hpp"

class $implement(MenuLayer, MainLayer) {
 public:
	static inline bool (__thiscall* _init)(MenuLayer* self);

	void buttonCallback(CCObject* sender) {
		auto alert = FLAlertLayer::create(NULL, "Mod", "Ok", NULL, "<cg>custom button!</c>");
		alert->show();
	}

	bool inithook() {
		if (!_init(this)) return false;

		CCSprite* AppStoreGamesSprite = CCSprite::createWithSpriteFrameName("GJ_gkBtn_001.png");
		CCSprite* YouTubeTrailerSprite = CCSprite::createWithSpriteFrameName("GJ_trailerBtn_001.png");
		CCSprite* GooglePlusSprite  = CCSprite::createWithSpriteFrameName("GJ_gpBtn_001.png");
		CCSprite* GooglePlayGamesSprite = CCSprite::createWithSpriteFrameName("GJ_gpgBtn_001.png");

		gd::CCMenuItemSpriteExtra *AppStoreGames = CCMenuItemSpriteExtra::create(
		    AppStoreGamesSprite,
		    this,
		    menu_selector(MainLayer::buttonCallback)
		);

		gd::CCMenuItemSpriteExtra *YouTubeTrailer = CCMenuItemSpriteExtra::create(
		    YouTubeTrailerSprite,
		    this,
		    menu_selector(MainLayer::buttonCallback)
		);

		gd::CCMenuItemSpriteExtra *GooglePlus = CCMenuItemSpriteExtra::create(
		    GooglePlusSprite,
		    this,
		    menu_selector(MainLayer::buttonCallback)
		);

		gd::CCMenuItemSpriteExtra *GooglePlayGames = CCMenuItemSpriteExtra::create(
		    GooglePlayGamesSprite,
		    this,
		    menu_selector(MainLayer::buttonCallback)
		);

		CCLabelBMFont * test = CCLabelBMFont::create("Splash", "bigFont.fnt");

    	test->setPosition({436, 253});
    	test->setRotation(11);
		test->setZOrder(2);

		addChild(test);

		CCMenu* menuIcons = CCMenu::create();

		CCMenu* AppStoreGamesMenu = CCMenu::create();
		AppStoreGamesMenu->addChild(AppStoreGames);
		AppStoreGamesMenu->setPosition(ccp(114, 16));
		AppStoreGamesMenu->setScale(.8f);

		CCMenu* youtubeTrailerMenu = CCMenu::create();
		youtubeTrailerMenu->addChild(YouTubeTrailer);
		youtubeTrailerMenu->setPosition(ccp(442, 49));
		youtubeTrailerMenu->setScale(.8f);

		CCMenu* GooglePlusMenu = CCMenu::create();
		GooglePlusMenu->addChild(GooglePlus);
		GooglePlusMenu->setPosition(ccp(114, 26));
		GooglePlusMenu->setScale(.8f);

		CCMenu* GooglePlayGamesMenu = CCMenu::create();
		GooglePlayGamesMenu->addChild(GooglePlayGames);
		GooglePlayGamesMenu->setPosition(ccp(442, 59));
		GooglePlayGamesMenu->setScale(.8f);

		menuIcons->addChild(AppStoreGamesMenu);
		menuIcons->addChild(youtubeTrailerMenu);
		menuIcons->addChild(GooglePlusMenu);
		menuIcons->addChild(GooglePlayGamesMenu);

		menuIcons->setPosition(ccp(0, 0));

		addChild(menuIcons);

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
	    reinterpret_cast<void*>(base + MenuLayerOffset),
		reinterpret_cast<void*>(extract(&MainLayer::inithook)),
	    reinterpret_cast<void**>(&MainLayer::_init));

	MH_EnableHook(MH_ALL_HOOKS);
	#endif
}

#if _WIN32
	WIN32CAC_ENTRY(inject)
#endif
