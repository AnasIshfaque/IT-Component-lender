#include "eloquent.h"
#include "eloquent/networking/wifi.h"
#include "eloquent/vision/camera/esp32/webserver.h"

// replace 'm5wide' with your own model
// possible values are 'aithinker', 'eye', 'm5stack', 'm5wide', 'wrover'
#include "eloquent/vision/camera/aithinker.h"



void setup() {
    Serial.begin(115200);
    //delay(2000);

    camera.jpeg();
    // replace with desired resolution
    // possible values are qqvga, qvga, vga
    camera.qqvga();

    // replace with your WiFi credentials
    while (!wifi.connectTo("UIU-STUDENT", "12345678"))
        Serial.println("Cannot connect to WiFi");

    while (!camera.begin())
        Serial.println("Cannot connect to camera");

    webServer.start();
    Serial.print("Camera web server started at http://");
    Serial.println(WiFi.localIP());
}

void loop() {
    // do nothing
}
