#include "osg/Impostor"

#include "osgDB/Registry"
#include "osgDB/Input"
#include "osgDB/Output"

using namespace osg;
using namespace osgDB;

// forward declare functions to use later.
bool Impostor_readLocalData(Object& obj, Input& fr);
bool Impostor_writeLocalData(const Object& obj, Output& fw);

// register the read and write functions with the osgDB::Registry.
RegisterDotOsgWrapperProxy g_ImpostorProxy
(
    new osg::Impostor,
    "Impostor",
    "Object Node Impostor LOD Group",
    &Impostor_readLocalData,
    &Impostor_writeLocalData
);

bool Impostor_readLocalData(Object& obj, Input& fr)
{
    bool iteratorAdvanced = false;

    Impostor& impostor = static_cast<Impostor&>(obj);

    if (fr.matchSequence("ImpostorThreshold %f"))
    {
        float threshold;
        fr[1].getFloat(threshold);
        impostor.setImpostorThreshold(threshold);

        iteratorAdvanced = true;
        fr+=2;
    }

    return iteratorAdvanced;
}


bool Impostor_writeLocalData(const Object& obj, Output& fw)
{
    const Impostor& impostor = static_cast<const Impostor&>(obj);

    fw.indent() << "ImpostorThreshold "<< impostor.getImpostorThreshold() << std::endl;

    return true;
}
