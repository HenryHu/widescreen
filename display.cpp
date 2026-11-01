#include "display.h"

MatrixPanel_I2S_DMA *display = nullptr;
int brightness = 1;

// Change these pins as needed
#define R1_PIN 25
#define G1_PIN 26
#define B1_PIN 27
#define R2_PIN 14
#define G2_PIN 12
#define B2_PIN 13
#define A_PIN 23
#define B_PIN 19
#define C_PIN 5
#define D_PIN 17
#define E_PIN -1
#define LAT_PIN 4
#define OE_PIN 15
#define CLK_PIN 16

MatrixPanel_I2S_DMA* GetDisplay() {
    HUB75_I2S_CFG::i2s_pins _pins={R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN,
        B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};
    HUB75_I2S_CFG mxconfig(
            64, // Module width
            32, // Module height
            1, // chain length
            _pins // pin mapping
            );
    mxconfig.latch_blanking = 4;
    mxconfig.i2sspeed = HUB75_I2S_CFG::HZ_10M;
    mxconfig.clkphase = false;
    return new MatrixPanel_I2S_DMA(mxconfig);
}

void InitDisplay() {
    display = GetDisplay();
    display->begin();
    display->clearScreen();
    display->fillScreen(display->color565(0, 0, 0));
    display->setBrightness(brightness);
    display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
}
