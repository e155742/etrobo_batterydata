#include "app.h"
#include <Clock.h>
#include "util.h"

void main_task(intptr_t unused) {
    ev3api::Clock clock;

    msg_f("AMPERE", 1);
    msg_f("VOLT", 4);
    msg_f("FULL DATA", 8);
    msg_f("48 mA", 9);
    msg_f("8387 mV", 10);

    char str[64];

    while (true) {
        if (1000 < clock.now()) {
            sprintf(str, "%d mA", ev3_battery_current_mA());
            msg_f(str, 2);
            sprintf(str, "%d mV", ev3_battery_voltage_mV());
            msg_f(str, 5);
            clock.reset();
        }
    }
}
