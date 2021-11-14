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
    void ToolsLayer::errorNotImplemented(CCObject* sender);
    void ToolsLayer::errorPermissionDenied(CCObject* sender);
    void ToolsLayer::toiletAction(CCObject* sender);
};
