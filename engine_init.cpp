#include "engine_init.h"

std::map<std::string, StorageEngineFactory::TCreateMethod> StorageEngineFactory::s_methods;

bool StorageEngineFactory::Register(const std::string name, StorageEngineFactory::TCreateMethod funcCreate) {
    auto it = s_methods.find(name);
    if (it == s_methods.end()) {
        s_methods[name] = funcCreate;
        return true;
    }
    return false;
}

std::unique_ptr<IStorageEngine> 
StorageEngineFactory::Create(const std::string& name)
{
    auto it = s_methods.find(name);
    if (it != s_methods.end()) 
        return it->second(); // call the createFunc

    return nullptr;
}