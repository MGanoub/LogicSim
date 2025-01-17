#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <Core/Circuit/CircuitEnums.h>
#include <QString>
namespace UI
{
    class ResourceManager
    {
    public:
        struct ResourceInfo
        {
            QString displayName;
            QString OnStatePixmapPath;
            QString offStatePixmapPath;
            QString audioFilePath;
        };
        ResourceManager(ResourceManager const &) = delete;
        ResourceManager &operator=(ResourceManager const &) = delete;
        ResourceManager(ResourceManager const &&) = delete;
        ResourceManager &operator=(ResourceManager const &&) = delete;

        static ResourceManager &getInstance();
        ResourceInfo getResourceInformationOf(Core::Circuit::ElementType type);

    private:
        ResourceManager() = default;
        ResourceInfo getVCCInputResource();
        ResourceInfo getGNDInputResource();
        ResourceInfo getANDGateResource();
        ResourceInfo getORGateResource();
        ResourceInfo getNOTGateResource();
        ResourceInfo getLEDResource();
    };
}

#endif // RESOURCEMANAGER_H
