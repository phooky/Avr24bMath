/*
 * Copyright 2010 by Adam Mayer <adam@makerbot.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <stdint.h>

/**
 * A simple 24-bit math library for ATMEGA.
 * Will be expanded to support whatever it needs whenever it needs it.
 */
class uint24_t {
private:
  uint32_t data:24 __attribute__ ((packed));
public:
  uint24_t() {}
  uint24_t(const uint24_t& value) {
    data = value.data;
  }
  uint24_t(const uint32_t& value) {
    data = value;
  }
  uint24_t(const uint16_t& value) {
    data = value;
  }
  uint24_t(const uint8_t& value) {
    data = value;
  }

  operator uint8_t() {
    return (uint8_t)data;
  }

  operator uint16_t() {
    return (uint16_t)data;
  }

  operator uint32_t() {
    return (uint32_t)data;
  }

  uint24_t operator+(const uint24_t value) {
    uint24_t out24(*this);
    asm("add %A0,%A1\n\t"
	"adc %B0,%B1\n\t"
	"adc %C0,%C1\n\t" 
	: "=r" (out24.data) : "r" (value.data));
    return out24;
  }

  uint24_t operator-(const uint24_t value) {
    uint24_t out24(*this);
    asm("sub %A0,%A1\n\t"
	"sbc %B0,%B1\n\t"
	"sbc %C0,%C1\n\t" 
	: "=r" (out24.data) : "r" (value.data));
    return out24;
  }
};

