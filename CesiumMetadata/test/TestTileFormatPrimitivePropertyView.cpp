#include "CesiumMetadata/TileFormatPrimitivePropertyView.h"
#include "catch2/catch.hpp"
#include <cstddef>
#include <cstdint>
#include <gsl/span>
#include <vector>

TEST_CASE("Test Uint8_t property") {
  std::vector<uint8_t> data{1, 5, 6, 7, 9};
  CesiumMetadata::TileFormatPrimitivePropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(uint8_t)),
      CesiumMetadata::TileFormatComponentType::UnsignedByte,
      data.size());

  auto values = propertyView.asUint8();
  REQUIRE(values.size() == data.size());

  for (size_t i = 0; i < values.size(); ++i) {
    REQUIRE(values[i] == data[i]);
  }

  // check other type is empty
  REQUIRE(propertyView.asInt8().empty());

  REQUIRE(propertyView.asUint16().empty());
  REQUIRE(propertyView.asInt16().empty());

  REQUIRE(propertyView.asUint32().empty());
  REQUIRE(propertyView.asInt32().empty());

  REQUIRE(propertyView.asUint64().empty());
  REQUIRE(propertyView.asInt64().empty());

  REQUIRE(propertyView.asFloat().empty());
  REQUIRE(propertyView.asDouble().empty());
}

TEST_CASE("Test Int8_t property") {
  std::vector<int8_t> data{-1, -5, 6, 7, 9};
  CesiumMetadata::TileFormatPrimitivePropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(int8_t)),
      CesiumMetadata::TileFormatComponentType::Byte,
      data.size());

  auto values = propertyView.asInt8();
  REQUIRE(values.size() == data.size());

  for (size_t i = 0; i < values.size(); ++i) {
    REQUIRE(values[i] == data[i]);
  }

  // check other type is empty
  REQUIRE(propertyView.asUint8().empty());

  REQUIRE(propertyView.asUint16().empty());
  REQUIRE(propertyView.asInt16().empty());

  REQUIRE(propertyView.asUint32().empty());
  REQUIRE(propertyView.asInt32().empty());

  REQUIRE(propertyView.asUint64().empty());
  REQUIRE(propertyView.asInt64().empty());

  REQUIRE(propertyView.asFloat().empty());
  REQUIRE(propertyView.asDouble().empty());
}

TEST_CASE("Test Uint16_t property") {
  std::vector<uint16_t> data{300, 500, 255, 1999};
  CesiumMetadata::TileFormatPrimitivePropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(uint16_t)),
      CesiumMetadata::TileFormatComponentType::UnsignedShort,
      data.size());

  auto values = propertyView.asUint16();
  REQUIRE(values.size() == data.size());

  for (size_t i = 0; i < values.size(); ++i) {
    REQUIRE(values[i] == data[i]);
  }

  // check other type is empty
  REQUIRE(propertyView.asUint8().empty());
  REQUIRE(propertyView.asInt8().empty());

  REQUIRE(propertyView.asInt16().empty());

  REQUIRE(propertyView.asUint32().empty());
  REQUIRE(propertyView.asInt32().empty());

  REQUIRE(propertyView.asUint64().empty());
  REQUIRE(propertyView.asInt64().empty());

  REQUIRE(propertyView.asFloat().empty());
  REQUIRE(propertyView.asDouble().empty());
}

TEST_CASE("Test Int16_t property") {
  std::vector<int16_t> data{-300, 500, -255, 1999};
  CesiumMetadata::TileFormatPrimitivePropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(int16_t)),
      CesiumMetadata::TileFormatComponentType::Short,
      data.size());

  auto values = propertyView.asInt16();
  REQUIRE(values.size() == data.size());

  for (size_t i = 0; i < values.size(); ++i) {
    REQUIRE(values[i] == data[i]);
  }

  // check other type is empty
  REQUIRE(propertyView.asUint8().empty());
  REQUIRE(propertyView.asInt8().empty());

  REQUIRE(propertyView.asUint16().empty());

  REQUIRE(propertyView.asUint32().empty());
  REQUIRE(propertyView.asInt32().empty());

  REQUIRE(propertyView.asUint64().empty());
  REQUIRE(propertyView.asInt64().empty());

  REQUIRE(propertyView.asFloat().empty());
  REQUIRE(propertyView.asDouble().empty());
}

