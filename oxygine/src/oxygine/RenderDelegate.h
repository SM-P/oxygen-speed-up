#pragma once
#include "oxygine-include.h"

#define ADRIEN

namespace oxygine
{
    class RenderDelegate
    {
    public:
        virtual ~RenderDelegate();

        virtual void render(Actor*, const RenderState& rs);
        virtual void render(ClipRectActor*, const RenderState& rs) {}
        virtual void render(MaskedSprite*, const RenderState& rs) {}
        virtual void doRender(Sprite*, const RenderState& rs) {}
        virtual void doRender(TextField*, const RenderState& rs) {}
        virtual void doRender(ColorRectSprite*, const RenderState& rs) {}
        virtual void doRender(ProgressBar*, const RenderState& rs) {}

#if defined(ADRIEN)
        virtual void renderBeforeThreaded(Actor* parent, const RenderState& parentRS, bool updateCopy) {}
        virtual void renderThreaded(Actor* parent, const RenderState& parentRS) {}
#endif
        
        static void setCurrent(void*) {}
    };
}