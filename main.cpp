#include <iostream>
#include "libplanieren/PlanierenStorage.h"

bool USM_CONFIG::InTextMode = 1;

int main() {
    Profile pr("Test");
    pr.create_task("08.08.2022", "16:30", "Идти на вождение");
    return 0;
}
