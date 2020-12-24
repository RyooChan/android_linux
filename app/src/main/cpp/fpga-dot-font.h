//
// Created by shiky on 2020-12-10.
//

#ifndef PUUSHSWITCH_FPGA_DOT_FONT_H
#define PUUSHSWITCH_FPGA_DOT_FONT_H

unsigned char fpga_number[12][10] = {
        // 2, 4, 6, 8위치 주석처리하고 바꿀 것
//	{0x3e,0x7f,0x63,0x73,0x73,0x6f,0x67,0x63,0x7f,0x3e}, // 0
        {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, // not use
//	{0x0c,0x1c,0x1c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x1e}, // 1
        {0x7c,0x60,0x50,0x48,0x44,0x02,0x00,0x00,0x00,0x00}, // 1
//	{0x7e,0x7f,0x03,0x03,0x3f,0x7e,0x60,0x60,0x7f,0x7f}, // 2
        {0x08,0x1c,0x2a,0x08,0x08,0x08,0x08,0x08,0x08,0x08}, // up
//	{0xfe,0x7f,0x03,0x03,0x7f,0x7f,0x03,0x03,0x7f,0x7e}, // 3
        {0x1f,0x03,0x05,0x09,0x11,0x20,0x00,0x00,0x00,0x00}, // 3
//	{0x66,0x66,0x66,0x66,0x66,0x66,0x7f,0x7f,0x06,0x06}, // 4
        {0x00,0x00,0x10,0x20,0x7f,0x20,0x10,0x00,0x00,0x00}, // left
        {0x00,0x00,0x00,0x3c,0x3c,0x3c,0x3c,0x00,0x00,0x00}, // 5
//	{0x60,0x60,0x60,0x60,0x7e,0x7f,0x63,0x63,0x7f,0x3e}, // 6
        {0x00,0x00,0x04,0x02,0x7f,0x02,0x04,0x00,0x00,0x00}, // right
//	{0x7f,0x7f,0x63,0x63,0x03,0x03,0x03,0x03,0x03,0x03}, // 7
        {0x00,0x00,0x00,0x00,0x02,0x44,0x48,0x50,0x60,0x7c}, // 7
//	{0x3e,0x7f,0x63,0x63,0x7f,0x7f,0x63,0x63,0x7f,0x3e}, // 8
        {0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x2a,0x1c,0x08}, // down
//	{0x3e,0x7f,0x63,0x63,0x7f,0x3f,0x03,0x03,0x03,0x03}, // 9
        {0x00,0x00,0x00,0x00,0x20,0x11,0x09,0x05,0x03,0x1f}, // 9
        {0x00,0x00,0x41,0x22,0x14,0x80, 0x14,0x22,0x41,0x00}, // x
        {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff} // 0
};

unsigned char fpga_set_full[10] = {

        0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f
};

unsigned char fpga_set_blank[10] = {

        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#endif //PUUSHSWITCH_FPGA_DOT_FONT_H