TEST_CASE("Test Uint32_t property") {
  std::vector<uint32_t> data{100000, 3444, 200000, 100000};
  CesiumMetadata::TileFormatPrimitivePropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(uint32_t)),
      CesiumMetadata::TileFormatComponentType::UnsignedInt,
      data.size());

  auto values = propertyView.asUint32();
  REQUIRE(values.size() == data.size());

  for (size_t i = 0; i < values.size(); ++i) {
    REQUIRE(values[i] == data[i]);
  }

  // check other type is empty
  REQUIRE(propertyView.asUint8().empty());
  REQUIRE(propertyView.asInt8().empty());

  REQUIRE(propertyView.asUint16().empty());
  REQUIRE(propertyView.asInt16().empty());

  REQUIRE(propertyView.asInt32().empty());

  REQUIRE(propertyView.asUint64().empty());
  REQUIRE(propertyView.asInt64().empty());

  REQUIRE(propertyView.asFloat().empty());
  REQUIRE(propertyView.asDouble().empty());
}

TEST_CASE("Test Int32_t property") {
  std::vector<int32_t> data{-100000, 3444, -200000, 100000};
  CesiumMetadata::TileFormatPrimitivePropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(int32_t)),
      CesiumMetadata::TileFormatComponentType::Int,
      data.size());

  auto values = propertyView.asInt32();
  REQUIRE(values.size() == data.size());

  for (size_t i = 0; i < values.size(); ++i) {
    REQUIRE(values[i] == data[i]);
  }

  // check other type is empty
  REQUIRE(propertyView.asUint8().empty());
  REQUIRE(propertyView.asInt8().empty());

  REQUIRE(propertyView.asUint16().empty());
  REQUIRE(propertyView.asInt16().empty());

  REQUIRE(propertyView.asUint32().empty());

  REQUIRE(propertyView.asUint64().empty());
  REQUIRE(propertyView.asInt64().empty());

  REQUIRE(propertyView.asFloat().empty());
  REQUIRE(propertyView.asDouble().empty());
}

TEST_CASE("Test Float property") {
  std::vector<float> data{-1000.40f, 3444.20f, -200.5f, 10.56f};
  CesiumMetadata::TileFormatPrimitivePropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(float)),
      CesiumMetadata::TileFormatComponentType::Float,
      data.size());

  auto values = propertyView.asFloat();
  REQUIRE(values.size() == data.size());

  for (size_t i = 0; i < values.size(); ++i) {
    REQUIRE(values[i] == Approx(data[i]));
  }

  // check other type is empty
  REQUIRE(propertyView.asUint8().empty());
  REQUIRE(propertyView.asInt8().empty());

  REQUIRE(propertyView.asUint16().empty());
  REQUIRE(propertyView.asInt16().empty());

  REQUIRE(propertyView.asUint32().empty());
  REQUIRE(propertyView.asInt32().empty());

  REQUIRE(propertyView.asUint64().empty());
  REQUIRE(propertyView.asInt64().empty());

  REQUIRE(propertyView.asDouble().empty());
}

TEST_CASE("Test Double property") {
  std::vector<double> data{-1000.40, 3444.20, -200.5, 10.56};
  CesiumMetadata::TileFormatPrimitivePropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(double)),
      CesiumMetadata::TileFormatComponentType::Double,
      data.size());

  auto values = propertyView.asDouble();
  REQUIRE(values.size() == data.size());

  for (size_t i = 0; i < values.size(); ++i) {
    REQUIRE(values[i] == Approx(data[i]));
  }

  // check other type is empty
  REQUIRE(propertyView.asUint8().empty());
  REQUIRE(propertyView.asInt8().empty());

  REQUIRE(propertyView.asUint16().empty());
  REQUIRE(propertyView.asInt16().empty());

  REQUIRE(propertyView.asUint32().empty());
  REQUIRE(propertyView.asInt32().empty());

  REQUIRE(propertyView.asUint64().empty());
  REQUIRE(propertyView.asInt64().empty());

  REQUIRE(propertyView.asFloat().empty());
}
