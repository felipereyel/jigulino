#include <BleMouse.h>
#include "M5Atom.h"

BleMouse bleMouse("The Mouse", "Some Manufacturer", 69);
bool is_on = false;
bool is_connected = false;
int x = 0;
int y = 0;

void (*resetFunc)(void) = 0;

void setup()
{
    M5.begin(true, false, true);

    bleMouse.begin();
    Serial.println("bleMouse.begin");

    M5.dis.setBrightness(10);
    Serial.println("M5.dis.setBrightness");

    M5.dis.drawpix(0, 0x0000ff);
    Serial.println("M5.dis.drawpix -- ready");
}

void loop()
{
    delay(200);
    M5.update();

    Serial.println("ble.checks");
    if (!bleMouse.isConnected())
    {
        if (is_connected)
        {
            // DISCONNECTED! RESET
            Serial.println("disconnected. resetting...");
            resetFunc();
        }

        // not connected loop
        return;
    }

    // CONNECTED!

    if (!is_connected)
    {
        Serial.println("connected!");
        is_connected = true;
        M5.dis.drawpix(0, 0xff0000);
    }

    Serial.println("btn.check");
    if (M5.Btn.wasPressed())
    {
        is_on = !is_on;

        if (is_on)
        {
            M5.dis.drawpix(0, 0x00ff00);
        }
        else
        {
            M5.dis.drawpix(0, 0xff0000);
        }
    }

    if (is_on)
    {
        Serial.println("jiggle");
        bleMouse.move(random(-1, 2) * 2, random(-1, 2) * 2);
    }
}