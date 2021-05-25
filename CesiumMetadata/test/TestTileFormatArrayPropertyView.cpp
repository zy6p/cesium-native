#include "CesiumMetadata/TileFormatArrayPropertyView.h"
#include "catch2/catch.hpp"

TEST_CASE("Create Uint8 Vec3") {
  std::vector<uint8_t> data{21, 32, 22, 40, 51, 2, 62, 70, 199};
  CesiumMetadata::TileFormatArrayPropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(uint8_t)),
      CesiumMetadata::TileFormatType::Vec3,
      CesiumMetadata::TileFormatComponentType::UnsignedByte,
      data.size() / 3);

  size_t numOfInstances = propertyView.numOfInstances();
  REQUIRE(numOfInstances == 3);
  for (size_t i = 0; i < numOfInstances; ++i) {
    auto values = propertyView.getInstanceAsUint8(i);
    REQUIRE(values[0] == data[i * 3]);
    REQUIRE(values[1] == data[i * 3 + 1]);
    REQUIRE(values[2] == data[i * 3 + 2]);
  }

  REQUIRE(propertyView.getInstanceAsInt8(0).empty());

  REQUIRE(propertyView.getInstanceAsUint16(0).empty());
  REQUIRE(propertyView.getInstanceAsInt16(0).empty());

  REQUIRE(propertyView.getInstanceAsUint32(0).empty());
  REQUIRE(propertyView.getInstanceAsInt32(0).empty());

  REQUIRE(propertyView.getInstanceAsUint64(0).empty());
  REQUIRE(propertyView.getInstanceAsInt64(0).empty());

  REQUIRE(propertyView.getInstanceAsFloat(0).empty());
  REQUIRE(propertyView.getInstanceAsDouble(0).empty());
}

TEST_CASE("Create Int8 Vec3") {
  std::vector<int8_t> data{21, 32, -12, 40, 51, -20, 62, 70, -120};
  CesiumMetadata::TileFormatArrayPropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(int8_t)),
      CesiumMetadata::TileFormatType::Vec3,
      CesiumMetadata::TileFormatComponentType::Byte,
      data.size() / 3);

  size_t numOfInstances = propertyView.numOfInstances();
  REQUIRE(numOfInstances == 3);
  for (size_t i = 0; i < numOfInstances; ++i) {
    auto values = propertyView.getInstanceAsInt8(i);
    REQUIRE(values[0] == data[i * 3]);
    REQUIRE(values[1] == data[i * 3 + 1]);
    REQUIRE(values[2] == data[i * 3 + 2]);
  }

  REQUIRE(propertyView.getInstanceAsUint8(0).empty());

  REQUIRE(propertyView.getInstanceAsUint16(0).empty());
  REQUIRE(propertyView.getInstanceAsInt16(0).empty());

  REQUIRE(propertyView.getInstanceAsUint32(0).empty());
  REQUIRE(propertyView.getInstanceAsInt32(0).empty());

  REQUIRE(propertyView.getInstanceAsUint64(0).empty());
  REQUIRE(propertyView.getInstanceAsInt64(0).empty());

  REQUIRE(propertyView.getInstanceAsFloat(0).empty());
  REQUIRE(propertyView.getInstanceAsDouble(0).empty());
}

TEST_CASE("Create Uint16 Vec3") {
  std::vector<uint16_t> data{2100, 32, 1222, 40, 51, 230, 62, 70, 120};
  CesiumMetadata::TileFormatArrayPropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(uint16_t)),
      CesiumMetadata::TileFormatType::Vec3,
      CesiumMetadata::TileFormatComponentType::UnsignedShort,
      data.size() / 3);

  size_t numOfInstances = propertyView.numOfInstances();
  REQUIRE(numOfInstances == 3);
  for (size_t i = 0; i < numOfInstances; ++i) {
    auto values = propertyView.getInstanceAsUint16(i);
    REQUIRE(values[0] == data[i * 3]);
    REQUIRE(values[1] == data[i * 3 + 1]);
    REQUIRE(values[2] == data[i * 3 + 2]);
  }

  REQUIRE(propertyView.getInstanceAsUint8(0).empty());
  REQUIRE(propertyView.getInstanceAsInt8(0).empty());

  REQUIRE(propertyView.getInstanceAsInt16(0).empty());

  REQUIRE(propertyView.getInstanceAsUint32(0).empty());
  REQUIRE(propertyView.getInstanceAsInt32(0).empty());

  REQUIRE(propertyView.getInstanceAsUint64(0).empty());
  REQUIRE(propertyView.getInstanceAsInt64(0).empty());

  REQUIRE(propertyView.getInstanceAsFloat(0).empty());
  REQUIRE(propertyView.getInstanceAsDouble(0).empty());
}

