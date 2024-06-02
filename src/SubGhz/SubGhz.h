#pragma once

#ifndef SubGhz_h
#define SubGhz_h

#include <Arduino.h>

#include "./Misc/Config.h"

#include <lvgl.h>
#include <ui.h>

#include <ELECHOUSE_CC1101_SRC_DRV.h>
#include <RCSwitch.h>

enum CC1101Preset
{
  AM650,
  AM270,
  FM238,
  FM476,
};

class SubGhz
{

private:
  static const char *bin2tristate(const char *bin);
  static char *dec2binWzerofill(unsigned long Dec, unsigned int bitLength);
  void send_byte(uint8_t dataByte);

public:
  bool init();

  void setPreset(CC1101Preset preset);
  void setPacketFormat(int packetFormat);
  void setModulation(int modulation);

  void setFrequency(float freq);
  float getFrequency();

  void enableRCSwitch();
  void disableRCSwitch();

  void enableReceiver();
  void disableReceiver();

  void enableTransmit();
  void disableTransmit();

  void enableScanner(float start, float stop);
  void disableScanner();

  void switchOn(const char *sGroup, const char *sDevice);
  void switchOff(const char *sGroup, const char *sDevice);

  void sendLastSignal();
  bool send_tesla();
  void sendSamples(int samples[], int samplesLength);
  bool sendCapture();

  void resetProtAnalyzer();
  void showResultProtAnalyzer();
  void showResultRecPlay();

  bool CaptureLoop();
  bool ProtAnalyzerLoop();
  void ScannerLoop();
  void GeneratorLoop();
};

#endif
