#ifndef GUI_COLORS_H
#define GUI_COLORS_H

#include <stdint.h>

namespace toasting::gui::color {

  class Color {
  public:
    uint16_t color;

    constexpr
    Color(uint8_t r, uint8_t g, uint8_t b)
    : color{
          ((unsigned(r) >> 3) << 11)
        | ((unsigned(g) >> 2) <<  5)
        | ((unsigned(b) >> 3) <<  0)
      }
    {}
  };

  // **************** Colors copied from GUIslice ****************
  // https://github.com/ImpulseAdventure/GUIslice/blob/v0.9/src/GUIslice.h#L176

  static constexpr Color kRedDk4     {128,  0,  0};   ///< Red (dark4)
  static constexpr Color kRedDk3     {160,  0,  0};   ///< Red (dark3)
  static constexpr Color kRedDk2     {192,  0,  0};   ///< Red (dark2)
  static constexpr Color kRedDk1     {224,  0,  0};   ///< Red (dark1)
  static constexpr Color kRed        {255,  0,  0};   ///< Red
  static constexpr Color kRedLt1     {255, 32, 32};   ///< Red (light1)
  static constexpr Color kRedLt2     {255, 64, 64};   ///< Red (light2)
  static constexpr Color kRedLt3     {255, 96, 96};   ///< Red (light3)
  static constexpr Color kRedLt4     {255,128,128};   ///< Red (light4)
  static constexpr Color kGreenDk4   {  0,128,  0};   ///< Green (dark4)
  static constexpr Color kGreenDk3   {  0,160,  0};   ///< Green (dark3)
  static constexpr Color kGreenDk2   {  0,192,  0};   ///< Green (dark2)
  static constexpr Color kGreenDk1   {  0,224,  0};   ///< Green (dark1)
  static constexpr Color kGreen      {  0,255,  0};   ///< Green
  static constexpr Color kGreenLt1   { 32,255, 32};   ///< Green (light1)
  static constexpr Color kGreenLt2   { 64,255, 64};   ///< Green (light2)
  static constexpr Color kGreenLt3   { 96,255, 96};   ///< Green (light3)
  static constexpr Color kGreenLt4   {128,255,128};   ///< Green (light4)
  static constexpr Color kBlueDk4    {  0,  0,128};   ///< Blue (dark4)
  static constexpr Color kBlueDk3    {  0,  0,160};   ///< Blue (dark3)
  static constexpr Color kBlueDk2    {  0,  0,192};   ///< Blue (dark2)
  static constexpr Color kBlueDk1    {  0,  0,224};   ///< Blue (dark1)
  static constexpr Color kBlue       {  0,  0,255};   ///< Blue
  static constexpr Color kBlueLt1    { 32, 32,255};   ///< Blue (light1)
  static constexpr Color kBlueLt2    { 64, 64,255};   ///< Blue (light2)
  static constexpr Color kBlueLt3    { 96, 96,255};   ///< Blue (light3)
  static constexpr Color kBlueLt4    {128,128,255};   ///< Blue (light4)
  static constexpr Color kBlack      {  0,  0,  0};   ///< Black
  static constexpr Color kGrayDk3    { 32, 32, 32};   ///< Gray (dark)
  static constexpr Color kGrayDk2    { 64, 64, 64};   ///< Gray (dark)
  static constexpr Color kGrayDk1    { 96, 96, 96};   ///< Gray (dark)
  static constexpr Color kGray       {128,128,128};   ///< Gray
  static constexpr Color kGrayLt1    {160,160,160};   ///< Gray (light1)
  static constexpr Color kGrayLt2    {192,192,192};   ///< Gray (light2)
  static constexpr Color kGrayLt3    {224,224,224};   ///< Gray (light3)
  static constexpr Color kWhite      {255,255,255};   ///< White

  static constexpr Color kYellow     {255,255,  0};   ///< Yellow
  static constexpr Color kYellowDk   { 64, 64,  0};   ///< Yellow (dark)
  static constexpr Color kPurple     {128,  0,128};   ///< Purple
  static constexpr Color kCyan       {  0,255,255};   ///< Cyan
  static constexpr Color kMagenta    {255,  0,255};   ///< Magenta
  static constexpr Color kTeal       {  0,128,128};   ///< Teal
  static constexpr Color kOrange     {255,165,  0};   ///< Orange
  static constexpr Color kBrown      {165, 42, 42};   ///< Brown

}

#endif /* GUI_COLORS_H */