TEST_CASE("Create Int16 Vec3") {
  std::vector<int16_t> data{2100, -32, -1222, -40, 51, 230, 62, 70, 120};
  CesiumMetadata::TileFormatArrayPropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(int16_t)),
      CesiumMetadata::TileFormatType::Vec3,
      CesiumMetadata::TileFormatComponentType::Short,
      data.size() / 3);

  size_t numOfInstances = propertyView.numOfInstances();
  REQUIRE(numOfInstances == 3);
  for (size_t i = 0; i < numOfInstances; ++i) {
    auto values = propertyView.getInstanceAsInt16(i);
    REQUIRE(values[0] == data[i * 3]);
    REQUIRE(values[1] == data[i * 3 + 1]);
    REQUIRE(values[2] == data[i * 3 + 2]);
  }

  REQUIRE(propertyView.getInstanceAsUint8(0).empty());
  REQUIRE(propertyView.getInstanceAsInt8(0).empty());

  REQUIRE(propertyView.getInstanceAsUint16(0).empty());

  REQUIRE(propertyView.getInstanceAsUint32(0).empty());
  REQUIRE(propertyView.getInstanceAsInt32(0).empty());

  REQUIRE(propertyView.getInstanceAsUint64(0).empty());
  REQUIRE(propertyView.getInstanceAsInt64(0).empty());

  REQUIRE(propertyView.getInstanceAsFloat(0).empty());
  REQUIRE(propertyView.getInstanceAsDouble(0).empty());
}

TEST_CASE("Create Uint32 Vec3") {
  std::vector<uint32_t> data{2100, 11132, 122200, 2240, 51, 230, 62, 70, 120};
  CesiumMetadata::TileFormatArrayPropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(uint32_t)),
      CesiumMetadata::TileFormatType::Vec3,
      CesiumMetadata::TileFormatComponentType::UnsignedInt,
      data.size() / 3);

  size_t numOfInstances = propertyView.numOfInstances();
  REQUIRE(numOfInstances == 3);
  for (size_t i = 0; i < numOfInstances; ++i) {
    auto values = propertyView.getInstanceAsUint32(i);
    REQUIRE(values[0] == data[i * 3]);
    REQUIRE(values[1] == data[i * 3 + 1]);
    REQUIRE(values[2] == data[i * 3 + 2]);
  }

  REQUIRE(propertyView.getInstanceAsUint8(0).empty());
  REQUIRE(propertyView.getInstanceAsInt8(0).empty());

  REQUIRE(propertyView.getInstanceAsUint16(0).empty());
  REQUIRE(propertyView.getInstanceAsInt16(0).empty());

  REQUIRE(propertyView.getInstanceAsInt32(0).empty());

  REQUIRE(propertyView.getInstanceAsUint64(0).empty());
  REQUIRE(propertyView.getInstanceAsInt64(0).empty());

  REQUIRE(propertyView.getInstanceAsFloat(0).empty());
  REQUIRE(propertyView.getInstanceAsDouble(0).empty());
}

