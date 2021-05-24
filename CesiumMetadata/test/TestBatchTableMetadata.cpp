#include "CesiumMetadata/BatchTableMetadata.h"
#include "CesiumMetadata/JsonPropertyView.h"
#include "CesiumMetadata/PrimitivePropertyView.h"
#include "CesiumMetadata/PropertyView.h"
#include "catch2/catch.hpp"
#include <filesystem>
#include <fstream>
#include <rapidjson/document.h>

namespace {
struct B3dmHeader {
  unsigned char magic[4];
  uint32_t version;
  uint32_t byteLength;
  uint32_t featureTableJsonByteLength;
  uint32_t featureTableBinaryByteLength;
  uint32_t batchTableJsonByteLength;
  uint32_t batchTableBinaryByteLength;
};

std::vector<std::byte> readFile(const std::filesystem::path& fileName) {
  std::ifstream file(fileName, std::ios::binary | std::ios::ate);

  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);

  std::vector<std::byte> buffer(static_cast<size_t>(size));
  file.read(reinterpret_cast<char*>(buffer.data()), size);

  return buffer;
}

void parseB3dm(
    std::vector<std::byte>& content,
    int& batchLength,
    gsl::span<std::byte>& featureTableJsonData,
    gsl::span<std::byte>& batchTableJsonData,
    gsl::span<std::byte>& batchTableBinData) {
  const B3dmHeader* header =
      reinterpret_cast<const B3dmHeader*>(content.data());

  size_t offset = sizeof(B3dmHeader);
  featureTableJsonData = gsl::span<std::byte>(
      content.data() + offset,
      header->featureTableJsonByteLength);

  offset +=
      header->featureTableJsonByteLength + header->featureTableBinaryByteLength;
  batchTableJsonData = gsl::span<std::byte>(
      content.data() + offset,
      header->batchTableJsonByteLength);

  offset += header->batchTableJsonByteLength;
  batchTableBinData = gsl::span<std::byte>(
      content.data() + offset,
      header->batchTableBinaryByteLength);

  // find batch length
  rapidjson::Document featureTableJson;
  featureTableJson.Parse(
      reinterpret_cast<const char*>(featureTableJsonData.data()),
      featureTableJsonData.size());
  const auto& object = featureTableJson.GetObject();
  batchLength = object["BATCH_LENGTH"].GetInt();
}
} // namespace

TEST_CASE("Parse Json metadata from batch table") {
  std::filesystem::path batchedWithJsonFile =
      std::filesystem::path(CesiumMetadata_TEST_DATA_DIR) / "B3dm" /
      "batchedWithJson.b3dm";
  std::vector<std::byte> content = readFile(batchedWithJsonFile);

  int batchLength;
  gsl::span<std::byte> featureTableJsonData;
  gsl::span<std::byte> batchTableJsonData;
  gsl::span<std::byte> batchTableBinaryData;
  parseB3dm(
      content,
      batchLength,
      featureTableJsonData,
      batchTableJsonData,
      batchTableBinaryData);

  // parse batch table
  auto metadata = CesiumMetadata::BatchTableMetadata::create(
      batchLength,
      batchTableJsonData,
      batchTableBinaryData);
  REQUIRE(metadata != nullptr);

  // check ID property
  {
    auto id = metadata->getProperty("id");
    REQUIRE(id != nullptr);

    auto idJson = id->asJsonPropertyView();
    REQUIRE(idJson != nullptr);

    uint64_t expectedValue = 0;
    for (const auto& value : idJson->asJsons()) {
      REQUIRE(value.isUint64());
      REQUIRE(value.getUint64() == expectedValue);
      ++expectedValue;
    }

    REQUIRE(expectedValue == batchLength);
  }

  // check height
  {
    auto height = metadata->getProperty("Height");
    REQUIRE(height != nullptr);

    auto heightJson = height->asJsonPropertyView();
    REQUIRE(heightJson != nullptr);

    std::vector<double> expected = {
        11.762595914304256,
        13.992324123159051,
        7.490081690251827,
        13.484312580898404,
        11.481756005436182,
        7.836617760360241,
        9.338438434526324,
        13.513022359460592,
        13.74609257467091,
        10.145220385864377};
    size_t i = 0;
    for (const auto& value : heightJson->asJsons()) {
      REQUIRE(value.isDouble());
      REQUIRE(value.getDouble() == Approx(expected[i]));
      ++i;
    }
    REQUIRE(i == expected.size());
  }

  // check latitude
  {
    auto latitude = metadata->getProperty("Latitude");
    REQUIRE(latitude != nullptr);

    auto latitudeJson = latitude->asJsonPropertyView();
    REQUIRE(latitudeJson != nullptr);

    std::vector<double> expected = {
        0.6988582109,
        0.6988498770649103,
        0.6988533339856887,
        0.6988691467754378,
        0.698848878034009,
        0.6988592976292447,
        0.6988600642191055,
        0.6988670019309562,
        0.6988523191715889,
        0.6988697375823105};
    size_t i = 0;
    for (const auto& value : latitudeJson->asJsons()) {
      REQUIRE(value.isDouble());
      REQUIRE(value.getDouble() == Approx(expected[i]));
      ++i;
    }
    REQUIRE(i == expected.size());
  }

  // check longitude
  {
    auto longitude = metadata->getProperty("Longitude");
    REQUIRE(longitude != nullptr);

    auto longitudeJson = longitude->asJsonPropertyView();
    REQUIRE(longitudeJson != nullptr);

    std::vector<double> expected = {
        -1.3196595204101946,
        -1.3196739888070643,
        -1.3196641114334025,
        -1.3196579305297966,
        -1.3196585149509301,
        -1.319678877969692,
        -1.3196612732428445,
        -1.3196718857616954,
        -1.3196471198757775,
        -1.319644104024109};
    size_t i = 0;
    for (const auto& value : longitudeJson->asJsons()) {
      REQUIRE(value.isDouble());
      REQUIRE(value.getDouble() == Approx(expected[i]));
      ++i;
    }
    REQUIRE(i == expected.size());
  }
}

TEST_CASE("Parse binary batch table") {
  std::filesystem::path batchedWithBinFile =
      std::filesystem::path(CesiumMetadata_TEST_DATA_DIR) / "B3dm" /
      "batchedWithBatchTableBinary.b3dm";
  std::vector<std::byte> content = readFile(batchedWithBinFile);

  int batchLength;
  gsl::span<std::byte> featureTableJsonData;
  gsl::span<std::byte> batchTableJsonData;
  gsl::span<std::byte> batchTableBinaryData;
  parseB3dm(
      content,
      batchLength,
      featureTableJsonData,
      batchTableJsonData,
      batchTableBinaryData);

  // parse batch table
  auto metadata = CesiumMetadata::BatchTableMetadata::create(
      batchLength,
      batchTableJsonData,
      batchTableBinaryData);
  REQUIRE(metadata != nullptr);

  // test binary unsigned byte code
  {
    auto code = metadata->getProperty("code");
    REQUIRE(code != nullptr);

    auto codePrimitive = code->asPrimitivePropertyView();
    REQUIRE(codePrimitive != nullptr);

    auto codeValues = codePrimitive->asUint8();
    REQUIRE(codeValues.size() == batchLength);

    for (auto value : codeValues) {
      REQUIRE(value == 255);
    }
  }

  // test binary vec3 cartographic
  {
    auto cartographic = metadata->getProperty("cartographic");
    REQUIRE(cartographic == nullptr);
  }
}
