#pragma once

namespace CesiumMetadata {
enum class TileFormatComponentType {
  Byte,
  UnsignedByte,
  Short,
  UnsignedShort,
  Int,
  UnsignedInt,
  Float,
  Double
};

enum class TileFormatType { Scalar, Vec2, Vec3, Vec4 };
} // namespace CesiumMetadata