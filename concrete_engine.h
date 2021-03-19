#pragma once
#include "engine_init.h"

class ConcreteEngine : public IStorageEngine {
public:
    ConcreteEngine() {
        std::cout << "ConcreteEngine()" << std::endl;
    }
    virtual ~ConcreteEngine() {
        std::cout << "~ConcreteEngine()" << std::endl;
    }
    virtual bool isEphemeral() const override {
        return false;
    };
    static std::unique_ptr<IStorageEngine> CreateMethod() { 
        return std::make_unique<ConcreteEngine>();
    }
    static std::string GetFactoryName() { return "ConcreteEngine"; }

private:
    static bool s_registered;
};