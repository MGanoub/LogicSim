#include "resourceManager.h"

namespace UI
{
    ResourceManager &ResourceManager::getInstance()
    {
        static ResourceManager s_instance;
        return s_instance;
    }

    ResourceManager::ResourceInfo ResourceManager::getResourceInformationOf(Core::Circuit::ElementType type)
    {
        switch (type)
        {
        case Core::Circuit::ElementType::VCC:
        {
            return getVCCInputResource();
        }
        case Core::Circuit::ElementType::BUTTON:
        {
            return getPressButtonResource();
        }
        case Core::Circuit::ElementType::GND:
        {
            return getGNDInputResource();
        }
        case Core::Circuit::ElementType::LED:
        {
            return getLEDResource();
        }
        case Core::Circuit::ElementType::BUZZER:
        {
            return getBuzzerResource();
        }
        case Core::Circuit::ElementType::AND_GATE:
        {
            return getANDGateResource();
        }
        case Core::Circuit::ElementType::OR_GATE:
        {
            return getORGateResource();
        }

        case Core::Circuit::ElementType::NOT_GATE:
        {
            return getNOTGateResource();
        }
        case Core::Circuit::ElementType::UNKNOWN:
        default:
            break;
        }
        return {};
    }

    ResourceManager::ResourceInfo ResourceManager::getVCCInputResource()
    {
        return {
            QString("VCC"),
            QString(":/inputs/VCC.png"),
            QString(":/inputs/VCC.png"),
            QString()};
    }

    ResourceManager::ResourceInfo ResourceManager::getGNDInputResource()
    {
        return {
            QString("GND"),
            QString(":/inputs/GND.png"),
            QString(":/inputs/GND.png"),
            QString()};
    }

    ResourceManager::ResourceInfo ResourceManager::getPressButtonResource()
    {
        return {
            QString("Press Button"),
            QString(":/inputs/buttonOn.png"),
            QString(":/inputs/buttonOff.png"),
            QString()};
    }

    ResourceManager::ResourceInfo ResourceManager::getLEDResource()
    {
        return {
            QString("LED"),
            QString(":/outputs/WhiteLedOn.png"),
            QString(":/outputs/WhiteLedOff.png"),
            QString()};
    }

    ResourceManager::ResourceInfo ResourceManager::getBuzzerResource()
    {
        return {
            QString("Buzzer"),
            QString(":/outputs/BuzzerOn.png"),
            QString(":/outputs/BuzzerOff.png"),
            QString(":/outputs/buzzerAudio/buzzerTone.wav")};
    }

    ResourceManager::ResourceInfo ResourceManager::getANDGateResource()
    {
        return {
            QString("AND Gate"),
            QString(":/LogicGates/ANDGate.png"),
            QString(":/LogicGates/ANDGate.png"),
            QString()};
    }
    ResourceManager::ResourceInfo ResourceManager::getORGateResource()
    {
        return {
            QString("OR Gate"),
            QString(":/LogicGates/ORGate.png"),
            QString(":/LogicGates/ORGate.png"),
            QString()};
    }
    ResourceManager::ResourceInfo ResourceManager::getNOTGateResource()
    {
        return {
            QString("NOT Gate"),
            QString(":/LogicGates/NOTGate.png"),
            QString(":/LogicGates/NOTGate.png"),
            QString()};
    }

    QString ResourceManager::getSourceCompTabIconPath()
    {
        return {":/MenuTabs/sourceTabIcon.png"};
    }
    QString ResourceManager::getLogicGateTabIconPath()
    {
        return {":/MenuTabs/LogicGatesTabIcon.png"};
    }
}