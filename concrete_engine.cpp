#include "concrete_engine.h"

bool ConcreteEngine::s_registered =
  StorageEngineFactory::Register(ConcreteEngine::GetFactoryName(),   
                                 ConcreteEngine::CreateMethod);