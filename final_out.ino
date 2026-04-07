#define BLYNK_TEMPLATE_ID "TMPL3hYcJZ-CK"
#define BLYNK_TEMPLATE_NAME "SMART SHELF"
#define BLYNK_AUTH_TOKEN "2rGEkOPM9_secn_jqtP5MoGwxPovoZfw"
#include <HX711.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define DOUT 4
#define CLK 5
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define LED_PIN 2
#define BUZZER_PIN 27

HX711 scale;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char auth[] = "2rGEkOPM9_secn_jqtP5MoGwxPovoZfw";
char ssid[] = "Redmi A2";
char pass[] = "naddiiee";

float calibration_factor = 436.24;
int threshold = 500;
bool notified = false;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor);
  scale.tare();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  Blynk.run();

  float weight = scale.get_units();
  Serial.print("Weight: ");
  Serial.println(weight);

  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Weight: ");
  display.print(weight, 2);
  display.print(" g");
  display.display();

  if (weight < threshold) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    if (!notified) {
      Blynk.logEvent("low_stock", "Shelf stock is low!");
      notified = true;
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    notified = false;
  }

  delay(500);
}