#include "catch2/catch.hpp"
#include "CesiumMetadata/TileFormatDataType.h"

TEST_CASE("Convert string to type") {
  REQUIRE(
      CesiumMetadata::convertStringToType("SCALAR") ==
      CesiumMetadata::TileFormatType::Scalar);

  REQUIRE(
      CesiumMetadata::convertStringToType("VEC2") ==
      CesiumMetadata::TileFormatType::Vec2);

  REQUIRE(
      CesiumMetadata::convertStringToType("VEC3") ==
      CesiumMetadata::TileFormatType::Vec3);

  REQUIRE(
      CesiumMetadata::convertStringToType("VEC4") ==
      CesiumMetadata::TileFormatType::Vec4);

  REQUIRE(
      CesiumMetadata::convertStringToType("Nonsense") ==
      CesiumMetadata::TileFormatType::None);
}

TEST_CASE("Convert string to componentType") {
  REQUIRE(
      CesiumMetadata::convertStringToComponentType("BYTE") ==
      CesiumMetadata::TileFormatComponentType::Byte);

  REQUIRE(
      CesiumMetadata::convertStringToComponentType("UNSIGNED_BYTE") ==
      CesiumMetadata::TileFormatComponentType::UnsignedByte);

  REQUIRE(
      CesiumMetadata::convertStringToComponentType("SHORT") ==
      CesiumMetadata::TileFormatComponentType::Short);

  REQUIRE(
      CesiumMetadata::convertStringToComponentType("UNSIGNED_SHORT") ==
      CesiumMetadata::TileFormatComponentType::UnsignedShort);

  REQUIRE(
      CesiumMetadata::convertStringToComponentType("INT") ==
      CesiumMetadata::TileFormatComponentType::Int);

  REQUIRE(
      CesiumMetadata::convertStringToComponentType("UNSIGNED_INT") ==
      CesiumMetadata::TileFormatComponentType::UnsignedInt);

  REQUIRE(
      CesiumMetadata::convertStringToComponentType("FLOAT") ==
      CesiumMetadata::TileFormatComponentType::Float);

  REQUIRE(
      CesiumMetadata::convertStringToComponentType("DOUBLE") ==
      CesiumMetadata::TileFormatComponentType::Double);

  REQUIRE(
      CesiumMetadata::convertStringToComponentType("Nonsense") ==
      CesiumMetadata::TileFormatComponentType::None);
}

TEST_CASE("Get number of component") {
  REQUIRE(
      CesiumMetadata::getNumOfComponents(
          CesiumMetadata::TileFormatType::Scalar) == 1);

  REQUIRE(
      CesiumMetadata::getNumOfComponents(
          CesiumMetadata::TileFormatType::Vec2) == 2);

  REQUIRE(
      CesiumMetadata::getNumOfComponents(
          CesiumMetadata::TileFormatType::Vec3) == 3);

  REQUIRE(
      CesiumMetadata::getNumOfComponents(
          CesiumMetadata::TileFormatType::Vec4) == 4);

  REQUIRE(
      CesiumMetadata::getNumOfComponents(
          CesiumMetadata::TileFormatType::None) == 0);
}

TEST_CASE("Get component size") {
  REQUIRE(
      CesiumMetadata::getComponentSize(
          CesiumMetadata::TileFormatComponentType::Byte) == sizeof(int8_t));

  REQUIRE(
      CesiumMetadata::getComponentSize(
          CesiumMetadata::TileFormatComponentType::UnsignedByte) == sizeof(uint8_t));

  REQUIRE(
      CesiumMetadata::getComponentSize(
          CesiumMetadata::TileFormatComponentType::Short) == sizeof(int16_t));

  REQUIRE(
      CesiumMetadata::getComponentSize(
          CesiumMetadata::TileFormatComponentType::UnsignedShort) == sizeof(uint16_t));

  REQUIRE(
      CesiumMetadata::getComponentSize(
          CesiumMetadata::TileFormatComponentType::Int) == sizeof(int32_t));

  REQUIRE(
      CesiumMetadata::getComponentSize(
          CesiumMetadata::TileFormatComponentType::UnsignedInt) == sizeof(uint32_t));

  REQUIRE(
      CesiumMetadata::getComponentSize(
          CesiumMetadata::TileFormatComponentType::Float) == sizeof(float));

  REQUIRE(
      CesiumMetadata::getComponentSize(
          CesiumMetadata::TileFormatComponentType::Double) == sizeof(double));

  REQUIRE(
      CesiumMetadata::getComponentSize(
          CesiumMetadata::TileFormatComponentType::None) == 0);
}
