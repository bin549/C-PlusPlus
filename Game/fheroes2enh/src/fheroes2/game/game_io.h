#pragma once

namespace Maps
{
    class FileInfo;
}

namespace Game
{
    bool Save(const string &);
    bool Load(const string &);
    bool LoadSAV2FileInfo(const string &, Maps::FileInfo &);
}
