#pragma once
#include "test.h"


extern Resources resources;

class PerfTest: public Test
{
public:
    spButton button;
    int count;
    bool _tweenAnim;
    bool _tweenRot;
    bool _tweenScale;

    PerfTest()
    {
        _tweenAnim = false;
        _tweenRot = false;
        _tweenScale = false;
        count = 0;
        addButton("add", "add 25000");
        addButton("animate", "animate");
        addButton("scale0.01", "scale=0.01");
        addButton("scale0.2", "scale=0.2");
        addButton("scale0.5", "scale=0.5");

        toggle dr[] = {toggle("driver=null", 0, new VideoDriverNull), toggle("driver=default", 0, 0)};
        addToggle("driver", dr, 2);

        _content->setTouchEnabled(false);
        _content->setTouchChildrenEnabled(false);

#if defined(ADRIEN)
        _contentCopy->setTouchEnabled(false);
        _contentCopy->setTouchChildrenEnabled(false);
#endif

    }

    void toggleClicked(string id, const toggle* data)
    {
        //if (id == "driver")
        //    content->driver = (IVideoDriver*)(data->data);
    }

    void clicked(string id)
    {
        if (id == "add")
        {
            int a = 25000;
            count += a;
            for (int i = 0; i < a; ++i)
            {
                spSprite sprite = new Sprite;
                sprite->setResAnim(resources.getResAnim("anim"));
                sprite->setAnchor(Vector2(0.5f, 0.5f));
                sprite->setSize(getStage()->getSize() / 20);
#if !defined(ADRIEN)
                sprite->setPosition(scalar::randFloat(0, (float)getWidth()), scalar::randFloat(0, (float)getHeight()));
#else
                Vector2 pos = Vector2(scalar::randFloat(0, (float)getWidth()), scalar::randFloat(0, (float)getHeight()));
                sprite->setPosition(pos);
#endif                
                _content->addChild(sprite);
#if defined(ADRIEN)
                sprite = new Sprite;
                sprite->setResAnim(resources.getResAnim("anim"));
                sprite->setAnchor(Vector2(0.5f, 0.5f));
                sprite->setSize(getStage()->getSize() / 20);
                sprite->setPosition(pos);
                _contentCopy->addChild(sprite);
#endif
            }

            char str[255];
            safe_sprintf(str, "add 25000 (%d)", count);
            updateText(id, str);
        }
        if (id == "scale0.01")
        {
            spActor child = _content->getFirstChild();
#if defined(ADRIEN)
            spActor childCopy = _contentCopy->getFirstChild();
#endif
            while (child)
            {
                child->setScale(Vector2(1, 1) * 0.01f);
                child = child->getNextSibling();
#if defined(ADRIEN)
                childCopy->setScale(Vector2(1, 1) * 0.01f);
                childCopy = childCopy->getNextSibling();
#endif
            }
        }
        if (id == "scale0.2")
        {
            spActor child = _content->getFirstChild();
#if defined(ADRIEN)
            spActor childCopy = _contentCopy->getFirstChild();          
#endif
            while (child)
            {
                child->setScale(Vector2(1, 1) * 0.2f);
                child = child->getNextSibling();
#if defined(ADRIEN)
                childCopy->setScale(Vector2(1, 1) * 0.2f);
                childCopy = childCopy->getNextSibling();
#endif
            }
        }

        if (id == "scale0.5")
        {
            spActor child = _content->getFirstChild();
#if defined(ADRIEN)
            spActor childCopy = _contentCopy->getFirstChild();
#endif
            while (child)
            {
                child->setScale(Vector2(1, 1) * 0.5f);
                child = child->getNextSibling();
#if defined(ADRIEN)
                childCopy->setScale(Vector2(1, 1) * 0.5f);
                childCopy = childCopy->getNextSibling();          
#endif
            }
        }

        if (id == "animate")
        {
            spActor child = _content->getFirstChild();
#if defined(ADRIEN)
            spActor childCopy = _contentCopy->getFirstChild();
#endif
            while (child)
            {
                spTween t = 0;
                if (!_tweenAnim)
                    t = createTween(TweenAnim(resources.getResAnim("anim")), 500, -1);
                else if (!_tweenRot)
                    t = createTween(Actor::TweenRotation((float)MATH_PI * 2.0f), 3000, -1);
                else if (!_tweenScale)
                    t = createTween(Actor::TweenScale(Vector2(0.2f, 0.2f)), 3000, -1, true);


                if (t)
                    child->addTween(t);
                child = child->getNextSibling();
#if defined(ADRIEN)
                t = 0;
                if (!_tweenAnim)
                    t = createTween(TweenAnim(resources.getResAnim("anim")), 500, -1);
                else if (!_tweenRot)
                    t = createTween(Actor::TweenRotation((float)MATH_PI * 2.0f), 3000, -1);
                else if (!_tweenScale)
                    t = createTween(Actor::TweenScale(Vector2(0.2f, 0.2f)), 3000, -1, true);
                
                if (t)
                    childCopy->addTween(t);
                childCopy = childCopy->getNextSibling();
#endif
            }

            if (!_tweenAnim)
                _tweenAnim = true;
            else
            {
                if (!_tweenRot)
                    _tweenRot = true;
                else if (!_tweenScale)
                {
                    updateText(id, "");
                    _tweenScale = true;
                }
            }
        }
    }

};