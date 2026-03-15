#include "pch.h"
#include "IMod.h"
#include "SDK.h"
#include "Registry.h"
#include "RegistryTypes.h"
#pragma comment(lib, "Faucet.lib")

class ExampleMod final : public IMod
{
public:
    ~ExampleMod() override = default;

    const ModInfo* GetInfo() const override {
        static const ModInfo info{ "com.BackSlashN.examplemod",
            "Murder Mystery",
            "BackSlashN",
            "Murder Mystery for Legacy Console Edition",
            {1, 0, 0}
        };
        return &info;
    }

    bool OnLoad() override { SDK::Log(L"LOAD CALLED"); return true; }

    bool OnInit() override { SDK::Log(L"INIT CALLED"); return true; }

    void OnRegister() override { SDK::Log(L"REGISTER CALLED"); }

    void OnLevelLoad() override {
        SDK::Log(L"LEVELLOAD CALLED");
    }

    void OnLevelUnload() override { SDK::Log(L"LEVELUNLOAD CALLED"); }

    bool OnUpdate(float deltaTime) override {
        return true;
    }

    void OnShutdown() override {
        SDK::Log(L"SHUTDOWN");
    }
};

extern "C" __declspec(dllexport) IMod* CreateMod()
{
    return new ExampleMod();
}
