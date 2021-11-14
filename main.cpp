#define CAC_PROJ_NAME "GDSplashes"

#if __APPLE__
	#include <CacKit>
	using namespace cocos2d;
#else
	#include "win32cac.h"
	#include "tools_layer.hpp"
#endif
#include "main.hpp"

class $implement(MenuLayer, MainLayer) {
 public:
	static inline bool (__thiscall* _init)(MenuLayer* self);

	void errorClosed(CCObject* sender){
		auto alert = FLAlertLayer::create(NULL, "Closed", "OK", NULL, "Google+ is currently closed by Google.");
		alert->show();
	}
	void errorClosedB(CCObject* sender){
		auto alert = FLAlertLayer::create(NULL, "Closed", "OK", NULL, "Everyplay is currently closed by Unity.");
		alert->show();
	}
	void errorNotImplemented(CCObject* sender){
		auto alert = FLAlertLayer::create(NULL, "Not implemented", "OK", NULL, "Tools Page is not implemented yet.");
		alert->show();
	}
	
	void youtubeTrailerLink(CCObject *sender){
		CCApplication::sharedApplication()->openURL("https://www.youtube.com/watch?v=k90y6PIzIaE");
	}
	void youtubeTrailer22Link(CCObject *sender){
		CCApplication::sharedApplication()->openURL("https://www.youtube.com/watch?v=ipK7vQ8gEZw");
	}
	void GooglePlayGamesLink(CCObject *sender){
		CCApplication::sharedApplication()->openURL("https://play.google.com/store/apps/details?id=com.robtopx.geometryjump");
	}
	void AppStoreLink(CCObject *sender){
		CCApplication::sharedApplication()->openURL("https://apps.apple.com/app/geometry-dash/id625334537");
	}

	bool inithook() {
		
		if (!_init(this)) return false;

		CCSprite* AppStoreGamesSprite = CCSprite::createWithSpriteFrameName("GJ_gkBtn_001.png");
		CCSprite* YouTubeTrailerSprite = CCSprite::createWithSpriteFrameName("GJ_trailerBtn_001.png");
		CCSprite* GooglePlusSprite  = CCSprite::createWithSpriteFrameName("GJ_gpBtn_001.png");
		CCSprite* GooglePlayGamesSprite = CCSprite::createWithSpriteFrameName("GJ_gpgBtn_001.png");
		CCSprite* EveryplaySprite = CCSprite::createWithSpriteFrameName("GJ_everyplayBtn_001.png");
		CCSprite* ToolsSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");
		CCSprite* SneakPeakSprite = CCSprite::create("SneakPeek.png");

		GooglePlusSprite->setColor({0x42, 0x41, 0x41});
		EveryplaySprite->setColor({0x42, 0x41, 0x41});

		gd::CCMenuItemSpriteExtra *AppStoreGames = CCMenuItemSpriteExtra::create(
		    AppStoreGamesSprite,
		    this,
		    menu_selector(MainLayer::AppStoreLink)
		);

		gd::CCMenuItemSpriteExtra *YouTubeTrailer = CCMenuItemSpriteExtra::create(
		    YouTubeTrailerSprite,
		    this,
		    menu_selector(MainLayer::youtubeTrailerLink)
		);
		gd::CCMenuItemSpriteExtra *YouTubeTrailer22 = CCMenuItemSpriteExtra::create(
		    SneakPeakSprite,
		    this,
		    menu_selector(MainLayer::youtubeTrailer22Link)
		);

		gd::CCMenuItemSpriteExtra *GooglePlus = CCMenuItemSpriteExtra::create(
		    GooglePlusSprite,
		    this,
		    menu_selector(MainLayer::errorClosed)
		);

		gd::CCMenuItemSpriteExtra *GooglePlayGames = CCMenuItemSpriteExtra::create(
		    GooglePlayGamesSprite,
		    this,
		    menu_selector(MainLayer::GooglePlayGamesLink)
		);
		gd::CCMenuItemSpriteExtra *Everyplay = CCMenuItemSpriteExtra::create(
		    EveryplaySprite,
		    this,
		    menu_selector(MainLayer::errorClosedB)
		);
		gd::CCMenuItemSpriteExtra *Tools = CCMenuItemSpriteExtra::create(
		    ToolsSprite,
		    this,
		    menu_selector(ToolsLayer::switchToCustomLayerButton)
		);

		CCLabelBMFont * test = CCLabelBMFont::create("Splash", "bigFont.fnt");

    	test->setPosition({436, 253});
    	test->setRotation(11);
		test->setZOrder(2);

		addChild(test);

		CCMenu* menuIcons = CCMenu::create();

		CCMenu* AppStoreGamesMenu = CCMenu::create();
		AppStoreGamesMenu->addChild(AppStoreGames);
		AppStoreGamesMenu->setPosition(ccp(95, -7));
		AppStoreGamesMenu->setScale(.8f);

		CCMenu* youtubeTrailerMenu = CCMenu::create();
		youtubeTrailerMenu->addChild(YouTubeTrailer);
		youtubeTrailerMenu->setPosition(ccp(364, -7));
		youtubeTrailerMenu->setScale(.8f);

		CCMenu* youtubeTrailer22Menu = CCMenu::create();
		youtubeTrailer22Menu->addChild(YouTubeTrailer22);
		youtubeTrailer22Menu->setPosition(ccp(372, -28));
		youtubeTrailer22Menu->setScale(.67f);

		CCMenu* GooglePlusMenu = CCMenu::create();
		GooglePlusMenu->addChild(GooglePlus);
		GooglePlusMenu->setPosition(ccp(95, 35));
		GooglePlusMenu->setScale(.8f);

		CCMenu* GooglePlayGamesMenu = CCMenu::create();
		GooglePlayGamesMenu->addChild(GooglePlayGames);
		GooglePlayGamesMenu->setPosition(ccp(364, 35));
		GooglePlayGamesMenu->setScale(.8f);

		CCMenu* EveryplayMenu = CCMenu::create();
		EveryplayMenu->addChild(Everyplay);
		EveryplayMenu->setPosition(ccp(53, -7));
		EveryplayMenu->setScale(.8f);

		CCMenu* ToolsMenu = CCMenu::create();
		ToolsMenu->addChild(Tools);
		ToolsMenu->setPosition(ccp(408, 35));
		ToolsMenu->setScale(.8f);

		menuIcons->addChild(AppStoreGamesMenu);
		menuIcons->addChild(youtubeTrailerMenu);
		menuIcons->addChild(youtubeTrailer22Menu);
		menuIcons->addChild(GooglePlusMenu);
		menuIcons->addChild(GooglePlayGamesMenu);
		menuIcons->addChild(EveryplayMenu);
		menuIcons->addChild(ToolsMenu);

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
	    reinterpret_cast<void**>(&MainLayer::_init)
	);

	MH_EnableHook(MH_ALL_HOOKS);
	#endif
}

#if _WIN32
	WIN32CAC_ENTRY(inject)
#endif
