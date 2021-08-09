#pragma once

#include "surface.h"

class SpritePos : public Surface
{
public:
    SpritePos();
    SpritePos(const Surface &, const Point &);
    void SetSurface(const Surface &);
    void SetPos(const Point &);
    void Reset();
    const Point &GetPos() const;
    Rect GetArea() const;
    uint32_t GetMemoryUsage() const;

protected:
    Point pos;
};

class SpriteBack : protected Surface
{
public:
    SpriteBack();

    explicit SpriteBack(const Rect &);

    bool isValid() const;

    void Save(const Point &);

    void Save(const Rect &);

    void Restore() const;

    void Destroy();

    void SetPos(const Point &);

    const Point &GetPos() const;

    const Size &GetSize() const;

    const Rect &GetArea() const;

    uint32_t GetMemoryUsage() const;

protected:
    Rect pos;
};

class SpriteMove : public Surface
{
public:
    SpriteMove();

    explicit SpriteMove(const Surface &);

    void Move(const Point &);

    void Move(int, int);

    void Hide();

    void Show();

    void Redraw();

    bool isVisible() const;

    const Point &GetPos() const;

    const Rect &GetArea() const;

    uint32_t GetMemoryUsage() const;

protected:
    void Show(const Point &);

    SpriteBack background;
    uint32_t mode;
};
