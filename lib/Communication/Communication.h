//
// Created by ubuntu on 17-6-17.
//

#ifndef WATERUP_PLANTPOT_COMMUNICATION_H
#define WATERUP_PLANTPOT_COMMUNICATION_H

#include <Arduino.h> // Include this library for using basic system functions and variables.
#include <ESP8266WiFi.h> // Include this library for working with the ESP8266 chip.
#include <WiFiManager.h> // Include this library for dynamically setting up the WiFi connection.
#include <Adafruit_MQTT.h> // Include this library for securely connecting to the internet using WiFi.
#include <Adafruit_MQTT_Client.h> // Include this library for MQTT communication.
#include <FS.h> // Include this library for access to the ESP8266's file system.
#include <Streaming.h> // Include this library for using the << Streaming operator.

#define MQTT_BROKER_HOST "mqtt.inf1i.ga" // The address of the MQTT broker.
#define MQTT_BROKER_PORT 8883 // The port to connect to at the MQTT broker.
#define MQTT_BROKER_USERNAME "inf1i-plantpot" // The pot's username authenticate at the MQTT broker.
#define MQTT_BROKER_PASSWORD "password" // The pot's password to authenticate at the MQTT broker.
#define MQTT_BROKER_FINGERPRINT "A6 E4 A9 8C 92 B3 8D 81 73 CE 5B 33 33 F5 A3 7A 1B 87 E2 F3"

#define TOPIC_PUBLISH_STATISTIC "/publish/statistic" // This MQTT topic is used to publish pot state statistics.
#define TOPIC_PUBLISH_WARNING "/publish/warning"

#define JSON_BUFFER_SIZE 200 // This holds the default string buffer size of json messages.

class Communication
{
public:
    void setup();
    void publishStatistic();
    void publishWarning();

private:
    void connect();
    void verifyFingerprint();
};


#endif //WATERUP_PLANTPOT_COMMUNICATION_H
