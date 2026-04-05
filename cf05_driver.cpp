/**
 * cf05_driver.cpp — CWClockfaceDriver adapter for cw-cf-0x05 (Pac-Man)
 * v3 bridge: wraps the v2 CF05::Clockface class in the function-pointer API.
 */

#include "Clockface05.h"        // v2 class, namespace CF05
#include <CWClockfaceDriver.h>     // v3 driver API

static CF05::Clockface* s_face = nullptr;

static void cf05_setup(Adafruit_GFX* display, CWDateTime* dateTime) {
    if (!s_face) s_face = new CF05::Clockface(display);
    s_face->setup(dateTime);
}

static void cf05_update() {
    if (s_face) s_face->update();
}

static void cf05_teardown() {
    // Instance kept alive for fast re-activation.
}

CWClockfaceDriver cf_pacman = {
    .name     = "Pac-Man",
    .index    = 4,
    .setup    = cf05_setup,
    .update   = cf05_update,
    .teardown = cf05_teardown,
};
