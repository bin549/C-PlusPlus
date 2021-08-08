#pragma once

#ifdef WITH_AUDIOCD
#include "types.h"

namespace Cdrom
{
    bool IsValid();
    void Play(const u8 track, bool loop, bool force = false);
    void Pause();
}

#endif
