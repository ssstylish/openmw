#ifndef OPENMW_ESM_DOOR_H
#define OPENMW_ESM_DOOR_H

#include <string>

namespace ESM
{

class ESMReader;
class ESMWriter;

struct Door
{
    static unsigned int sRecordId;
    /// Return a string descriptor for this record type. Currently used for debugging / error logs only.
    static std::string getRecordType() { return "Door"; }

    std::string mId, mName, mModel, mScript, mOpenSound, mCloseSound;

    void load(ESMReader &esm, bool &isDeleted);
    void save(ESMWriter &esm, bool isDeleted = false) const;

    void blank();
    ///< Set record to default state (does not touch the ID).

    Door(const std::string id, const std::string name, const std::string &model,
         const std::string script, const std::string opensound, const std::string closesound)
    : mId(id)
    , mName(name)
    , mModel(model)
    , mScript(script)
    , mOpenSound(opensound)
    , mCloseSound(closesound)
    {
    }

    Door()
    {
    }
};
}
#endif
