#pragma once

#include <string>

namespace CesiumMetadata {
enum class TileFormatComponentType {
  None,
  Byte,
  UnsignedByte,
  Short,
  UnsignedShort,
  Int,
  UnsignedInt,
  Float,
  Double
};

enum class TileFormatType { None, Scalar, Vec2, Vec3, Vec4 };

TileFormatType convertStringToType(const std::string& type);

TileFormatComponentType convertStringToComponentType(const std::string& type);

uint32_t getNumOfComponents(TileFormatType type);

uint32_t getComponentSize(TileFormatComponentType componentType);
} // namespace CesiumMetadata