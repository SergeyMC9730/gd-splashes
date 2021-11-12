#pragma once

#include "win32cac.h"

class ToolsLayer : public CCLayer {
protected:
    virtual bool init();
    virtual void keyBackClicked();
    void backButtonCallback(CCObject*);
public:
    static ToolsLayer* create();
    void switchToCustomLayerButton(CCObject*);
    ToolsLayer::errorNotImplemented(CCObject* sender);
    ToolsLayer::errorPermissionDenied(CCObject* sender);
};
