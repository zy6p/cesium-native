#include "CesiumMetadata/TileFormatDataType.h"
#include <cstdint>

namespace CesiumMetadata {
TileFormatType convertStringToType(const std::string& type) {
  if (type == "SCALAR") {
    return TileFormatType::Scalar;
  }

  if (type == "VEC2") {
    return TileFormatType::Vec2;
  }

  if (type == "VEC3") {
    return TileFormatType::Vec3;
  }

  if (type == "VEC4") {
    return TileFormatType::Vec4;
  }

  return TileFormatType::None;
}

TileFormatComponentType convertStringToComponentType(const std::string& type) {
  if (type == "BYTE") {
    return TileFormatComponentType::Byte;
  }

  if (type == "UNSIGNED_BYTE") {
    return TileFormatComponentType::UnsignedByte;
  }

  if (type == "SHORT") {
    return TileFormatComponentType::Short;
  }

  if (type == "UNSIGNED_SHORT") {
    return TileFormatComponentType::UnsignedShort;
  }

  if (type == "INT") {
    return TileFormatComponentType::Int;
  }

  if (type == "UNSIGNED_INT") {
    return TileFormatComponentType::UnsignedInt;
  }

  if (type == "FLOAT") {
    return TileFormatComponentType::Float;
  }

  if (type == "DOUBLE") {
    return TileFormatComponentType::Double;
  }

  return TileFormatComponentType::None;
}

uint32_t getNumOfComponents(TileFormatType type) {
  switch (type) {
  case TileFormatType::None:
    return 0;
  case TileFormatType::Scalar:
    return 1;
  case TileFormatType::Vec2:
    return 2;
  case TileFormatType::Vec3:
    return 3;
  case TileFormatType::Vec4:
    return 4;
  default:
    return 0;
  }
}

uint32_t getComponentSize(TileFormatComponentType componentType) {
  switch (componentType) {
  case TileFormatComponentType::None:
    return 0;
  case TileFormatComponentType::Byte:
    return sizeof(int8_t);
  case TileFormatComponentType::UnsignedByte:
    return sizeof(uint8_t);
  case TileFormatComponentType::Short:
    return sizeof(int16_t);
  case TileFormatComponentType::UnsignedShort:
    return sizeof(uint16_t);
  case TileFormatComponentType::Int:
    return sizeof(int32_t);
  case TileFormatComponentType::UnsignedInt:
    return sizeof(uint32_t);
  case TileFormatComponentType::Float:
    return sizeof(float);
  case TileFormatComponentType::Double:
    return sizeof(double);
  default:
    return 0;
  }
}
} // namespace CesiumMetadata