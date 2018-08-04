/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _NUMBEREDIT_H_
#define _NUMBEREDIT_H_

#include "basenumberedit.h"

class NumberEdit : public BaseNumberEdit {
  public:
    NumberEdit(Window * parent, const rect_t & rect, int32_t vmin, int32_t vmax,
               std::function<int32_t()> getValue, std::function<void(int32_t)> setValue = nullptr, LcdFlags flags = 0);

#if defined(DEBUG_WINDOWS)
    std::string getName() override
    {
      return "NumberEdit(" + std::to_string(getValue()) + ")";
    }
#endif

    void paint(BitmapBuffer * dc) override;

    void enable(bool enabled)
    {
      this->enabled = enabled;
    }

    void setPrefix(const char * value)
    {
      prefix = value;
    }

    void setSuffix(const char * value)
    {
      suffix = value;
    }

    void setZeroText(const char * text)
    {
      zeroText = text;
    }

    void setDisplayHandler(std::function<void(BitmapBuffer *, LcdFlags, int32_t)> function)
    {
      displayFunction = std::move(function);
    }

    bool onTouchEnd(coord_t x, coord_t y) override;

    void onFocusLost() override;

  protected:
    std::function<void(BitmapBuffer *, LcdFlags, int32_t)> displayFunction;
    const char * prefix = nullptr;
    const char * suffix = nullptr;
    const char * zeroText = nullptr;
    bool enabled = true;
};

#endif // _NUMBEREDIT_H_