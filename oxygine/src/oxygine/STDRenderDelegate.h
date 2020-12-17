#pragma once
#include "oxygine-include.h"
#include "RenderDelegate.h"
#include "STDRenderer.h"

#define ADRIEN
#define MULTITHREADED false
#define NUMTHREADS 1

namespace oxygine
{
    DECLARE_SMART(STDRenderDelegate, spSTDRenderDelegate);
    class STDRenderDelegate : public RenderDelegate
    {
    public:
        static STDRenderDelegate* instance;

        STDRenderDelegate() {}

        void render(ClipRectActor*,     const RenderState& rs) override;
        void render(MaskedSprite*,      const RenderState& rs) override;
        void doRender(Sprite*,          const RenderState& rs) override;
        void doRender(TextField*,       const RenderState& rs) override;
        void doRender(ColorRectSprite*, const RenderState& rs) override;
        void doRender(ProgressBar*,     const RenderState& rs) override;
#if defined(ADRIEN)
        void renderBeforeThreaded(Actor* parent, const RenderState& parentRS, bool updateCopy) override;
        void renderThreaded(Actor* parent, const RenderState& parentRS);
#endif


    protected:
    };

}