TEST_CASE("Create Int32 Vec3") {
  std::vector<int32_t> data{-2100, 11132, -122200, -2240, 51, 230, 62, 70, 120};
  CesiumMetadata::TileFormatArrayPropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(int32_t)),
      CesiumMetadata::TileFormatType::Vec3,
      CesiumMetadata::TileFormatComponentType::Int,
      data.size() / 3);

  size_t numOfInstances = propertyView.numOfInstances();
  REQUIRE(numOfInstances == 3);
  for (size_t i = 0; i < numOfInstances; ++i) {
    auto values = propertyView.getInstanceAsInt32(i);
    REQUIRE(values[0] == data[i * 3]);
    REQUIRE(values[1] == data[i * 3 + 1]);
    REQUIRE(values[2] == data[i * 3 + 2]);
  }

  REQUIRE(propertyView.getInstanceAsUint8(0).empty());
  REQUIRE(propertyView.getInstanceAsInt8(0).empty());

  REQUIRE(propertyView.getInstanceAsUint16(0).empty());
  REQUIRE(propertyView.getInstanceAsInt16(0).empty());

  REQUIRE(propertyView.getInstanceAsUint32(0).empty());

  REQUIRE(propertyView.getInstanceAsUint64(0).empty());
  REQUIRE(propertyView.getInstanceAsInt64(0).empty());

  REQUIRE(propertyView.getInstanceAsFloat(0).empty());
  REQUIRE(propertyView.getInstanceAsDouble(0).empty());
}

TEST_CASE("Create Float Vec3") {
  std::vector<float> data{
      -2100.0f,
      111.32f,
      -12.2200f,
      -2.240f,
      5.1f,
      0.230f,
      6.2f,
      0.70f,
      0.120f};
  CesiumMetadata::TileFormatArrayPropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(float)),
      CesiumMetadata::TileFormatType::Vec3,
      CesiumMetadata::TileFormatComponentType::Float,
      data.size() / 3);

  size_t numOfInstances = propertyView.numOfInstances();
  REQUIRE(numOfInstances == 3);
  for (size_t i = 0; i < numOfInstances; ++i) {
    auto values = propertyView.getInstanceAsFloat(i);
    REQUIRE(values[0] == data[i * 3]);
    REQUIRE(values[1] == data[i * 3 + 1]);
    REQUIRE(values[2] == data[i * 3 + 2]);
  }

  REQUIRE(propertyView.getInstanceAsUint8(0).empty());
  REQUIRE(propertyView.getInstanceAsInt8(0).empty());

  REQUIRE(propertyView.getInstanceAsUint16(0).empty());
  REQUIRE(propertyView.getInstanceAsInt16(0).empty());

  REQUIRE(propertyView.getInstanceAsUint32(0).empty());
  REQUIRE(propertyView.getInstanceAsInt32(0).empty());

  REQUIRE(propertyView.getInstanceAsUint64(0).empty());
  REQUIRE(propertyView.getInstanceAsInt64(0).empty());

  REQUIRE(propertyView.getInstanceAsDouble(0).empty());
}

TEST_CASE("Create Double Vec3") {
  std::vector<double>
      data{-2100.2, 111.32, 12.2200, -2.240, 5.1, 0.230, 6.2, 0.70, 0.120};
  CesiumMetadata::TileFormatArrayPropertyView propertyView(
      gsl::span<std::byte>(
          reinterpret_cast<std::byte*>(data.data()),
          data.size() * sizeof(float)),
      CesiumMetadata::TileFormatType::Vec3,
      CesiumMetadata::TileFormatComponentType::Double,
      data.size() / 3);

  size_t numOfInstances = propertyView.numOfInstances();
  REQUIRE(numOfInstances == 3);
  for (size_t i = 0; i < numOfInstances; ++i) {
    auto values = propertyView.getInstanceAsDouble(i);
    REQUIRE(values[0] == data[i * 3]);
    REQUIRE(values[1] == data[i * 3 + 1]);
    REQUIRE(values[2] == data[i * 3 + 2]);
  }

  REQUIRE(propertyView.getInstanceAsUint8(0).empty());
  REQUIRE(propertyView.getInstanceAsInt8(0).empty());

  REQUIRE(propertyView.getInstanceAsUint16(0).empty());
  REQUIRE(propertyView.getInstanceAsInt16(0).empty());

  REQUIRE(propertyView.getInstanceAsUint32(0).empty());
  REQUIRE(propertyView.getInstanceAsInt32(0).empty());

  REQUIRE(propertyView.getInstanceAsUint64(0).empty());
  REQUIRE(propertyView.getInstanceAsInt64(0).empty());

  REQUIRE(propertyView.getInstanceAsFloat(0).empty());
}
