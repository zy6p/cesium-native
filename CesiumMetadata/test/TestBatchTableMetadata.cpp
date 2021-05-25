#include "CesiumMetadata/ArrayPropertyView.h"
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
      std::filesystem::path(CesiumMetadata_TEST_DATA_DIR) / "Batchtable" /
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

TEST_CASE(
    "Parse batch table with nested string and object array json property") {
  std::filesystem::path batchedWithBinFile =
      std::filesystem::path(CesiumMetadata_TEST_DATA_DIR) / "Batchtable" /
      "batchedWithBatchTable.b3dm";
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
        6.155801922082901,
        13.410263679921627,
        6.1022464875131845,
        6.742499912157655,
        6.869888566434383,
        10.701326800510287,
        6.163868889212608,
        12.224825594574213,
        12.546202838420868,
        7.632075032219291};
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
        0.698874,
        0.6988615321420496,
        0.6988736012180136,
        0.6988863062831799,
        0.6988864387845588,
        0.6988814788613282,
        0.6988618972526105,
        0.6988590050687061,
        0.6988690935212543,
        0.6988854945986224};
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
        -1.31968,
        -1.3196832683949145,
        -1.3196637662080655,
        -1.3196656317210846,
        -1.319679266890895,
        -1.319693717777418,
        -1.3196607462778132,
        -1.3196940116311096,
        -1.319683648959897,
        -1.3196959060375169};
    size_t i = 0;
    for (const auto& value : longitudeJson->asJsons()) {
      REQUIRE(value.isDouble());
      REQUIRE(value.getDouble() == Approx(expected[i]));
      ++i;
    }
    REQUIRE(i == expected.size());
  }

  // test info property
  {
    auto info = metadata->getProperty("info");
    REQUIRE(info != nullptr);

    auto infoJson = info->asJsonPropertyView();
    REQUIRE(infoJson != nullptr);

    auto values = infoJson->asJsons();
    REQUIRE(values.size() == batchLength);
    size_t i = 0;
    for (const auto& v : values) {
      REQUIRE(v.isObject());
      const auto& object = v.getObject();
      REQUIRE(
          object.at("name").getString() == ("building" + std::to_string(i)));
      REQUIRE(object.at("year").getUint64() == i);
      ++i;
    }
  }

  // test room array of array
  {
    auto rooms = metadata->getProperty("rooms");
    REQUIRE(rooms != nullptr);

    auto roomJson = rooms->asJsonPropertyView();
    REQUIRE(roomJson != nullptr);

    auto values = roomJson->asJsons();
    REQUIRE(values.size() == batchLength);
    size_t i = 0;
    for (const auto& v : values) {
      REQUIRE(v.isArray());
      const auto& vector = v.getArray();
      REQUIRE(vector.size() == 3);
      REQUIRE(vector[0].getString() == ("room" + std::to_string(i) + "_a"));
      REQUIRE(vector[1].getString() == ("room" + std::to_string(i) + "_b"));
      REQUIRE(vector[2].getString() == ("room" + std::to_string(i) + "_c"));
      ++i;
    }
  }
}

TEST_CASE("Parse binary batch table") {
  std::filesystem::path batchedWithBinFile =
      std::filesystem::path(CesiumMetadata_TEST_DATA_DIR) / "Batchtable" /
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
    REQUIRE(cartographic != nullptr);

    auto cartographicArray = cartographic->asArrayPropertyView();
    REQUIRE(cartographicArray != nullptr);

    auto size = cartographicArray->numOfInstances();
    REQUIRE(size == batchLength);

    // clang-format off
    std::vector<double> expected{ 
        -1.31968, 0.698874, 6.155801922082901,
        -1.3196832683949145, 0.6988615321420496, 13.410263679921627,
        -1.3196637662080655, 0.6988736012180136, 6.1022464875131845,
        -1.3196656317210846, 0.6988863062831799, 6.742499912157655,
        -1.319679266890895,  0.6988864387845588, 6.869888566434383,
        -1.319693717777418, 0.6988814788613282, 10.701326800510287,
        -1.3196607462778132, 0.6988618972526105, 6.163868889212608,
        -1.3196940116311096, 0.6988590050687061, 12.224825594574213,
        -1.319683648959897, 0.6988690935212543, 12.546202838420868,
        -1.3196959060375169, 0.6988854945986224, 7.632075032219291
    };
    // clang-format on

    for (size_t i = 0; i < size; ++i) {
      gsl::span<const double> values =
          cartographicArray->getInstanceAsDouble(i);
      REQUIRE(values.size() == 3);
      REQUIRE(values[0] == Approx(expected[i * 3]));
      REQUIRE(values[1] == Approx(expected[i * 3 + 1]));
      REQUIRE(values[2] == Approx(expected[i * 3 + 2]));
    }
  }
}
