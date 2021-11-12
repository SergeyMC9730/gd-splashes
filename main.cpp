#define CAC_PROJ_NAME "GDSplashes"

#if __APPLE__
	#include <CacKit>
	using namespace cocos2d;
#else
	#include "win32cac.h"
#endif
#include "main.hpp"

class $implement(ProfilePage, ProfilePageLayer){
 public:
	static inline bool (__thiscall* _init)(ProfilePage* self);

	void errorNotImplemented(CCObject* sender){
		auto alert = FLAlertLayer::create(NULL, "Not implemented", "OK", NULL, "Tools Page is not implemented yet.");
		alert->show();
	}

	bool profile(){
		if (!_init(this)) return false;

		CCSprite* ToolsPageSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");

		ToolsPageSprite->setColor({0x42, 0x41, 0x41});

		gd::CCMenuItemSpriteExtra *ToolsPage = CCMenuItemSpriteExtra::create(
		    ToolsPageSprite,
		    this,
		    menu_selector(ProfilePageLayer::errorNotImplemented)
		);

		CCMenu* ToolsPageMenu = CCMenu::create();
		ToolsPageMenu->addChild(ToolsPage);
		ToolsPageMenu->setPosition(ccp(95, -7));
		ToolsPageMenu->setScale(.8f);

		addChild(ToolsPageMenu);

		return true;
	}
};
class $implement(MenuLayer, MainLayer) {
 public:
	static inline bool (__thiscall* _init)(MenuLayer* self);

	void errorClosed(CCObject* sender){
		auto alert = FLAlertLayer::create(NULL, "Closed", "OK", NULL, "Google+ is currently closed by Google.");
		alert->show();
	}
	void errorNotImplemented(CCObject* sender){
		auto alert = FLAlertLayer::create(NULL, "Not implemented", "OK", NULL, "Tools Page is not implemented yet.");
		alert->show();
	}
	
	void youtubeTrailerLink(CCObject *sender){
		ShellExecute(0, 0, "https://www.youtube.com/watch?v=k90y6PIzIaE", 0, 0, SW_SHOW);
	}
	void GooglePlayGamesLink(CCObject *sender){
		ShellExecute(0, 0, "https://play.google.com/store/apps/details?id=com.robtopx.geometryjump", 0, 0, SW_SHOW);
	}
	void AppStoreLink(CCObject *sender){
		ShellExecute(0, 0, "https://apps.apple.com/app/geometry-dash/id625334537", 0, 0, SW_SHOW);
	}

	bool inithook() {
		
		if (!_init(this)) return false;

		CCSprite* AppStoreGamesSprite = CCSprite::createWithSpriteFrameName("GJ_gkBtn_001.png");
		CCSprite* YouTubeTrailerSprite = CCSprite::createWithSpriteFrameName("GJ_trailerBtn_001.png");
		CCSprite* GooglePlusSprite  = CCSprite::createWithSpriteFrameName("GJ_gpBtn_001.png");
		CCSprite* GooglePlayGamesSprite = CCSprite::createWithSpriteFrameName("GJ_gpgBtn_001.png");

		GooglePlusSprite->setColor({0x42, 0x41, 0x41});

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

		CCMenu* GooglePlusMenu = CCMenu::create();
		GooglePlusMenu->addChild(GooglePlus);
		GooglePlusMenu->setPosition(ccp(95, 35));
		GooglePlusMenu->setScale(.8f);

		CCMenu* GooglePlayGamesMenu = CCMenu::create();
		GooglePlayGamesMenu->addChild(GooglePlayGames);
		GooglePlayGamesMenu->setPosition(ccp(364, 35));
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
	    reinterpret_cast<void**>(&MainLayer::_init)
	);

	MH_CreateHook(
	    reinterpret_cast<void*(__fastcall*)(int, bool)>(base + ProfilePageOffset),
		reinterpret_cast<void*>(extract(&ProfilePageLayer::profile)),
	    reinterpret_cast<void**>(&ProfilePageLayer::_init)
	);

	MH_EnableHook(MH_ALL_HOOKS);
	#endif
}

#if _WIN32
	WIN32CAC_ENTRY(inject)
#endif
