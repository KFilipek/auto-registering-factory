#include <iostream>
#include <vector>
#include "engine_init.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Start..." << endl;
    StorageEngineFactory::ListEngines();
    return 0;
}