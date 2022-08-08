#include <iostream>
#include "libplanieren/PlanierenStorage.h"

bool USM_CONFIG::InTextMode = 1;

int main() {
    Profile pr("Test");
    //pr.create_task("08.08.2022", "16:30", "Идти на вождение");
    std::cout << pr.get_tasks()[0].task_;
    return 0;
}
