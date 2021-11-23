#pragma once

#include "win32cac.h"

class DebugLayer : public CCLayer {
protected:
    virtual bool init();
    virtual void keyBackClicked();
    void backButtonCallback(CCObject*);
public:
    static DebugLayer* create();
    void switchToLayer(CCObject*);
    void DebugLayer::errorNotImplemented(CCObject* sender);
    void DebugLayer::test(CCObject* sender);
};
