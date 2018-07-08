#ifndef OPENMW_COMPONENTS_NIFBULLET_BULLETNIFLOADER_HPP
#define OPENMW_COMPONENTS_NIFBULLET_BULLETNIFLOADER_HPP

#include <cassert>
#include <string>
#include <set>
#include <iostream>
#include <map>

#include <osg/Matrixf>
#include <osg/BoundingBox>
#include <osg/ref_ptr>
#include <osg/Referenced>

#include <components/nif/niffile.hpp>
#include <components/resource/bulletshape.hpp>

class btTriangleMesh;
class btCompoundShape;
class btCollisionShape;

namespace Nif
{
    class Node;
    struct Transformation;
    struct NiTriShape;
}

namespace NifBullet
{

/**
*Load bulletShape from NIF files.
*/
class BulletNifLoader
{
public:
    BulletNifLoader();

    virtual ~BulletNifLoader();

    void warn(const std::string &msg)
    {
        std::cerr << "NIFLoader: Warn:" << msg << "\n";
    }

    void fail(const std::string &msg)
    {
        std::cerr << "NIFLoader: Fail: "<< msg << std::endl;
        abort();
    }

    osg::ref_ptr<Resource::BulletShape> load(const Nif::File& file);

private:
    bool findBoundingBox(const Nif::Node* node, int flags = 0);

    void handleNode(const std::string& fileName, Nif::Node const *node, int flags, bool isCollisionNode, bool isAnimated=false, bool autogenerated=false);

    const Nif::Node* getCollisionNode(const Nif::Node* rootNode);

    void handleNiTriShape(const Nif::NiTriShape *shape, int flags, const osg::Matrixf& transform, bool isAnimated);

    btCompoundShape* mCompoundShape;

    btTriangleMesh* mStaticMesh;

    osg::ref_ptr<Resource::BulletShape> mShape;
};

}

#endif
