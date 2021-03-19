#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <functional>

class IStorageEngine {
public:
    IStorageEngine() = default;
    virtual ~IStorageEngine() = default;

    virtual bool isEphemeral() const = 0;
    
    class Factory {
    public:
        Factory() = default;
        virtual ~Factory() {}
        virtual std::unique_ptr<IStorageEngine> create(std::string params) const = 0;
        virtual std::string getCanonicalName() const = 0;
    };
};

class SpecificEngine : public IStorageEngine {
public:
    SpecificEngine() {
        std::cout << "SpecificEngine()" << std::endl;
    }
    virtual ~SpecificEngine() {
        std::cout << "~SpecificEngine()" << std::endl;
    }
    virtual bool isEphemeral() const override {
        return false;
    };
};

class StorageEngineFactory {
public:
    // using TCreateMethod = std::unique_ptr<IStorageEngine>(*)();
    using TCreateMethod = std::function<std::unique_ptr<IStorageEngine>()>;
    StorageEngineFactory() = delete;
    static bool Register(const std::string name, TCreateMethod funcCreate);
    static std::unique_ptr<IStorageEngine> Create(const std::string& name);
    static void ListEngines() {
        for(auto &entry : s_methods) {
            std::cout << entry.first << std::endl;
        }
    }
private:
    static std::map<std::string, TCreateMethod> s_methods;
};
